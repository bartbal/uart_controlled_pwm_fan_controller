/*
 * File: irq.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:21:25 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 9:41:03 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "hardware/irq.h"
    #include <stdlib.h>
}
#include <cstdio>

void irq_set_exclusive_handler(uint num, irq_handler_t handler){
    if(num != 4){
        printf("First param should be 4!\n");
    }
    // TODO: handler should be called periodicly
}

void irq_set_enabled(uint num, bool enabled){
    if(num != 4){
        printf("First param should be 4!\n");
    }
    if(!enabled){
        printf("irq set enabled should be enabled!");
    }
}


#endif