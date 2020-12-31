
#include "blackboard_io.h"


int get_sw_state(int n)
{
    if (0 <= n && n <= 11)
        return ((SW_DATA & 0b1 << n) != 0);
    else
        return 0;
}

int get_btn_state(int n)
{
    if (0 <= n && n <= 3)
        return ((BTN_DATA & 0b1 << n) != 0);
    else
        return 0;
}

void en_led(int n)
{
    if (0 <= n && n <= 9)
        LED_CTRL |= (0b1 << n);
}

void dis_led(int n)
{
    if (0 <= n && n <= 9)
        LED_CTRL &= ~(0b1 << n);
}

void set_RGB(int n, int R, int G, int B)
{
    int offset;
    switch (n)
    {
        case 10 : offset = 10; break;
        case 11 : offset = 13; break;
        default : return;
    }
    LED_CTRL &= ~(0b111 << offset);
    LED_CTRL |= (R & 0b1) << (offset + 2);
    LED_CTRL |= (G & 0b1) << (offset + 1);
    LED_CTRL |= (B & 0b1) << offset;
}

void sseg_dig_en(uint8_t val)
{
    SSEG_CTRL &= ~0xF;
    SSEG_CTRL |= (val & 0xF);
}

void sseg_dp_en(uint8_t val)
{
    SSEG_CTRL &= ~(0xF << 4);
    SSEG_CTRL |= (val & 0xF) << 4;
}

void sseg_set_num(int num)
{
    if (0 <= num && num <= 9999)
    {
        SSEG_CTRL &= ~(0x3FFF << 8);
        SSEG_CTRL |= (num & 0x3FFF) << 8;
    }
}

int sseg_get_num(void)
{
    return (SSEG_CTRL & 0x3FFF) >> 8;
}
