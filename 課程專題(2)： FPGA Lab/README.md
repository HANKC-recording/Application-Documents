# 課程專題(2)：FPGA Lab

[📄 點此直接打開備審全文（查看本專題之書面報告與數據分析）](課程專題(2).pdf)

---

## 🧭 建議閱讀步驟

1. **看下方「一、Altera／Quartus」**（約 1 分鐘）：SRAM 累加器從手動控制到狀態機、再燒錄上板的過程。
2. **想看實機照片與狀態圖**：打開 [備審全文](課程專題(2).pdf)。
3. **想看原始碼**：直接用下方「檔案導覽」，不需要逐一翻資料夾。

## 專題概覽

整理自「數位邏輯設計實習」「FPGA 系統設計實務」「計算機組織」三門課，涵蓋 **VHDL 與 Verilog 兩種硬體描述語言**，以及 **Altera Quartus 與 Xilinx ISE 兩大 FPGA 工具鏈**。

> 資料夾內檔案較多，大部分是工具自動產生的模擬檔。**重點檔案請看下方「檔案導覽」**。

## 一、Altera／Quartus：SRAM 累加器（已燒錄上板）

- **分工**：課程為兩人一組分題進行，SRAM 累加器由本人負責（電路設計、VHDL、模擬、Altera 開發板燒錄與實機驗證）。
- **手動控制版**：以 VHDL 實作 4×4 SRAM（CS／WE／OE 控制，未致能時輸出高阻抗），與 4-bit 加減法器、比較器整合成可偵測溢位的累加器。
- **狀態機版**：把整排手動控制線整合成 Moore 有限狀態機（S0–S5），加入同步 reset。
- **實機驗證**：以 Quartus 燒錄到 Altera 開發板，指撥開關輸入、LED 顯示狀態與結果，跑完完整累加序列並確認溢位時鎖住 SRAM。

## 二、Xilinx ISE：8-bit ALU 與 schematic 設計（模擬驗證）

- **8-bit ALU**：以 Verilog behavioral description 實作 13 種運算（ADD、SUB、AND、OR、XOR、SHL、SHR 等），輸出 16-bit 結果與 carry／zero 旗標，testbench 掃過全部運算驗證。
- **Schematic 設計**：以 ISE 畫 1-bit 全加器、串列加法器等電路並模擬。
- **開發環境**：開發板為 Spartan-6 SP601，只能使用已停止維護的 ISE，因此以 Oracle VirtualBox 架設相容環境執行。

> 這部分僅保留**模擬結果**，未錄下實機執行畫面。

## 檔案導覽

| 想看什麼 | 檔案 |
| --- | --- |
| SRAM 累加器（手動控制版） | [`數位邏輯設計實習(ALTERA)/Digital file/lab7/`](<數位邏輯設計實習(ALTERA)/Digital file/lab7>) 內 `SRAM*.dig` |
| SRAM 累加器（狀態機版） | [`數位邏輯設計實習(ALTERA)/Digital file/lab9/`](<數位邏輯設計實習(ALTERA)/Digital file/lab9>) 內 `SRAM*.dig` |
| 各次實習報告 | `數位邏輯設計實習(ALTERA)/` 內 `DLE xx_*.pdf` |
| 8-bit ALU 原始碼 | [`ALU.v`](<FPGA系統設計實務/CO_ALU(虛擬機執行檔)/ALU.v>) |
| 8-bit ALU Testbench | [`ALU_tb.v`](<FPGA系統設計實務/CO_ALU(虛擬機執行檔)/ALU_tb.v>) |
| 串列加法器（schematic＋testbench） | [`ser_adder.sch`](<FPGA系統設計實務/lab2(虛擬機執行檔)/ser_adder.sch>)、[`ser_adder_tb.v`](<FPGA系統設計實務/lab2(虛擬機執行檔)/ser_adder_tb.v>) |
| 計算機組織作業報告 | [`計算機組織作業報告/`](計算機組織作業報告) |

`.dig` 檔可用 [Digital](https://github.com/hneemann/Digital) 開啟並直接模擬。
