/*
 * File: gpio.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 11:45:38 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 9:40:40 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "hardware/gpio.h"
    #include <stdio.h>
}
// #include <iostream>
// #include <cstdio>

void gpio_set_function(uint gpio, enum gpio_function fn){
    if(fn == GPIO_FUNC_PWM){
        if(gpio != 28 ){
            printf("wrong gpio pin, should be 28 for pwm function");
        }
    } else if(fn == GPIO_FUNC_UART){
        if(gpio != 0 || gpio != 1){
            printf("wrong gpio pin, should be 0 for tx and 1 for rx when function is uart");
        }
    } else {
        printf("gpio function not GPIO_FUNC_PWM\n");
    }
}

#endif // MOK