/*
 * File: pwm.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:21:47 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 9:41:26 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "hardware/pwm.h"
    #include "types.h"
    #include <stdlib.h>
}
#include <cstdio>

void pwm_set_irq_enabled(uint slice_num, bool enabled){
    if(!enabled){
        printf("secend param should be true\n");
    }
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
}

void pwm_clear_irq(uint slice_num){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
}

void pwm_set_gpio_level(uint gpio, uint16_t level){
    if(gpio != 28){
        printf("gpio is not pin 28\n");
    }
    printf("setting level to %u\n", level);
}

void pwm_set_enabled(uint slice_num, bool enabled){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    if(!enabled){
        printf("second param should be true\n");
    }
}

void pwm_set_chan_level(uint slice_num, uint chan, uint16_t level){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    if(chan != PWM_CHAN_A){
        printf("pwm set chan level not on channel A");
    }
    printf("setting chan level to %u\n", level);
}

void pwm_set_wrap(uint slice_num, uint16_t wrap){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    if(wrap != 255){
        printf("pwm set wrap not 255\n");
    }
}

uint pwm_gpio_to_slice_num(uint gpio){
    if(gpio != 28){
        printf("gpio pin not 28!\n");
    }
    return 6;
}

#endif// MOK
