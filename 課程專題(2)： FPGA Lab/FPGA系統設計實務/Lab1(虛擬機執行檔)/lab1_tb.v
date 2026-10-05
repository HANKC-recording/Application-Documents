// Verilog test fixture created from schematic /home/ise/Xilinx_VM_lab/Lab1/lab1.sch - Wed Mar  4 19:04:51 2026

`timescale 1ns / 1ps

module lab1_lab1_sch_tb();

// Inputs
   reg A;
   reg B;
   reg C;

// Output
   wire Sum;
   wire Cout;

// Bidirs

// Instantiate the UUT
   lab1 UUT (
		.A(A), 
		.B(B), 
		.C(C), 
		.Sum(Sum), 
		.Cout(Cout)
   );
// Initialize Inputs
   //`ifdef auto_init
      initial begin
		A = 0;
		B = 0;
		C = 0;
		#4000;
		
		$finish;
		end
		
		always #100 A = ~A;
		always #200 B = ~B;
   //`endif
endmodule
