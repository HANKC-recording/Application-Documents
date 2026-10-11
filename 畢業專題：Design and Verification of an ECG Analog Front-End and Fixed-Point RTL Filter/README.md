# 畢業專題：Design and Verification of an ECG Analog Front-End and Fixed-Point RTL Filter

[📄 點此直接打開備審全文（查看本專題之書面報告與數據分析）](畢業專題.pdf)　｜　[📄 期末成果報告](畢業專題期末成果報告_張博翔.pdf)

---

## 🧭 建議閱讀步驟

1. **看下方「專題概覽」與「數位端」**（約 1 分鐘）：了解系統架構與定點化設計。
2. **看 [`ECG_Verilog/tbECG.v`](ECG_Verilog/tbECG.v)**：系統頂層，可以看到各模組如何串接。
3. **看 [`ECG_Verilog/fir_filter_hp.v`](ECG_Verilog/fir_filter_hp.v)**：127 taps 高通 FIR，MAC 摺積與 Q15 定點運算的核心。
4. **想看驗證波形與完整數據**：打開 [備審全文](畢業專題.pdf)。

## 專題概覽

以 ECG 作為測試訊號，完成一條「類比前端 → 數位 FIR 濾波 → 心率偵測」的訊號鏈。**設計重心在數位端**：以 Verilog 從零建構定點 FIR 濾波器與 RR 間期偵測器，並以 testbench 驗證；類比前端則完成 LTspice 設計、麵包板實作與示波器頻率響應量測。

- **個人專題**：設計、實作、驗證皆由本人獨立完成（指導教授：劉健群）。
- **獎項**：開發前期以階段性成果參加生物醫學工程學系專題研究競賽，獲**佳作**（當時題名為「Electrocardiogram Detection Circuit」）。

## 數位端（Verilog RTL）

- **資料路徑**：訊號源模組 → 高通 FIR → 低通 FIR → 陷波 FIR → RR 偵測器，各級間為 16-bit 有號資料，每級 FIR 介面一致、可單獨替換或驗證。
- **定點化**：係數乘上 2¹⁵ 四捨五入為整數（Q15），32-bit 累加器承接乘積和，最後右移 15 位還原並做 16-bit 飽和，避免溢位。
- **FIR 規格**：高通 127 taps、低通 64 taps、陷波 65 taps，皆為線性相位對稱係數。
- **RR 偵測**：簡化 Pan–Tompkins，平方突顯 R 波，搭配閾值與 250 ms 不反應期避開 T 波。
- **驗證結果**：量得 RR 間期約 1000 ms，對應心率 60 BPM。

> 本專題**未實作實體 ADC**。`ADC.v` 為訊號源模組，將 MATLAB 預先數位化的 ECG 樣本以 500 Hz 逐點播放，模擬 ADC 取樣的資料流；類比前端與數位管線目前各自獨立驗證。

## 類比前端（LTspice＋實體量測）

- **架構**：儀表放大器（增益 ×10）→ Sallen–Key 二階高通（0.5 Hz）→ 四階低通（100 Hz）→ 雙 T 陷波（60 Hz）。
- **實測**：麵包板實作後以 Keysight DSOX1202G 頻率響應分析（10–150 Hz）量測，重現模擬的帶通形狀與 60 Hz 陷波（相對通帶約 44 dB 衰減，模擬約 50 dB）。

## 檔案導覽

| 內容 | 檔案 |
| --- | --- |
| Testbench（系統頂層，從這裡看起） | [`ECG_Verilog/tbECG.v`](ECG_Verilog/tbECG.v) |
| 高通 FIR（127 taps） | [`ECG_Verilog/fir_filter_hp.v`](ECG_Verilog/fir_filter_hp.v) |
| 低通 FIR（64 taps） | [`ECG_Verilog/fir_filter.v`](ECG_Verilog/fir_filter.v) |
| 陷波 FIR（65 taps） | [`ECG_Verilog/fir_filter_bs.v`](ECG_Verilog/fir_filter_bs.v) |
| RR 間期偵測器 | [`ECG_Verilog/RR_detector.v`](ECG_Verilog/RR_detector.v) |
| 訊號源模組（播放預錄樣本） | [`ECG_Verilog/ADC.v`](ECG_Verilog/ADC.v) |
| 類比前端整體電路（LTspice） | [`filter_design_LTspice/ECG_ckt_sim.asc`](filter_design_LTspice/ECG_ckt_sim.asc) |
| 各級類比電路 | `filter_design_LTspice/` 內 `IA`、`HPF`、`LPF`、`TwinT` 等 `.asc` 檔 |
