/*
 * File: pwm.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:20:55 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 3:50:58 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK
#ifndef PWM_H
#define PWM_H

#include "types.h"
#include <stdlib.h>

enum pwm_chan
{
    PWM_CHAN_A = 0,
    PWM_CHAN_B = 1
};

#define PWM_IRQ_WRAP 4

void pwm_set_irq_enabled(uint slice_num, bool enabled);

void pwm_clear_irq(uint slice_num);

void pwm_set_gpio_level(uint gpio, uint16_t level);

void pwm_set_enabled(uint slice_num, bool enabled);

void pwm_set_chan_level(uint slice_num, uint chan, uint16_t level);

void pwm_set_wrap(uint slice_num, uint16_t wrap);

uint pwm_gpio_to_slice_num(uint gpio);

#endif // PWM_H
#endif // MOK