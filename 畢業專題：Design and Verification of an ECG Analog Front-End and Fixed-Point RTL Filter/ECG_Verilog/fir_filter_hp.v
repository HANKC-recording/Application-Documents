module FIR_filter_hp (
    input wire clk,
    input wire rst_n,
    input wire data_en,
    input wire signed [15:0] data_in,   // x[n]
    output reg signed [15:0] data_out   // y[n]
);

    reg signed [15:0] h [0:126]; 
    
    initial begin
        // FIR Spec: High Pass, Fs=500Hz, Fc=5Hz, Taps=127
        h[0] = 16'd10; 
        h[1] = 16'd9; 
        h[2] = 16'd9; 
        h[3] = 16'd9; 
        h[4] = 16'd8; 
        h[5] = 16'd8; 
        h[6] = 16'd8; 
        h[7] = 16'd7; 
        h[8] = 16'd7; 
        h[9] = 16'd6; 
        h[10] = 16'd5; 
        h[11] = 16'd4; 
        h[12] = 16'd2; 
        h[13] = 16'd0; 
        h[14] = -16'd3; 
        h[15] = -16'd6; 
        h[16] = -16'd9; 
        h[17] = -16'd13; 
        h[18] = -16'd18; 
        h[19] = -16'd24; 
        h[20] = -16'd30; 
        h[21] = -16'd37; 
        h[22] = -16'd45; 
        h[23] = -16'd54; 
        h[24] = -16'd63; 
        h[25] = -16'd74; 
        h[26] = -16'd85; 
        h[27] = -16'd98; 
        h[28] = -16'd111; 
        h[29] = -16'd125; 
        h[30] = -16'd140; 
        h[31] = -16'd156; 
        h[32] = -16'd173; 
        h[33] = -16'd190; 
        h[34] = -16'd208; 
        h[35] = -16'd227; 
        h[36] = -16'd246; 
        h[37] = -16'd266; 
        h[38] = -16'd287; 
        h[39] = -16'd307; 
        h[40] = -16'd328; 
        h[41] = -16'd349; 
        h[42] = -16'd371; 
        h[43] = -16'd392; 
        h[44] = -16'd413; 
        h[45] = -16'd434; 
        h[46] = -16'd454; 
        h[47] = -16'd474; 
        h[48] = -16'd494; 
        h[49] = -16'd512; 
        h[50] = -16'd530; 
        h[51] = -16'd548; 
        h[52] = -16'd564; 
        h[53] = -16'd579; 
        h[54] = -16'd593; 
        h[55] = -16'd606; 
        h[56] = -16'd617; 
        h[57] = -16'd627; 
        h[58] = -16'd636; 
        h[59] = -16'd643; 
        h[60] = -16'd648; 
        h[61] = -16'd652; 
        h[62] = -16'd655; 
        h[63] = 16'd32122; 
        h[64] = -16'd655; 
        h[65] = -16'd652; 
        h[66] = -16'd648; 
        h[67] = -16'd643; 
        h[68] = -16'd636; 
        h[69] = -16'd627; 
        h[70] = -16'd617; 
        h[71] = -16'd606; 
        h[72] = -16'd593; 
        h[73] = -16'd579; 
        h[74] = -16'd564; 
        h[75] = -16'd548; 
        h[76] = -16'd530; 
        h[77] = -16'd512; 
        h[78] = -16'd494; 
        h[79] = -16'd474; 
        h[80] = -16'd454; 
        h[81] = -16'd434; 
        h[82] = -16'd413; 
        h[83] = -16'd392; 
        h[84] = -16'd371; 
        h[85] = -16'd349; 
        h[86] = -16'd328; 
        h[87] = -16'd307; 
        h[88] = -16'd287; 
        h[89] = -16'd266; 
        h[90] = -16'd246; 
        h[91] = -16'd227; 
        h[92] = -16'd208; 
        h[93] = -16'd190; 
        h[94] = -16'd173; 
        h[95] = -16'd156; 
        h[96] = -16'd140; 
        h[97] = -16'd125; 
        h[98] = -16'd111; 
        h[99] = -16'd98; 
        h[100] = -16'd85; 
        h[101] = -16'd74; 
        h[102] = -16'd63; 
        h[103] = -16'd54; 
        h[104] = -16'd45; 
        h[105] = -16'd37; 
        h[106] = -16'd30; 
        h[107] = -16'd24; 
        h[108] = -16'd18; 
        h[109] = -16'd13; 
        h[110] = -16'd9; 
        h[111] = -16'd6; 
        h[112] = -16'd3; 
        h[113] = 16'd0; 
        h[114] = 16'd2; 
        h[115] = 16'd4; 
        h[116] = 16'd5; 
        h[117] = 16'd6; 
        h[118] = 16'd7; 
        h[119] = 16'd7; 
        h[120] = 16'd8; 
        h[121] = 16'd8; 
        h[122] = 16'd8; 
        h[123] = 16'd9; 
        h[124] = 16'd9; 
        h[125] = 16'd9; 
        h[126] = 16'd10; 
 
    end

    reg signed [15:0] x_delay [0:127];
    integer k;

    reg signed [31:0] accumulator; 
    reg signed [31:0] mult_result;
    
    reg signed [31:0] scaled_result;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            data_out <= 0;
            for (k=0; k<127; k=k+1) x_delay[k] <= 0;
        end 
        else if (data_en) begin
            // Shift
            for (k=126; k>0; k=k-1) begin
                x_delay[k] <= x_delay[k-1];
            end
            
            x_delay[0] <= data_in;

            // Convolution
            accumulator = 0; 
            for (k=0; k<127; k=k+1) begin
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