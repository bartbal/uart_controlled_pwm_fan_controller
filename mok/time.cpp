/*
 * File: time.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 3:24:46 pm
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 6:13:38 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "pico/time.h"
}
// #include <chrono>
// #include <thread>

void sleep_us(uint64_t us){
    // std::this_thread::sleep_for(std::chrono::milliseconds(us));
}

#endif