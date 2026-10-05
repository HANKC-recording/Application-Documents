// =================================================================
// Homework 3 ： 8-Bit ALU ( Behavioral Model )
// =================================================================

module ALU8bit( Opcode, Operand1, Operand2, Cin, Result, flagC, flagZ);
    // -------------------------------------------------------------
    // Ports Declaration
    // -------------------------------------------------------------
    input [3:0] Opcode;                     // 4-bit Opcode (13種功能需用4bits)
    input [7:0] Operand1, Operand2;         // 8-bit Operand
    input Cin;                              // 1-bit 進位/借位輸入 (用於加法與減法)
    
    output reg [15:0] Result = 16'h0000;    // 16-bit 結果輸出
    output reg flagC = 1'b0,                // Carry flag，預設 0
               flagZ = 1'b0;                // Zero flag)，預設 0

    // -------------------------------------------------------------
    // Parameters for Opcodes
    // -------------------------------------------------------------
    // 運算功能
    parameter [3:0] ADD  = 4'b0000, // 1. Addition 
                    ADDC = 4'b0001, // 2. Addition with carry
                    SUB  = 4'b0010, // 3. Subtraction
                    SUBB = 4'b0011, // 4. Subtraction with borrow
                    DEC  = 4'b0100, // 5. Decrement (遞減)
                    INC  = 4'b0101, // 6. Increment (遞增)
                    TRA  = 4'b0110, // 7. Transfer function (輸出等於輸入，傳遞)
                    AND  = 4'b0111, // 8. Logical AND 
                    OR   = 4'b1000, // 9. Logical OR 
                    XOR  = 4'b1001, // 10. Logical XOR 
                    NOT  = 4'b1010, // 11. Logical NOT
                    SHL  = 4'b1011, // 12. Left shift  (左移 1 位)
                    SHR  = 4'b1100; // 13. Right shift (右移 1 位)

    // -------------------------------------------------------------
    // Combinational Logic
    // -------------------------------------------------------------
    always @ (Opcode or Operand1 or Operand2 or Cin)
    begin
        // ================= 【Arithmetic Unit】 =================
        
        // 1. Addition
        if (Opcode == ADD) begin
            Result = Operand1 + Operand2;
            flagC = Result[8];               // 以結果的第 8 位元(Bit 8)作為進位溢位判定
            flagZ = (Result == 16'h0000);    // 零旗標：當 16-bit 結果全為 0 時拉高
        end
        // 2. Addition with carry
        else if (Opcode == ADDC) begin
            Result = Operand1 + Operand2 + Cin;
            flagC = Result[8];
            flagZ = (Result == 16'h0000);
        end
        // 3. Subtraction
        else if (Opcode == SUB) begin
            Result = Operand1 - Operand2;
            flagC = Result[8];               // 減法借位旗標
            flagZ = (Result == 16'h0000);
        end
        // 4. Subtraction with borrow
        else if (Opcode == SUBB) begin
            Result = Operand1 - Operand2 - Cin;
            flagC = Result[8];
            flagZ = (Result == 16'h0000);
        end
        // 5. Decrement
        else if (Opcode == DEC) begin
            Result = Operand1 - 1'b1;
            flagC = Result[8];
            flagZ = (Result == 16'h0000);
        end
        // 6. Increment
        else if (Opcode == INC) begin
            Result = Operand1 + 1'b1;
            flagC = Result[8];
            flagZ = (Result == 16'h0000);
        end
        // 7. Transfer A
        else if (Opcode == TRA) begin
            Result = Operand1;               // 直接將運算元 1 傳送到輸出
            flagC = 1'b0;                    // 轉移無進位，清除 flagC
            flagZ = (Result == 16'h0000);
        end
        
        // ================= 【Logic Unit】 =================
        // 純邏輯運算不影響/不變更 flagC 的數值
        
        // 8. 邏輯 AND
        else if (Opcode == AND) begin
            Result = Operand1 & Operand2;
            flagZ = (Result == 16'h0000);
        end
        // 9. 邏輯 OR
        else if (Opcode == OR) begin
            Result = Operand1 | Operand2;
            flagZ = (Result == 16'h0000);
        end
        // 10. 邏輯 XOR
        else if (Opcode == XOR) begin
            Result = Operand1 ^ Operand2;
            flagZ = (Result == 16'h0000);
        end
        // 11. 邏輯 NOT
        else if (Opcode == NOT) begin
            Result = ~Operand1;
            flagZ = (Result == 16'h0000);
        end
        
        // ================= 【Shift Unit】 =================
        
        // 12. Left Shift
        else if (Opcode == SHL) begin
            Result = Operand1 << 1;
            flagC = Operand1[7];             // 左移時，原本的最高位元(Bit 7)會被擠出去，移入進位旗標
            flagZ = (Result == 16'h0000);
        end
        // 13. Right Shift
        else if (Opcode == SHR) begin
            Result = Operand1 >> 1;
            flagC = Operand1[0];             // 右移時，原本的最低位元(Bit 0)會被擠出去，移入進位旗標
            flagZ = (Result == 16'h0000);
        end
        
        // ================= 【Default Case】 =================
        else begin
            Result = 16'h0000;
            flagC = 1'b0;
            flagZ = 1'b0;
        end
    end
endmodule
