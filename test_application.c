
#include "blackboard_io.h"
#include "sleep.h"


int main(void)
{
    set_RGB(10, 1, 0, 0); // led 10: R
    set_RGB(11, 0, 0, 1); // led 11: B

    sseg_dig_en(0xF);
    sseg_dp_en(0);
    sseg_set_num(0);

    while (1)
    {
        for (int i = 0; i <= 9; i++)
            if (get_sw_state(i))
                en_led(i);
            else
                dis_led(i);
        
        int ssegNum = 0;

        if (get_btn_state(0)) ssegNum  = 1;
        if (get_btn_state(1)) ssegNum += 10;
        if (get_btn_state(2)) ssegNum += 100;
        if (get_btn_state(3)) ssegNum += 1000;

        sseg_set_num(ssegNum);

        usleep(1000); // 1 ms
    }

    return 0;
}
