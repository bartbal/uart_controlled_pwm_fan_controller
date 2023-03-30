/*
 * File: multicore.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:21:34 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 9:39:26 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "pico/multicore.h"
}
// #include <stdlib.h>
#include <thread>


void multicore_launch_core1(void (*entry)(void)){
    std::thread thread_obj(entry);
}

// void tight_loop_contents(){
//     return;
// }

#endif // MOK