/*
 * File: time.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 3:23:16 pm
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 2:03:59 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK
#ifndef TIME_H
#define TIME_H

// #include "/usr/include/time.h"
#include "time.h"
#include "types.h"

/**
 * @brief 
 * Sleep for us amound of microseconds
 * @param us 
 * Microseconds to sleep
 */
void sleep_us(uint64_t us);

#endif // TIME_H
#endif // MOK
