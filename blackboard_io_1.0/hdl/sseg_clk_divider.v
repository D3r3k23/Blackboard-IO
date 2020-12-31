
module sseg_clk_divider
#(parameter
    integer DIV_BIT = 14 // for 100 MHz clk
)(
    input  wire clk,
    output wire div_clk
);

    integer count = 0;

    always @( posedge clk )
        count <= count + 1;
    
    assign div_clk = count[DIV_BIT];

endmodule // sseg_clk_divider
