/*
 * Board A: Tetris Interface Master
 * 接線:
 * - LCD (I2C): SDA->A4, SCL->A5
 * - 搖桿: X->A0, Y->A1, Btn->2
 * - 矩陣: DIN->12, CLK->11, CS->10
 * - 蜂鳴器: Pin 3
 * - 通訊: 0(RX), 1(TX) -> 交叉接 Board B
 */

#include <LedControl.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// ★★★ 蜂鳴器 ★★★
#define BUZZER_PIN 3 

// LCD 設定 (若沒畫面請改 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  

// MAX7219 設定
LedControl lc = LedControl(12, 11, 10, 1);

// 搖桿
const int joyX = A0;
const int joyY = A1;
const int joyBtn = 2;

// --- 紀錄變數 ---
unsigned long highScore = 0;      // 歷史最高分
unsigned long highScoreTime = 0;  // 創下最高分時的時間 (秒)
unsigned long currentScore = 0;   // 目前分數

// 遊戲變數
byte displayBuffer[8];
byte gameBoard[8];
int currentX = 2, currentY = -1, currentType = 0, currentRotation = 0;
unsigned long lastMoveTime = 0;
int dropSpeed = 500;

enum GameState { WAIT_START, PLAYING, GAME_OVER };
GameState currentState = WAIT_START;

// Tetris 形狀
const byte shapes[7][4][4] = {
  { { B0000, B1111, B0000, B0000 }, { B0010, B0010, B0010, B0010 }, { B0000, B1111, B0000, B0000 }, { B0010, B0010, B0010, B0010 } },
  { { B1000, B1110, B0000, B0000 }, { B0110, B0100, B0100, B0000 }, { B0000, B1110, B0010, B0000 }, { B0100, B0100, B1100, B0000 } },
  { { B0010, B1110, B0000, B0000 }, { B0100, B0100, B0110, B0000 }, { B0000, B1110, B1000, B0000 }, { B1100, B0100, B0100, B0000 } },
  { { B0110, B0110, B0000, B0000 }, { B0110, B0110, B0000, B0000 }, { B0110, B0110, B0000, B0000 }, { B0110, B0110, B0000, B0000 } },
  { { B0110, B1100, B0000, B0000 }, { B0100, B0110, B0010, B0000 }, { B0110, B1100, B0000, B0000 }, { B0100, B0110, B0010, B0000 } },
  { { B0100, B1110, B0000, B0000 }, { B0100, B0110, B0100, B0000 }, { B0000, B1110, B0100, B0000 }, { B0100, B1100, B0100, B0000 } },
  { { B1100, B0110, B0000, B0000 }, { B0010, B0110, B0100, B0000 }, { B1100, B0110, B0000, B0000 }, { B0010, B0110, B0100, B0000 } }
};

// 前向宣告
void showStandbyScreen();
void startGame();
void playTetrisLogic();
void triggerGameOver();
void refreshScreen();
void handleInput();
void updateDisplayBuffer();
boolean checkCollision(int x, int y, int rot);
void lockBlock();
void clearLines();
void spawnBlock();
void playTone(int freq, int duration);
void soundStart();
void soundClear();
void soundGameOver();
void soundMove();

void setup() {
  Serial.begin(9600);
  
  pinMode(joyBtn, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(A2));

  // 一開機先顯示待機畫面
  showStandbyScreen();
  Serial.println(F("System Ready. Waiting for 's' or Button."));
}

void loop() {
  // 1. 電腦輸入監控
  if (Serial.available()) {
    char c = Serial.read();
    // 輸入 's' 且在待機狀態 -> 開始
    if ((c == 's' || c == 'S') && currentState == WAIT_START) {
      startGame();
    }
  }

  // 2. 按鈕輸入監控
  if (currentState == WAIT_START && digitalRead(joyBtn) == LOW) {
      delay(50);
      if (digitalRead(joyBtn) == LOW) startGame();
  }

  // 3. 狀態機
  switch (currentState) {
    case WAIT_START: 
      // 保持待機畫面，什麼都不做
      break;
    case PLAYING: 
      playTetrisLogic(); 
      break;
    case GAME_OVER:
      // 結束畫面停留 3 秒
      if (millis() - lastMoveTime > 3000) { 
        // 3秒後自動回到待機介面
        showStandbyScreen();
      }
      break;
  }
}

// --- 介面與流程控制 ---

// 顯示待機畫面 (歷史高分 & 時間)
void showStandbyScreen() {
  currentState = WAIT_START;
  
  lcd.clear(); 
  // 第一行：顯示歷史最高分
  lcd.print("HiScore:"); 
  lcd.print(highScore);
  
  // 第二行：顯示創下該紀錄的時間
  lcd.setCursor(0, 1); 
  lcd.print("BestTime:"); 
  lcd.print(highScoreTime); 
  lcd.print("s");
  
  // 傳送 Reset 給 Board B (歸零計時器)
  Serial.print('R');
}

// 開始遊戲
void startGame() {
  currentState = PLAYING;
  memset(gameBoard, 0, sizeof(gameBoard));
  currentScore = 0;
  spawnBlock();
  
  // 切換介面：顯示 最高分 & 目前分數 (時間隱藏)
  lcd.clear();
  lcd.print("High: "); lcd.print(highScore);
  
  lcd.setCursor(0, 1);
  lcd.print("Score: "); lcd.print(currentScore);
  
  // 傳送 Start 給 Board B (開始計時)
  Serial.print('S');
  soundStart(); 
}

