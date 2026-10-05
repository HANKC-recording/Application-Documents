module FIR_filter (
    input wire clk,
    input wire rst_n,
    input wire data_en,
    input wire signed [15:0] data_in,   // x[n]
    output reg signed [15:0] data_out   // y[n]
);

    reg signed [15:0] h [0:63]; 
    
    initial begin
        // FIR Spec: Fs=500Hz, Fc=40Hz, Taps=64
        h[0] = -16'd3; 
        h[1] = 16'd10; 
        h[2] = 16'd24; 
        h[3] = 16'd36; 
        h[4] = 16'd42; 
        h[5] = 16'd37; 
        h[6] = 16'd16; 
        h[7] = -16'd20; 
        h[8] = -16'd66; 
        h[9] = -16'd111; 
        h[10] = -16'd138; 
        h[11] = -16'd129; 
        h[12] = -16'd73; 
        h[13] = 16'd29; 
        h[14] = 16'd161; 
        h[15] = 16'd289; 
        h[16] = 16'd370; 
        h[17] = 16'd362; 
        h[18] = 16'd239; 
        h[19] = -16'd0; 
        h[20] = -16'd318; 
        h[21] = -16'd644; 
        h[22] = -16'd884; 
        h[23] = -16'd935; 
        h[24] = -16'd715; 
        h[25] = -16'd182; 
        h[26] = 16'd650; 
        h[27] = 16'd1701; 
        h[28] = 16'd2840; 
        h[29] = 16'd3903; 
        h[30] = 16'd4725; 
        h[31] = 16'd5173; 
        h[32] = 16'd5173; 
        h[33] = 16'd4725; 
        h[34] = 16'd3903; 
        h[35] = 16'd2840; 
        h[36] = 16'd1701; 
        h[37] = 16'd650; 
        h[38] = -16'd182; 
        h[39] = -16'd715; 
        h[40] = -16'd935; 
        h[41] = -16'd884; 
        h[42] = -16'd644; 
        h[43] = -16'd318; 
        h[44] = -16'd0; 
        h[45] = 16'd239; 
        h[46] = 16'd362; 
        h[47] = 16'd370; 
        h[48] = 16'd289; 
        h[49] = 16'd161; 
        h[50] = 16'd29; 
        h[51] = -16'd73; 
        h[52] = -16'd129; 
        h[53] = -16'd138; 
        h[54] = -16'd111; 
        h[55] = -16'd66; 
        h[56] = -16'd20; 
        h[57] = 16'd16; 
        h[58] = 16'd37; 
        h[59] = 16'd42; 
        h[60] = 16'd36; 
        h[61] = 16'd24; 
        h[62] = 16'd10; 
        h[63] = -16'd3; 
    end

    reg signed [15:0] x_delay [0:63];
    integer k;

    reg signed [31:0] accumulator; 
    reg signed [31:0] mult_result;
    
    reg signed [31:0] scaled_result;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_out <= 0;
            for (k=0; k<64; k=k+1) x_delay[k] <= 0;
        end 
        else if (data_en) begin
            // Shift
            for (k=63; k>0; k=k-1) begin
                x_delay[k] <= x_delay[k-1];
            end
            
            x_delay[0] <= data_in;

            // Convolution
            accumulator = 0; 
            for (k=0; k<64; k=k+1) begin
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