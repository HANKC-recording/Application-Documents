module adc (
    input wire clk,             // Sampling Clock
    input wire rst_n,           // reset_negedge
    input wire data_en,
    output reg [15:0] data_out  // 16-bits output
);

    reg [15:0] memory [0:65535];
    integer idx;

    initial begin
        $readmemh("ecg_input.hex", memory);
        idx = 0;
        data_out = 0;
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            idx <= 0;
            data_out <= 0;
        end

        else if (data_en) begin
            data_out <= memory[idx];
            if (idx < 65535) 
                idx <= idx + 1;
            else 
                idx <= 0;
        end
    end
endmodule