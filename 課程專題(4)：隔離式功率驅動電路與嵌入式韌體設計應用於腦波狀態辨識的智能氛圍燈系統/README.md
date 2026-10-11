# 課程專題(4)：隔離式功率驅動電路與嵌入式韌體設計應用於腦波狀態辨識的智能氛圍燈系統

[📄 點此直接打開備審全文（查看本專題之書面報告與數據分析）](課程專題(4).pdf)　｜　[🎬 期末報告（附 Demo 連結）](電工實_Final_連結附demo.pdf)

---

## 🧭 建議閱讀步驟

1. **看下方「分工」**：區分本人與組員負責的部分。
2. **看「設計重點」**（約 1 分鐘）：EEG 前處理、隔離功率驅動與 ESP32 韌體。
3. **看 Demo**：[期末報告](電工實_Final_連結附demo.pdf) 內有影片連結。
4. **想看電路與程式**：[`RGB LED.asc`](<RGBLED_LTspice/RGB LED.asc>)（LTspice）、[`RGBLEDdrive.ino`](RGBLEDdrive/RGBLEDdrive/RGBLEDdrive.ino)（韌體）。

## 專題概覽

114-2 臺大旁聽課程「電工實驗（生醫工程）」的期末專題。將 EEG 分類所得的狀態（放鬆／專注／眨眼）即時轉換成 RGB 燈條的色彩與亮度，整合**數位訊號處理、隔離功率驅動電路與 ESP32 韌體**。

- **系統資料流**：BrainLink 藍芽裝置擷取 EEG → PC 端前處理、分類與決策 → 序列埠送至 ESP32-S3 → 隔離功率級 → RGB LED 燈條。

## 分工

| 本人負責 | 組員負責 | 共同設計 |
| --- | --- | --- |
| EEG 訊號前處理（濾波、STFT／S2I、正規化）<br>隔離功率驅動電路設計（含 LTspice 模擬） | pCNN 模型訓練／調參<br>LOSO 與 Ensemble 分析<br>即時分類 GUI | ESP32 韌體驅動核心<br>雙模型即時決策邏輯 |

## 設計重點

- **EEG 前處理**：linear detrend 去基線漂移；掉包資料長度檢查與補零；40 Hz 五階 Butterworth 低通；STFT（1 秒窗、0.5 秒重疊）轉成 41×39 時頻圖；每張圖獨立正規化至 [0, 1]。
- **隔離功率驅動**：1N4007 橋式整流＋濾波電容供電；PC817 光耦隔離控制端與功率端並兼作準位轉換；閘極上／下拉電阻確保 MOSFET 完全關斷；三通道低邊開關＋限流電阻。
- **ESP32 韌體**：non-blocking 主迴圈，以 `millis()` 計時；LEDC 硬體 PWM（2 kHz、10-bit），共陽 LED 採反相輸出；四段亮度檔位，腦波眨眼或實體按鈕皆可換檔。

## 系統成果

分類模型（組員負責）含資料增強之測試準確率 92.3%；跨受試者 LOSO 驗證 20 秒三分類約 90.2%、4 秒眨眼二分類約 97.7%。

## 檔案導覽

| 想看什麼 | 檔案 |
| --- | --- |
| ESP32 韌體 | [`RGBLEDdrive/RGBLEDdrive/RGBLEDdrive.ino`](RGBLEDdrive/RGBLEDdrive/RGBLEDdrive.ino) |
| 功率驅動電路（LTspice） | [`RGBLED_LTspice/RGB LED.asc`](<RGBLED_LTspice/RGB LED.asc>) |
| 電路材料清單 | [`RGB_LED_Circuit_BOM.xlsx`](RGB_LED_Circuit_BOM.xlsx) |
| EEG 專題報告 | [`EEG 專題.pdf`](<EEG 專題.pdf>) |
| 期末報告與 Demo 連結 | [`電工實_Final_連結附demo.pdf`](電工實_Final_連結附demo.pdf) |
