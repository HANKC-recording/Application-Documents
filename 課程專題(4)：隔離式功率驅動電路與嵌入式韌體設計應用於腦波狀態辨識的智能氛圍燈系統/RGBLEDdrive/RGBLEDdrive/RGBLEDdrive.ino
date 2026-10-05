/*
 * ESP32_Driver.ino
 * 接收 PC 端傳送的四個參數，控制 RGB LED
 * 
 * 接收格式: "state,R,G,B\n"
 * state: 0=放鬆, 1=專注, 2=眨眼 (只用於觸發換檔)
 * R: 放鬆機率 (0-1) - 決定紅色亮度
 * B: 專注機率 (0-1) - 決定藍色亮度
 * B: 不使用 (綠色完全不輸出)
 * 
 * 檔位控制整體亮度: 1=25%, 2=50%, 3=75%, 4=100%
 * 紅色亮度 = R × 檔位亮度
 * 藍色亮度 = B × 檔位亮度
 * 綠色 = 0 (完全不亮)
 * 
 * 眨眼時：沿用上一次的放鬆/專注比例（不更新 R/G），只觸發換檔
 * 連續眨眼不加檔，只有非眨眼→眨眼才加檔
 */

#include <math.h>

// ===================== 可調參數區 =====================
const int   PIN_R            = 4;      // R 腳位 (紅色 - 放鬆)
const int   PIN_G            = 5;      // G 腳位 (綠色 - 不使用，設為 0)
const int   PIN_B            = 6;      // B 腳位 (藍色 - 專注)
const int   PIN_SIGNAL       = 0;      // 實體按鈕腳位

const int   PWM_FREQ         = 2000;   // PWM 頻率 Hz
const int   PWM_RES          = 10;     // PWM 解析度 bit
const int   MAX_PWM          = 1023;   // 最大 PWM 值 (2^10 - 1)

const int   POLL_INTERVAL_MS = 2000;   // 輪詢間隔 ms（PC 每 2 秒發送一次）

// 燈光週期參數
const float FADE_IN_SEC      = 0.5;    // 緩啟動時間（秒）
const float STABLE_SEC       = 1.0;    // 穩定維持時間（秒）
const float FADE_OUT_SEC     = 0.5;    // 緩關閉時間（秒）

const int   FADE_STEPS       = 20;     // 漸變步數

// 檔位參數
const int MAX_GEAR = 4;
const unsigned long GEAR_COOLDOWN_MS = 500;  // 換檔冷卻 0.5 秒
// ======================================================

int current_gear = 1;

// 接收的變數
float R_ratio = 0.33;   // 放鬆機率 (控制紅色)
float B_ratio = 0.33;   // 專注機率 (控制藍色)

// 上一次非眨眼時的 R/G 值（用於眨眼時沿用）
float last_R_ratio = 0.33;
float last_B_ratio = 0.33;

int current_state = -1;     // 0=放鬆, 1=專注, 2=眨眼 (只用於換檔判斷)

// 眨眼狀態追蹤
int last_received_state = -1;

unsigned long lastGearChangeTime = 0;
unsigned long lastPollTime = 0;
unsigned long step_start_time = 0;
bool is_in_cycle = false;
int cycle_step = 0;

bool lastSignalState = HIGH;

// ────────── 函式宣告 ──────────
void writeRGB(float gear_frac);
void printStatus(const char* stage);
void runCycle();
void parseCommand();

// ──────────────────────────────────────────────
void setup() {
  Serial.begin(115200);
  pinMode(PIN_SIGNAL, INPUT_PULLUP);

  ledcAttach(PIN_R, PWM_FREQ, PWM_RES);
  ledcAttach(PIN_G, PWM_FREQ, PWM_RES);
  ledcAttach(PIN_B, PWM_FREQ, PWM_RES);

  ledcWrite(PIN_R, MAX_PWM);
  ledcWrite(PIN_G, MAX_PWM);
  ledcWrite(PIN_B, MAX_PWM);

  unsigned long now = millis();
  lastGearChangeTime = now;
  lastPollTime = now;

  Serial.println(F("========================================"));
  Serial.println(F("[就緒] 腦波驅動 RGB LED (紅+藍模式)"));
  Serial.print(F("[參數] 輪詢間隔="));    Serial.print(POLL_INTERVAL_MS);  Serial.println(F("ms"));
  Serial.print(F("[參數] 緩啟動="));      Serial.print(FADE_IN_SEC);       Serial.println(F("s"));
  Serial.print(F("[參數] 穩定="));        Serial.print(STABLE_SEC);        Serial.println(F("s"));
  Serial.print(F("[參數] 緩關閉="));      Serial.print(FADE_OUT_SEC);      Serial.println(F("s"));
  Serial.println(F("========================================"));
  Serial.println(F("[等待] 接收格式: state,R,G,B"));
  Serial.println(F("  R: 紅色亮度 (放鬆)"));
  Serial.println(F("  G: 藍色亮度 (專注)"));
  Serial.println(F("  state: 0=放鬆, 1=專注, 2=眨眼 (用於換檔，沿用上次比例)"));
  Serial.println(F("========================================"));

  runCycle();
}

