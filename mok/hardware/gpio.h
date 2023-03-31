/*
 * File: gpio.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 11:13:12 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 12:41:42 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK
#ifndef GPIO_H
#define GPIO_H

#include <types.h>

// define gpio_function enum
enum gpio_function {
    GPIO_FUNC_XIP = 0,
    GPIO_FUNC_SPI = 1,
    GPIO_FUNC_UART = 2,
    GPIO_FUNC_I2C = 3,
    GPIO_FUNC_PWM = 4,
    GPIO_FUNC_SIO = 5,
    GPIO_FUNC_PIO0 = 6,
    GPIO_FUNC_PIO1 = 7,
    GPIO_FUNC_GPCK = 8,
    GPIO_FUNC_USB = 9,
    GPIO_FUNC_NULL = 0xf,
};

/**
 * @brief 
 * Mok function to set gpio function.
 * This will check the given params and print any issues
 * @param gpio 
 * @param fn 
 */
void gpio_set_function(uint gpio, enum gpio_function fn);

#endif // GPIO_H
#endif // MOK
