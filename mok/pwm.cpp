/*
 * File: pwm.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:21:47 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 8:37:47 pm
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

static bool _irq_enabled = false;
static bool _pwm_cleared = false;
static bool _pwm_enabled = false;

void pwm_set_irq_enabled(uint slice_num, bool enabled){
    if(!enabled){
        printf("second param should be true\n");
    }
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    _irq_enabled = enabled;
}

void pwm_clear_irq(uint slice_num){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    _pwm_cleared = true;
}

static uint16_t prevLevel = 1;

void pwm_set_gpio_level(uint gpio, uint16_t level){
    if(gpio != 28){
        printf("gpio is not pin 28\n");
    }
    if(level != prevLevel){
        printf("setting level to %u\n", level);
        prevLevel = level;
    }
}

void pwm_set_enabled(uint slice_num, bool enabled){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    if(!enabled){
        printf("second param should be true\n");
    }
    _pwm_enabled = enabled;
}

void pwm_set_chan_level(uint slice_num, uint chan, uint16_t level){
    if(slice_num != 6){
        printf("wrong pwm slice!\n");
    }
    if(chan != PWM_CHAN_A){
        printf("pwm set chan level not on channel A\n");
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

bool test_pwm(){
    if(!_irq_enabled){
        printf("_irq_enabled not enabled!\n");
        return false;
    }    
    if(!_pwm_cleared){
        printf("_pwm_cleared not enabled!\n");
        return false;
    }
    if(!_pwm_enabled){
        printf("_pwm_enabled not enabled!\n");
        return false;
    }    
    return true;
}

#endif// MOK