// ──────────────────────────────────────────────
void loop() {
  unsigned long now = millis();

  // ── 處理燈光週期 (非阻塞) ──
  if (is_in_cycle) {
    unsigned long elapsed = now - step_start_time;
    
    if (cycle_step == 0) {  // 緩啟動階段
      int step_duration = (int)(FADE_IN_SEC * 1000 / FADE_STEPS);
      int step_index = elapsed / step_duration;
      if (step_index >= FADE_STEPS) {
        cycle_step = 1;
        step_start_time = now;
        writeRGB(1.0);
        Serial.println(F("[週期] 進入穩定階段"));
      } else {
        float t = (float)(step_index + 1) / FADE_STEPS;
        writeRGB(t);
      }
    } 
    else if (cycle_step == 1) {  // 穩定階段
      if (elapsed >= (unsigned long)(STABLE_SEC * 1000)) {
        cycle_step = 2;
        step_start_time = now;
        Serial.println(F("[週期] 進入緩關閉階段"));
      }
    } 
    else if (cycle_step == 2) {  // 緩關閉階段
      int step_duration = (int)(FADE_OUT_SEC * 1000 / FADE_STEPS);
      int step_index = elapsed / step_duration;
      if (step_index >= FADE_STEPS) {
        is_in_cycle = false;
        // ledcWrite(PIN_R, MAX_PWM);
        // ledcWrite(PIN_G, MAX_PWM);
        // ledcWrite(PIN_B, MAX_PWM);
        Serial.println(F("[週期] 週期結束，燈光熄滅"));
      } else {
        float t = 1.0 - (float)(step_index + 1) / FADE_STEPS;
        writeRGB(t);
      }
    }
  }

  // ── 實體按鈕換檔 (手動增加檔位) ──
  bool currentSignalState = digitalRead(PIN_SIGNAL);
  if (lastSignalState == HIGH && currentSignalState == LOW) {
    delay(30);
    if (digitalRead(PIN_SIGNAL) == LOW) {
      unsigned long nowBtn = millis();
      if ((nowBtn - lastGearChangeTime) >= GEAR_COOLDOWN_MS) {
        int new_gear = current_gear + 1;
        if (new_gear > MAX_GEAR) new_gear = 1;
        Serial.print(F("[按鈕] 換檔: "));
        Serial.print(current_gear); Serial.print(F(" → ")); Serial.println(new_gear);
        current_gear = new_gear;
        lastGearChangeTime = nowBtn;
        runCycle();
      } else {
        unsigned long remain = GEAR_COOLDOWN_MS - (nowBtn - lastGearChangeTime);
        Serial.print(F("[按鈕] 冷卻中，剩餘 "));
        Serial.print(remain); Serial.println(F("ms"));
      }
    }
  }
  lastSignalState = currentSignalState;

  // ── 輪詢 Serial ──
  if ((now - lastPollTime) >= (unsigned long)POLL_INTERVAL_MS) {
    lastPollTime = now;
    if (Serial.available() > 0) {
      parseCommand();
    }
  }
}

