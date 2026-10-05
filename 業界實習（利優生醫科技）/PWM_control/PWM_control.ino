const byte analogPin = A0;  // A1 = Vd ; A0 = VR ; 給 PIN5、6 輸出PWM
const int Vd = 1023;        // VDD/source
int Confirm=3;
float duty;
int retry;                  // 重新輸入

void setup() {
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);        // Pin 5、6輸出PW
  pinMode(12,OUTPUT); 
  pinMode(13,OUTPUT);       // Pin 12、13控制方向  
}

void loop() {
  for (int i = 100; i>0; i-- ){             // PWM緩關閉
    if (Confirm == 1){
      analogWrite(5, (duty*i/100*255));
      analogWrite(6, 0);
      delay(100);
    }
    if (Confirm == 0){
      analogWrite(6, (duty*i/100*255));
      analogWrite(5, 0);
      delay(100);
    }
  }

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);    
  delay(100);               // Dead time設定避免短路

  //float VR_Value= analogRead(analogPin);   //10bits解析度
  //float VR_Value= 500;   //10bits解析度
  //float duty = VR_Value/Vd;
  Serial.println("\n=== DUTY 值設定 ===");      // 輸入Duty
  float VR_Value = inputInt("0~100%");
  duty = VR_Value/100;

  while (true){
    Serial.println("\n=== PWM 控制系统 ==="); // 選擇腳位
    Serial.println("選擇轉向");
    int confirm = inputInt("順轉1 / 反轉0");
    Confirm = confirm;                       // Confirm為全域變數避免迴圈結束失去數值

    if (confirm == 1){                       // 選擇1順轉，0反轉
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    }
    if (confirm == 0){
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      break;
    }    
  }

  for (int i = 0; i<255; i++ ){               // PWM緩啟動
    int breakpoint = ChooseDirect();          // 依據方才的輸入決定PWM調控的MOSFET

    if (Confirm == 1){
      analogWrite(5, (duty*i));
      analogWrite(6, 0);
    }
    if (Confirm == 0){
      analogWrite(6, (duty*i));
      analogWrite(5, 0);
    }

    if (breakpoint == 1){                      // 跳出迴圈用，若迴圈時輸入r or R則結束迴圈
      retry = 1;
      break;
    }

    Serial.println(analogRead(A1));
    Serial.println(analogRead(A2));
    Serial.println("\n");                               // 控制迴圈時間，約0.1s執行一次
    delay(150);
  }

  while (true){
    //Serial.println(analogRead(A5));
    if (retry == 1){                            // 跳出for loop後再跳出 while loop回到開頭重新輸入
      break;
    }
    if (Confirm == 1){                          // 緩啟動結束後條回輸出
      analogWrite(5, duty*255);
    }
    if (Confirm == 0){
      analogWrite(6, duty*255);
    }
    if (Serial.available() > 0) {                 // 檢查是否有輸入
      String input = Serial.readStringUntil('\n');
      input.trim(); // 移除空白字元
      if (input == "r" || input == "R") {       // 回到開頭重新輸入
          Serial.println("重新選擇轉向...");
          //while (Serial.available() > 0) {
          //  Serial.read();
          //} 
          break;
      }
    }
    Serial.println(analogRead(A1));
    Serial.println("!");
    Serial.println(analogRead(A2));
    Serial.println("\n");
  }
}


int inputInt(String prompt) {
  //Serial.print(prompt);
  //while (Serial.available() == 0);  // 等待使用者輸入
  //return Serial.parseInt();         // 讀取整數
  // 加入逾時保護 - 
  unsigned long startTime = millis();
  const unsigned long TIMEOUT_MS = 120000;  // 120秒逾時
  
  while (Serial.available() == 0) {
    // 檢查逾時
    if (millis() - startTime > TIMEOUT_MS) {
      return 3;  // 返回預設值
    }
    delay(10);  // 短暫延遲，避免CPU滿載
  }

  Serial.print(prompt);
  while (Serial.available() == 0);    // 等待使用者輸入
  int result = Serial.parseInt();
  while (Serial.available() > 0) {    // 清空剩餘的輸入緩衝區
    Serial.read();
  }
  return result;
}

int ChooseDirect() {                  // 選擇方向
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim(); // 移除空白字元
    if (input == "r" || input == "R") {
        Serial.println("重新選擇轉向...");
        return 1;
    }
  }
  return 0;
}
