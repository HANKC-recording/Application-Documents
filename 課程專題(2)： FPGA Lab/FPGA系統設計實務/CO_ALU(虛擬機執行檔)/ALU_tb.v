`timescale 1ns/100ps    // 設定時間單位為 1ns，時間精度為 100ps
`include "ALU.v"        // 導入 ALU 模組檔名

module ALU8bit_tb;

    // Inputs
    reg [3:0] Opcode;
    reg [7:0] Operand1;
    reg [7:0] Operand2;
    reg Cin;

    // Outputs
    wire [15:0] Result;
    wire flagC;
    wire flagZ;

    // Temporary variable (內部計數)
    reg [3:0] count = 4'b0000;

    // Instantiate the Unit Under Test (UUT)
    ALU8bit uut (
        .Opcode(Opcode), 
        .Operand1(Operand1), 
        .Operand2(Operand2), 
        .Cin(Cin),
        .Result(Result), 
        .flagC(flagC), 
        .flagZ(flagZ)
    ); 

    initial begin
        // Initialize Inputs (初始化)
        Opcode = 4'b0000;
        Operand1 = 8'h00;
        Operand2 = 8'h00;
        Cin = 1'b0;

        // 等待 100 ns 讓全域重置完成
        #100; 
        
        // Stimulus
        Operand1 = 8'hAA;   // 二進位: 10101010
        Operand2 = 8'h55;   // 二進位: 01010101
        Cin = 1'b1;         // 測試帶進位加減法時使用
        
        // 利用 for 迴圈自動掃描 13 種 Opcode 運算結果
        for (count = 0; count < 13; count = count + 1'b1) begin
            Opcode = count;
            #20;            // 每隔 20ns 變換一次運算功能
        end
        
        $finish;            // 結束模擬
    end

    // =================================================================
    // Terminal Monitor
    // =================================================================
    initial begin
        $display("-------------------------------------------------------------------------------------------------------");
        $display(" 時間(Time) | Opcode | Operand1 (十六/十進位) | Operand2 (十六/十進位) | Cin =>  Result (十六進位) |  C  |  Z ");
        $display("-------------------------------------------------------------------------------------------------------");
        
        $monitor("%8t ns |  %b  |    %h    (%3d)     |    %h    (%3d)     |  %b  =>      %h        |  %b  |  %b ", 
                 $time,     Opcode,  Operand1, Operand1,  Operand2, Operand2,  Cin,    Result,            flagC, flagZ);
    end

    initial begin
        $dumpfile("ALU_wave.vcd");
        $dumpvars(0, ALU8bit_tb);
    end
    
endmodule