/*
 * File: main.cpp
 * Project: atp humidity control
 * File Created: Monday, 27th March 2023 10:57:25 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 8:44:11 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#include <ctime>
extern "C"{
    #include "stdio.h"
    #include "pico/stdlib.h"
    #include "pico/multicore.h"
}

#include <stdlib.h>
#include <iostream>

#include "uartInterface.hpp"
#include "pwmFanControl.hpp"

// get the uart input and set it as the new fan speed
void core1Loop(){
    uint8_t value = 0;
    while(1){
        value = uart_getc(UART_ID);       
        
        PwmFanControl::setSpeed(value);      
    }
}

int main() {

    // initialize uart stuff
    UartInterface::setupUart();

    // let us knw that we are up
    std::cout << "################started################??\n";

    // initialize the pwm fan controller
    PwmFanControl::init();

    // start core1Loop function in core 1
    multicore_launch_core1(core1Loop);

    // main loop
    while (1){
        tight_loop_contents();
    }

}

