/*
 * File: pwm.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:20:55 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 1:56:06 pm
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

/**
 * @brief 
 * Mok set the pwm irq enable
 * if not set to enabled the on wrap irq wont work
 * @param slice_num 
 * @param enabled 
 */
void pwm_set_irq_enabled(uint slice_num, bool enabled);

/**
 * @brief 
 * Mok the pwm clear irq function. 
 * Checks the params. Prints any faults.
 * if not cleared the on wrap irq wont work
 * @param slice_num 
 */
void pwm_clear_irq(uint slice_num);

/**
 * @brief 
 * Mok the pwm set gpio level function. 
 * Checks the params. Prints any faults.
 * @param gpio 
 * @param level 
 */
void pwm_set_gpio_level(uint gpio, uint16_t level);

/**
 * @brief 
 * Mok the pwm set enabled function.
 * if not set to enabled the on wrap irq wont work
 * @param slice_num 
 * @param enabled 
 */
void pwm_set_enabled(uint slice_num, bool enabled);

/**
 * @brief 
 * Mok the pwm set chan level.
 * Checks the params. Prints any faults.
 * @param slice_num 
 * @param chan 
 * @param level 
 */
void pwm_set_chan_level(uint slice_num, uint chan, uint16_t level);

/**
 * @brief 
 * Mok the pwm set wrap function. 
 * Checks the params. Prints any faults.
 * @param slice_num 
 * @param wrap 
 */
void pwm_set_wrap(uint slice_num, uint16_t wrap);

/**
 * @brief 
 * Mok the pwm gpio to slice num function.
 * Checks the params. Prints any faults.
 * returns 6. that is the slice of pin 28.
 * @param gpio 
 * @return 
 * 6
 */
uint pwm_gpio_to_slice_num(uint gpio);

/**
 * @brief 
 * Test if the pwm has been correctly configgured.
 * For mokking only. 
 * This is not a function declared in the original sdk.
 * @return true
 * if the test was withoud any errors.
 * @return false
 * if the test had erros.
 */
bool test_pwm();

#endif // PWM_H
#endif // MOK