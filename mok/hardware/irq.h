/*
 * File: irq.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:20:42 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 1:19:41 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */
#ifdef MOK
#ifndef IRQ_H
#define IRq_H

#include "types.h"
#include <stdlib.h>

// declare irq handler type
typedef void (*irq_handler_t)(void);

/**
 * @brief 
 * Mok setting interrupt. This creates a thread that calls the handler every half a second.
 * it also checks if the correct num was passed.
 * @param num 
 * @param handler 
 */
void irq_set_exclusive_handler(uint num, irq_handler_t handler);

/**
 * @brief 
 * Mok the set enabled function. checks paramters.
 * if irq is not enabled the irq handler set with 
 * irq_set_exclusive_handler will not be called.
 * @param num 
 * @param enabled 
 */
void irq_set_enabled(uint num, bool enabled);

#endif // IRQ_H
#endif // MOK