// Verilog test fixture created from schematic /home/ise/Xilinx_VM_lab/lab2_4bits_full_adder/ser_adder.sch - Sun Mar  8 15:58:13 2026

`timescale 1ns / 1ps

module ser_adder_ser_adder_sch_tb();

// Inputs
   reg A0;
   reg A1;
   reg A2;
   reg A3;
   reg B0;
   reg B1;
   reg B2;
   reg B3;
   reg Cin;

// Output
   wire Sum0;
   wire Sum1;
   wire Sum2;
   wire Sum3;
   wire Cout;

// Bidirs

// Instantiate the UUT
   ser_adder UUT (
		.Sum0(Sum0), 
		.Sum1(Sum1), 
		.Sum2(Sum2), 
		.Sum3(Sum3), 
		.A0(A0), 
		.A1(A1), 
		.A2(A2), 
		.A3(A3), 
		.B0(B0), 
		.B1(B1), 
		.B2(B2), 
		.B3(B3), 
		.Cin(Cin), 
		.Cout(Cout)
   );
// Initialize Inputs
   //`ifdef auto_init
      initial begin
		A0 = 0;
		A1 = 0;
		A2 = 0;
		A3 = 0;
		B0 = 0;
		B1 = 0;
		B2 = 0;
		B3 = 0;
		Cin = 0;
		end
		
		always begin
		#100;
		A0 <= $random %2;
		B0 <= $random %2;
		Cin <= $random %2;
		A1 <= $random %2;
		B1 <= $random %2;
		A2 <= $random %2;
		B2 <= $random %2;
		A3 <= $random %2;
		B3 <= $random %2;
		end
   //`endif
endmodule
