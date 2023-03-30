/*
 * File: pwmFanControl.cpp
 * Project: atp humidity control
 * File Created: Monday, 27th March 2023 1:47:08 pm
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 3:23:08 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

extern "C"{
    #include "pico/time.h"
    #include "hardware/gpio.h"
    #include "pico/stdlib.h"
    #include "stdio.h"
    #include "hardware/irq.h"
    #include "hardware/pwm.h"
}

#include "pwmFanControl.hpp"

//  Have to declase/define these values C stile because of 
//  the interrupt not accepting memberfunction pointers and not having an args parameter
static bool fanSpeedMutex = false;
static uint8_t fanSpeed = 100;

void PwmFanControl::init(){
    // set FAN_PWM_PIN to pwm function
    gpio_set_function(FAN_PWM_PIN, GPIO_FUNC_PWM);
    // get the pwm slice for FAN_PWM_PIN
    uint slice_num = pwm_gpio_to_slice_num(FAN_PWM_PIN);
    // set the wrap period to 255 cycles
    pwm_set_wrap(slice_num, 255);
    // configure pwm channel a
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 1);
    // start the pwm
    pwm_set_enabled(slice_num, true);
    // adjust the pwm to fanSpeed
    pwm_set_gpio_level (FAN_PWM_PIN, fanSpeed);
    // clear the interupt for this slice
    pwm_clear_irq(slice_num);
    // enable the interupt for this slice
    pwm_set_irq_enabled(slice_num, true);
    // set the interrupt to on_pwm_wrap method
    irq_set_exclusive_handler(PWM_IRQ_WRAP, on_pwm_wrap);
    // enable the interupt
    irq_set_enabled(PWM_IRQ_WRAP, true);
}

void PwmFanControl::on_pwm_wrap() {
    // Clear the interrupt flag that brought us here
    pwm_clear_irq(pwm_gpio_to_slice_num(FAN_PWM_PIN));
    // update pwm level to adjust fan speed
    pwm_set_gpio_level(FAN_PWM_PIN, getSpeed());
}

uint8_t PwmFanControl::getSpeed(){
    while (fanSpeedMutex){
        sleep_us(1);
    }
    fanSpeedMutex = true;
    uint8_t result = fanSpeed;
    fanSpeedMutex = false;
    return result;
}

void PwmFanControl::setSpeed(uint8_t newSpeed){
    if(newSpeed > 100){
        newSpeed = 100;
    }  
    
    while (fanSpeedMutex){
        sleep_us(1);
    }
    fanSpeedMutex = true;
    fanSpeed = uint8_t(2.55*newSpeed);
    printf("new fan speed: %u\n", fanSpeed);
    fanSpeedMutex = false; 
};