// ──────────────────────────────────────────────
// 解析 PC 指令
// 格式: state,R,G,B
// ──────────────────────────────────────────────
void parseCommand() {
  String line = Serial.readStringUntil('\n');
  line.trim();
  if (line.length() == 0) return;

  Serial.print(F("[收到] ")); Serial.println(line);

  int comma1 = line.indexOf(',');
  int comma2 = line.indexOf(',', comma1 + 1);
  int comma3 = line.indexOf(',', comma2 + 1);
  
  if (comma1 == -1 || comma2 == -1 || comma3 == -1) {
    Serial.println(F("[錯誤] 格式錯誤，應為 state,R,G,B"));
    return;
  }

  int state = line.substring(0, comma1).toInt();
  float temp_R = line.substring(comma1 + 1, comma2).toFloat();
  float temp_B = line.substring(comma2 + 1, comma3).toFloat();
  // float temp_B = line.substring(comma3 + 1).toFloat(); // 不使用

  // ========== 核心邏輯 ==========
  // 如果是眨眼 (state == 2)：沿用上一次的 R/G 比例，只觸發換檔
  // 如果不是眨眼：更新 R/G 比例
  unsigned long now = millis();
  bool should_change_gear = false;

  if (state == 2) {
    // 眨眼：沿用上一次的比例（不更新 R_ratio, B_ratio）
    // 只檢查是否要換檔
    if (last_received_state != 2) {
      should_change_gear = true;
      Serial.println(F("[眨眼] 有效眨眼！換檔 (沿用上次比例)"));
    } else {
      Serial.println(F("[眨眼] 連續眨眼，忽略"));
    }
  } else {
    // 非眨眼：更新 R/G 比例
    R_ratio = temp_R;
    B_ratio = temp_B;
    // 儲存為上次非眨眼的值（供下次眨眼時沿用）
    last_R_ratio = R_ratio;
    last_B_ratio = B_ratio;
    Serial.println(F("[狀態] 更新放鬆/專注比例"));
  }

  // 更新狀態記錄
  last_received_state = state;
  current_state = state;

  // 執行換檔
  if (should_change_gear) {
    if ((now - lastGearChangeTime) >= GEAR_COOLDOWN_MS) {
      int new_gear = current_gear + 1;
      if (new_gear > MAX_GEAR) new_gear = 1;
      Serial.print(F("[眨眼換檔] "));
      Serial.print(current_gear); Serial.print(F(" → ")); Serial.println(new_gear);
      current_gear = new_gear;
      lastGearChangeTime = now;
      runCycle();
    } else {
      unsigned long remain = GEAR_COOLDOWN_MS - (now - lastGearChangeTime);
      Serial.print(F("[眨眼換檔] 冷卻中，剩餘 "));
      Serial.print(remain); Serial.println(F("ms"));
    }
  } else {
    runCycle();
  }

  // 輸出調試資訊（顯示當前使用的 R/G 值）
  Serial.print(F("[套用] 紅色(放鬆)=")); Serial.print(R_ratio, 3);
  Serial.print(F(" 藍色(專注)="));       Serial.print(B_ratio, 3);
  Serial.print(F(" 檔位="));            Serial.print(current_gear);
  Serial.print(F(" (亮度="));           Serial.print(current_gear * 25);
  Serial.println(F("%)"));
}

// ──────────────────────────────────────────────
void runCycle() {
  is_in_cycle = true;
  cycle_step = 0;
  step_start_time = millis();
  
  Serial.println(F("[週期] 開始新週期"));
  Serial.print(F(" 目標亮度="));
  Serial.print(current_gear * 25);
  Serial.println(F("%"));
}

// ──────────────────────────────────────────────
// 寫入 PWM
// 只輸出紅色和藍色，綠色完全不亮
// ──────────────────────────────────────────────
void writeRGB(float gear_frac) {
  // 整體亮度百分比 (檔位 1=25%, 2=50%, 3=75%, 4=100%)
  float gear_percent = current_gear * 25.0f * gear_frac;
  
  // 紅色 = 放鬆機率 × 檔位亮度
  int gate_R = (int)((R_ratio * gear_percent / 100.0f) * MAX_PWM);
  
  // 藍色 = 專注機率 × 檔位亮度
  int gate_B = (int)((B_ratio * gear_percent / 100.0f) * MAX_PWM);
  
  // 綠色 = 完全不亮
  int gate_G = 0;

  // 限制 PWM 值範圍
  gate_R = constrain(gate_R, 0, MAX_PWM);
  gate_G = constrain(gate_G, 0, MAX_PWM);
  gate_B = constrain(gate_B, 0, MAX_PWM);

  // Common Anode：反向輸出 (高電位 = 熄滅)
  ledcWrite(PIN_R, MAX_PWM - gate_R);
  ledcWrite(PIN_G, MAX_PWM - gate_G);
  ledcWrite(PIN_B, MAX_PWM - gate_B);
}

// ──────────────────────────────────────────────
void printStatus(const char* stage) {
  Serial.println(F("========================================"));
  Serial.print(stage);
  Serial.print(F(" 檔位="));   Serial.print(current_gear);
  Serial.print(F(" 亮度="));   Serial.print(current_gear * 25); Serial.println(F("%"));
  Serial.print(F(" 紅色(放鬆)=")); Serial.print(R_ratio, 3);
  Serial.print(F(" 藍色(專注)=")); Serial.print(B_ratio, 3);
  Serial.println(F(" (綠色=0)"));
  Serial.println(F("========================================"));
}
