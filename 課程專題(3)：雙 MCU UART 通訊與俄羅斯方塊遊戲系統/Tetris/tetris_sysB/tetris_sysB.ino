/*
 * Board B: Simple Timer (PC Control Only)
 * 功能: 透過電腦 Serial Monitor 輸入 s 開始計時
 * 接線:
 * - 位數: A0, A1, A2, A3
 * - 筆畫: 2, 3, 4, 5, 6, 7, 8
 */

#include <SevSeg.h>

SevSeg sevseg;

// ★★★ 極性設定 ★★★
// 如果顯示全亮或亂碼，請改為 COMMON_CATHODE (共陰)
#define DISPLAY_TYPE COMMON_ANODE 

// 計時變數
unsigned long startTime = 0;
unsigned long elapsedTime = 0; // 經過的時間 (毫秒)
bool isRunning = false;        // 是否正在跑

void setup() {
  Serial.begin(9600); // 啟動電腦通訊
  
  byte numDigits = 4;
  byte digitPins[] = {A0, A1, A2, A3};
  // 避開 Pin 12，使用 2-8
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; 
  
  bool resistorsOnSegments = true;
  bool updateWithDelays = false;
  bool leadingZeros = true; 
  bool disableDecPoint = true; 

  sevseg.begin(DISPLAY_TYPE, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);

  Serial.println(F("System Ready."));
  Serial.println(F("Type 's' to Start, 'p' to Pause, 'r' to Reset"));
}

void loop() {
  // 1. 顯示器刷新 (最優先，無時無刻都要跑)
  sevseg.refreshDisplay();

  // 2. 檢查電腦有沒有輸入指令
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    
    // 忽略換行符號
    if (cmd == '\n' || cmd == '\r') return;

    if (cmd == 's' || cmd == 'S') { 
      // [Start] 開始計時
      if (!isRunning) {
        // 邏輯：當前時間 - 已經累積的時間 = 新的起跑點
        startTime = millis() - elapsedTime;
        isRunning = true;
        Serial.println(F("Timer Started!"));
      }
    } 
    else if (cmd == 'p' || cmd == 'P') { 
      // [Pause] 暫停
      isRunning = false;
      Serial.print(F("Paused at: "));
      Serial.println(elapsedTime / 1000);
    } 
    else if (cmd == 'r' || cmd == 'R') { 
      // [Reset] 歸零
      isRunning = false;
      elapsedTime = 0;
      sevseg.setNumber(0, 2);
      Serial.println(F("Timer Reset."));
    }
  }

  // 3. 計時邏輯
  if (isRunning) {
    elapsedTime = millis() - startTime;
    
    // 轉換成 秒數
    unsigned long totalSeconds = elapsedTime / 1000;
    
    // 顯示在七段顯示器上 (純秒數 0-9999)
    sevseg.setNumber(totalSeconds);
  } else if (elapsedTime > 0) {
    // 暫停狀態，持續顯示最後的時間
    sevseg.setNumber(elapsedTime / 1000);
  } else {
    // 歸零狀態
    sevseg.setNumber(0);
  }
}