// 遊戲結束
void triggerGameOver() {
  currentState = GAME_OVER;
  
  // 傳送 Pause 給 Board B，並請求時間
  Serial.print('P');
  
  // 讀取 B 板回傳的時間 (秒數)
  unsigned long gameDuration = 0;
  unsigned long waitStart = millis();
  while(millis() - waitStart < 1000) { // 等待最多1秒
    if(Serial.available()) {
      gameDuration = Serial.parseInt();
      while(Serial.available()) Serial.read(); // 清空 buffer
      break;
    }
  }

  soundGameOver();

  lcd.clear();
  // 判斷是否破紀錄
  if (currentScore > highScore) {
    // 破紀錄！更新分數與時間
    highScore = currentScore;
    highScoreTime = gameDuration; // ★ 更新最佳時間
    
    lcd.print("NEW HIGH SCORE!");
    lcd.setCursor(0, 1);
    lcd.print("Val: "); lcd.print(highScore);
  } else {
    // 沒破紀錄
    lcd.print("GAME OVER");
    lcd.setCursor(0, 1);
    lcd.print("Score: "); lcd.print(currentScore);
  }
  
  lastMoveTime = millis(); // 用於計算停留時間
}

// 消除行數與更新分數
void clearLines() {
  int linesCleared = 0;
  for (int y = 0; y < 8; y++) {
    if (gameBoard[y] == 0xFF) { 
      linesCleared++;
      for (int k = y; k > 0; k--) gameBoard[k] = gameBoard[k-1];
      gameBoard[0] = 0;
    }
  }
  if (linesCleared > 0) { 
    currentScore += (linesCleared * 100); 
    
    // 即時更新 LCD 分數
    lcd.setCursor(7, 1); // "Score: " 後面的位置
    lcd.print(currentScore);
    
    soundClear(); 
  }
}

// --- Tetris 邏輯 (不變) ---
void playTetrisLogic() {
  unsigned long currentMillis = millis();
  handleInput();
  if (currentMillis - lastMoveTime > dropSpeed) {
    if (!checkCollision(currentX, currentY + 1, currentRotation)) {
      currentY++;
    } else {
      lockBlock(); clearLines(); spawnBlock(); 
      if (checkCollision(currentX, currentY, currentRotation)) triggerGameOver();
    }
    lastMoveTime = currentMillis;
  }
  updateDisplayBuffer(); refreshScreen(); delay(20);
}

// --- 音效與硬體控制 ---
void playTone(int freq, int duration) { tone(BUZZER_PIN, freq, duration); }
void soundMove() { tone(BUZZER_PIN, 400, 10); }
void soundStart() { int melody[] = {262, 330, 392, 523}; for (int i = 0; i < 4; i++) { tone(BUZZER_PIN, melody[i], 100); delay(120); } }
void soundClear() { tone(BUZZER_PIN, 1000, 50); delay(60); tone(BUZZER_PIN, 1500, 50); delay(60); tone(BUZZER_PIN, 2000, 100); }
void soundGameOver() { tone(BUZZER_PIN, 440, 200); delay(250); tone(BUZZER_PIN, 349, 200); delay(250); tone(BUZZER_PIN, 293, 400); }

void refreshScreen() { for (int i = 0; i < 8; i++) lc.setRow(0, i, displayBuffer[i]); }
void handleInput() {
  int xVal = analogRead(joyX); int yVal = analogRead(joyY);
  static unsigned long lastInputTime = 0;
  if (millis() - lastInputTime < 150) return; 
  if (xVal < 100) { if (!checkCollision(currentX - 1, currentY, currentRotation)) { currentX--; soundMove(); } lastInputTime = millis(); }
  if (xVal > 900) { if (!checkCollision(currentX + 1, currentY, currentRotation)) { currentX++; soundMove(); } lastInputTime = millis(); }
  if (yVal < 100) { int nextRot = (currentRotation + 1) % 4; if (!checkCollision(currentX, currentY, nextRot)) { currentRotation = nextRot; playTone(600, 30); } lastInputTime = millis(); }
  if (yVal > 900) dropSpeed = 50; else dropSpeed = 500;
}
void updateDisplayBuffer() {
  for (int i = 0; i < 8; i++) displayBuffer[i] = gameBoard[i];
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      byte rowShape = shapes[currentType][currentRotation][r];
      if (bitRead(rowShape, 3 - c)) {
        int worldX = currentX + c; int worldY = currentY + r;
        if (worldX >= 0 && worldX <= 7 && worldY >= 0 && worldY <= 7) bitWrite(displayBuffer[worldY], worldX, 1);
      }
    }
  }
}
boolean checkCollision(int x, int y, int rot) {
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      byte rowShape = shapes[currentType][rot][r];
      if (bitRead(rowShape, 3 - c)) {
        int worldX = x + c; int worldY = y + r;
        if (worldX < 0 || worldX > 7 || worldY > 7) return true;
        if (worldY >= 0) { if (bitRead(gameBoard[worldY], worldX)) return true; }
      }
    }
  }
  return false;
}
void lockBlock() {
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      byte rowShape = shapes[currentType][currentRotation][r];
      if (bitRead(rowShape, 3 - c)) {
        int worldX = currentX + c; int worldY = currentY + r;
        if (worldY >= 0 && worldY <= 7 && worldX >= 0 && worldX <= 7) bitWrite(gameBoard[worldY], worldX, 1);
      }
    }
  }
}
void spawnBlock() { currentType = random(0, 7); currentRotation = 0; currentX = 2; currentY = -1; dropSpeed = 500; }