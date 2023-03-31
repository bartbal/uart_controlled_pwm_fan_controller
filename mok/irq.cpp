/*
 * File: irq.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:21:25 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 1:30:52 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "hardware/irq.h"
    #include <stdlib.h>
    #include "pico/multicore.h"
    #include "pico/time.h"
    #include "hardware/pwm.h"
}

#include <thread>
#include <cstdio>

// used to store the handle given by irq_set_exclusive_handler.
// Cannot pass this as argument so had to wrap it in irq_loop.
static irq_handler_t _handler;

// used to test if irq has been set to enabled
static bool _enabled = false;

/**
 * @brief 
 * Moks the on wrap interrupt. This calls the irq_handler 
 * about as many times the original interupt does
 */
static void irq_loop(){
    while(true){
        if(multicore_subs_exit()){
            break;
        }
        if(_enabled){
            if(test_pwm()){
                _handler();
            } else {
                printf("PWM not configured correctly!\n");
            }
        } else {
            printf("irq not enabled, call irq_set_enabled to enable\n");
        }
        sleep_us(500000);
    }
}

void irq_set_exclusive_handler(uint num, irq_handler_t handler){
    if(num != 4){
        printf("First param should be 4!\n");
    }
    _handler = handler;
    // launch thread and detach
    std::thread thread_obj(irq_loop);
    thread_obj.detach();
}

void irq_set_enabled(uint num, bool enabled){
    if(num != 4){
        printf("First param should be 4!\n");
    }
    if(!enabled){
        printf("irq set enabled should be enabled!");
    }
    _enabled = enabled;
}


#endif