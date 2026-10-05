`timescale 1ms/100us

`include "ADC.v"
`include "fir_filter_hp.v"   // HP
`include "fir_filter.v"      // LP
`include "fir_filter_bs.v"   // NOTCH
`include "RR_detector.v"     // RR

module tb_system;
    reg clk;
    reg rst_n;

    wire signed [15:0] raw_data;
    wire signed [15:0] hp_data;
    wire signed [15:0] lp_data;
    wire signed [15:0] final_data;
    
    wire [31:0] energy_waveform;
    wire peak_flag;
    wire [31:0] rr_count;
    real rr_time_ms;

    initial clk = 0;
    always #1 clk = ~clk; 

    adc u_adc (
        .clk(clk),
        .rst_n(rst_n),
        .data_en(1'b1), 
        .data_out(raw_data)
    );
    FIR_filter_hp u_hp (
        .clk(clk),
        .rst_n(rst_n),
        .data_en(1'b1),
        .data_in(raw_data), 
        .data_out(hp_data)
    );
    FIR_filter u_lp (
        .clk(clk),
        .rst_n(rst_n),
        .data_en(1'b1),
        .data_in(hp_data), 
        .data_out(lp_data)
    );
    FIR_filter_BS u_notch (
        .clk(clk),
        .rst_n(rst_n),
        .data_en(1'b1),
        .data_in(lp_data),
        .data_out(final_data)
    );
    RR_detector u_rr (
        .clk(clk),
        .rst_n(rst_n),
        .data_in(final_data),
        .peak_flag(peak_flag),
        .rr_interval(rr_count),
        .energy_debug(energy_waveform)
    );

    always @(rr_count) begin
        rr_time_ms = rr_count * 2.0; 
    end

    initial begin
        $dumpfile("wave_ECG_analysis.vcd");
        $dumpvars(0, tb_system);
        
        $display("開始模擬...");
        
        rst_n = 1;
        #0.1 rst_n = 0; // Reset active
        #5   rst_n = 1; // Reset release
        
        #4100; // 跑 4 秒

        $display("模擬結束");
        $finish;
    end

endmodule