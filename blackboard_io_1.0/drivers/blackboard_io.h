
#ifndef BLACKBOARD_IO_H
#define BLACKBOARD_IO_H

#include "stdint.h"
#include "xparameters.h"


#define BB_IO_BASE XPAR_BLACKBOARD_IO_0_S00_AXI_BASEADDR

#define SW_DATA   *((uint32_t*) (BB_IO_BASE + 0x0))
#define BTN_DATA  *((uint32_t*) (BB_IO_BASE + 0x4))
#define LED_CTRL  *((uint32_t*) (BB_IO_BASE + 0x8))
#define SSEG_CTRL *((uint32_t*) (BB_IO_BASE + 0xC))


int get_sw_state(int n);
int get_btn_state(int n);

void en_led(int n);
void dis_led(int n);
void set_RGB(int n, int R, int G, int B);

void sseg_dig_en(uint8_t val);
void sseg_dp_en(uint8_t val);
void sseg_set_num(int num);
int sseg_get_num(void);


#endif // BLACKBOARD_IO_H
