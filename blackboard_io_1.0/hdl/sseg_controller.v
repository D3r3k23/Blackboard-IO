
module sseg_controller
(
    input wire          clk,
    input wire [3  : 0] dig_en,
    input wire [3  : 0] dp_en,
    input wire [13 : 0] num,

    output wire [3 : 0] an,
    output wire [7 : 0] cat
);

    wire div_clk;

    sseg_clk_divider #( .DIV_BIT(14) )
    clk_gen
    (
        .clk     ( clk     ),
        .div_clk ( div_clk )
    );

    reg [1 : 0] dig_sel = 0;

    always @( posedge div_clk )
        dig_sel <= dig_sel + 1;

    wire [3 : 0] an_data;
    wire [6 : 0] cat_data;

    sseg_decoder sseg_decoder_inst
    (
        .num      ( num      ),
        .dig_sel  ( dig_sel  ),
        .an_data  ( an_data  ),
        .cat_data ( cat_data )
    );

    assign an = ~(dig_en & an_data);

    assign cat[7] = ~dp_en[dig_sel];

    assign cat[6 : 0] = dig_en[dig_sel] ? ~cat_data : 7'd0;

endmodule // sseg_controller
