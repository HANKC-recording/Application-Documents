module RR_detector (
    input wire clk,
    input wire rst_n,
    input wire signed [15:0] data_in,
    output reg peak_flag,
    output reg [31:0] rr_interval,
    output wire [31:0] energy_debug 
);

    parameter THRESHOLD_SQ = 32'd130000000;

    // Refractory Period
    // 500Hz 採樣率 -> 250ms = 125 點
    // 拉長到 250ms 可以有效避開 T 波的誤判
    parameter REFRACTORY_PERIOD = 125; 

    // ============================================================
    
    // 內部變數
    reg [31:0] global_counter;    
    reg [31:0] last_peak_time;
    reg [31:0] refractory_cnt;
    
    // 平方運算 (Squaring) - 讓 R 波更明顯，壓制 T 波與雜訊
    // data_in 是 16-bit, 平方後最大 32-bit (包含符號位其實31-bit)
    wire signed [31:0] data_sq;
    assign data_sq = data_in * data_in;
    
    // 輸出給你看波形用的 (轉成 unsigned 方便觀察)
    assign energy_debug = data_sq;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            global_counter <= 0;
            last_peak_time <= 0;
            rr_interval <= 0;
            peak_flag <= 0;
            refractory_cnt <= 0;
        end 
        else begin
            // 1. 全域時間計數
            global_counter <= global_counter + 1;
            
            // 預設 flag 為 0 (脈衝)
            peak_flag <= 0;

            // 2. 處理不反應期倒數
            if (refractory_cnt > 0) begin
                refractory_cnt <= refractory_cnt - 1;
            end
            
            // 3. 峰值偵測邏輯 (使用平方後的能量 data_sq)
            else if (data_sq > THRESHOLD_SQ && refractory_cnt == 0) begin
                
                // --- 偵測到 R 波 ---
                peak_flag <= 1;
                
                // 計算 RR Interval
                if (last_peak_time != 0) begin
                    rr_interval <= global_counter - last_peak_time;
                end
                
                // 更新時間
                last_peak_time <= global_counter;
                
                // 進入不反應期
                refractory_cnt <= REFRACTORY_PERIOD;
            end
        end
    end

endmodule