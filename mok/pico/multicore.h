/*
 * File: multicore.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:19:22 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 11:48:37 am
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK
#ifndef MULTICORE_H
#define MULTICORE_H

bool multicore_thread_exit();

bool multicore_main_exit();

bool multicore_subs_exit();

void multicore_launch_core1(void (*entry)(void));

// FIXME: not a method of multicore but didn't know where else to put it for now
void tight_loop_contents();

#endif // MULTICORE_H
#endif // MOK