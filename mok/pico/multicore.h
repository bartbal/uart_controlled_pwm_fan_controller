/*
 * File: multicore.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:19:22 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 3:14:57 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK
#ifndef MULTICORE_H
#define MULTICORE_H

void multicore_launch_core1(void (*entry)(void));

// FIXME: not a method of multicore but didn't know where else to put it for now
static  void tight_loop_contents(){return;};

#endif // MULTICORE_H
#endif // MOK