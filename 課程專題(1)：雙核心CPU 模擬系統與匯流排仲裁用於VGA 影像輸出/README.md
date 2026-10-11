# 課程專題(1)：雙核心 CPU 模擬系統與匯流排仲裁用於 VGA 影像輸出

[📄 點此直接打開備審全文（查看本專題之書面報告與數據分析）](課程專題(1).pdf)　｜　[📊 期末專題簡報](期末專題簡報.pdf)

---

## 🧭 建議閱讀步驟

1. **看下方「設計重點」**（約 1 分鐘）：指令集、多週期 CPU 與 Round-Robin 仲裁。
2. **看 [`Project/dual.v`](Project/dual.v)**：系統頂層，兩顆核心、仲裁器與 VRAM 的連接。
3. **想看架構圖與 VGA 輸出畫面**：打開 [備審全文](課程專題(1).pdf) 或 [期末專題簡報](期末專題簡報.pdf)。

## 專題概覽

數位邏輯實習的期末專題。為了理解多核心系統搶同一份資源時如何協調而不出錯，我設計了**自訂指令集、兩顆獨立 CPU、共享 VRAM 與 Round-Robin 匯流排仲裁器**，最後以 VGA 即時輸出兩核平行繪製的畫面。一旦兩核同時寫入 VRAM，畫面就會損壞，因此畫面本身就是最直觀的驗證。

## 設計重點

- **自訂 16-bit 指令集**：固定格式 `opcode[15:12] / Rd[11:10] / Rs[9:8] / imm8[7:0]`，實作 8 個指令（MOV、ADD、SUB、AND、OR、OUT、BEQ、JMP）。
- **8-bit 多週期 CPU**：控制單元狀態機 FETCH → DECODE → EXECUTE → WRITEBACK；暫存器檔 R0–R3。
- **Round-Robin 匯流排仲裁**：單核請求直接授權，兩核同時請求時以 `last_gnt` 輪替，避免任一核 starvation；授權訊號直接接到 VRAM 寫入致能，兩核寫入天生互斥。
- **VGA 輸出**：標準 640×480 @ 60 Hz 時序，將 16×16 VRAM 每格放大成 40×30 色塊，3-bit RGB。

## 驗證結果

- 切換 `image_sel` 時兩核同步換圖，Reset 後兩核從 PC = 0 重啟。
- `gnt0`、`gnt1` 永不同時為 1；兩核同時請求時授權交替出現。
- VGA 穩定輸出由兩核分工繪製的完整點陣圖，無錯位或雜點。

> 目前完成**模擬與功能驗證**，尚未燒錄到 FPGA 實機。

## 檔案導覽

使用 [Digital](https://github.com/hneemann/Digital)（hneemann）設計與模擬：

| 想看什麼 | 檔案 |
| --- | --- |
| 雙核心系統頂層 | [`Project/dual.dig`](Project/dual.dig) |
| 系統頂層 Verilog | [`Project/dual.v`](Project/dual.v) |
| Core 0／Core 1 | [`Project/core0.dig`](Project/core0.dig)、[`Project/core1.dig`](Project/core1.dig) |
| VGA 顯示模組 | [`Project/VGA.dig`](Project/VGA.dig) |

以 Digital 開啟 `dual.dig` 即可直接執行模擬並看到 VGA 輸出畫面。
