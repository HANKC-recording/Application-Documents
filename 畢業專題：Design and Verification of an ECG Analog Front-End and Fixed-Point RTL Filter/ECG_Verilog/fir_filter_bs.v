module FIR_filter_BS (
    input wire clk,
    input wire rst_n,
    input wire data_en,
    input wire signed [15:0] data_in,   // x[n]
    output reg signed [15:0] data_out   // y[n]
);

    reg signed [15:0] h [0:64]; 
    
    initial begin
        // FIR Spec: Fs=500Hz, F_notch=60Hz, Taps=65
        h[0] = -16'd6; 
        h[1] = 16'd2; 
        h[2] = 16'd9; 
        h[3] = 16'd13; 
        h[4] = 16'd10; 
        h[5] = -16'd1; 
        h[6] = -16'd15; 
        h[7] = -16'd24; 
        h[8] = -16'd20; 
        h[9] = -16'd2; 
        h[10] = 16'd24; 
        h[11] = 16'd42; 
        h[12] = 16'd38; 
        h[13] = 16'd10; 
        h[14] = -16'd32; 
        h[15] = -16'd63; 
        h[16] = -16'd62; 
        h[17] = -16'd24; 
        h[18] = 16'd35; 
        h[19] = 16'd82; 
        h[20] = 16'd87; 
        h[21] = 16'd42; 
        h[22] = -16'd32; 
        h[23] = -16'd95; 
        h[24] = -16'd110; 
        h[25] = -16'd63; 
        h[26] = 16'd23; 
        h[27] = 16'd100; 
        h[28] = 16'd125; 
        h[29] = 16'd82; 
        h[30] = -16'd8; 
        h[31] = -16'd95; 
        h[32] = 16'd32623; 
        h[33] = -16'd95; 
        h[34] = -16'd8; 
        h[35] = 16'd82; 
        h[36] = 16'd125; 
        h[37] = 16'd100; 
        h[38] = 16'd23; 
        h[39] = -16'd63; 
        h[40] = -16'd110; 
        h[41] = -16'd95; 
        h[42] = -16'd32; 
        h[43] = 16'd42; 
        h[44] = 16'd87; 
        h[45] = 16'd82; 
        h[46] = 16'd35; 
        h[47] = -16'd24; 
        h[48] = -16'd62; 
        h[49] = -16'd63; 
        h[50] = -16'd32; 
        h[51] = 16'd10; 
        h[52] = 16'd38; 
        h[53] = 16'd42; 
        h[54] = 16'd24; 
        h[55] = -16'd2; 
        h[56] = -16'd20; 
        h[57] = -16'd24; 
        h[58] = -16'd15; 
        h[59] = -16'd1; 
        h[60] = 16'd10; 
        h[61] = 16'd13; 
        h[62] = 16'd9; 
        h[63] = 16'd2; 
        h[64] = -16'd6;  
    end

    reg signed [15:0] x_delay [0:64];
    integer k;

    reg signed [31:0] accumulator; 
    reg signed [31:0] mult_result;
    
    reg signed [31:0] scaled_result;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_out <= 0;
            for (k=0; k<65; k=k+1) x_delay[k] <= 0;
        end 
        else if (data_en) begin
            // Shift
            for (k=64; k>0; k=k-1) begin
                x_delay[k] <= x_delay[k-1];
            end
            
            x_delay[0] <= data_in;

            // Convolution
            accumulator = 0; 
            for (k=0; k<65; k=k+1) begin
                mult_result = x_delay[k] * h[k];
                accumulator = accumulator + mult_result;
            end

            scaled_result = accumulator >>> 15;

            if (scaled_result > 32767) begin
                data_out <= 32767;
            end

            else if (scaled_result < -32768) begin
                data_out <= -32768;
            end

            else begin
                data_out <= scaled_result[15:0];
            end
        end
    end
endmodule