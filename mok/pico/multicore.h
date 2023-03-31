/*
 * File: multicore.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:19:22 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 12:29:00 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK
#ifndef MULTICORE_H
#define MULTICORE_H

/**
 * @brief 
 * Use this in the loop of the threaded task to check when to stop the thread.
 * @return bool 
 * True if thread has to stop
 */
bool multicore_thread_exit();

/**
 * @brief 
 * Use this in the main loop to check when to exit.
 * @return bool
 * True if main loop has to stop
 */
bool multicore_main_exit();

/**
 * @brief 
 * Use this method in sub loops of any thread loops or the main 
 * loop to check if the loop has to stop.
 * @return bool
 * True if the loop has to stop
 */
bool multicore_subs_exit();

/**
 * @brief 
 * sdk mok method for launching core 1.
 * @details
 * This method starts a new thread instead of a core. 
 * Will also catch ctrl+c input to stop threads. For that to work 
 * properly make sure to use the multicore exit methods. 
 * @param entry 
 * Function pointer to a funtion to run in a seperate "core" 
 * which in this case is actualy a thread.
 */
void multicore_launch_core1(void (*entry)(void));

/**
 * @brief 
 * This method gets called in the main loop.
 * This mok version just returns.
 */
void tight_loop_contents();

#endif // MULTICORE_H
#endif // MOK