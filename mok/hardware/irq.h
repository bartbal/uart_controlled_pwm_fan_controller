/*
 * File: irq.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:20:42 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 6:08:53 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */
#ifdef MOK
#ifndef IRQ_H
#define IRq_H

#include "types.h"
#include <stdlib.h>

typedef void (*irq_handler_t)(void);

void irq_set_exclusive_handler(uint num, irq_handler_t handler);

void irq_set_enabled(uint num, bool enabled);

#endif // IRQ_H
#endif // MOK