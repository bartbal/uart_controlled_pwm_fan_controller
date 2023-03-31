/*
 * File: multicore.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:21:34 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 12:27:38 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

#ifdef MOK

extern "C"{
    #include "pico/multicore.h"
    #include <cstring>
    #include <signal.h>
    #include "pico/time.h"
}

#include <iostream>
#include <thread>
#include <atomic>

static std::atomic<bool> quit(false);
static std::atomic<bool> wait(true);

/**
 * @brief 
 * Function to call when ctrl+c is presed.
 * Assigned in the multicore_launch_core1 function
 */
static void got_signal(int){
    quit.store(true);
}

void multicore_launch_core1(void (*entry)(void)){
    // catch when ctrl+c is pressed and call got_signal method
    struct sigaction sa;
    memset( &sa, 0, sizeof(sa) );
    sa.sa_handler = got_signal;
    sigfillset(&sa.sa_mask);
    sigaction(SIGINT,&sa,NULL);

    // launch thread and detach
    std::thread thread_obj(entry);
    thread_obj.detach();
}

bool multicore_main_exit(){
    if(quit.load()){
        std::cout << "waiting for thread\n";
        while(wait.load()){
            sleep_us(500000);
        }
        std::cout << "ending main\n";
        return true;
    }
    return false;
}

bool multicore_subs_exit(){
    if(quit.load()){
        std::cout << "ending sub\n";
        return true;
    }
    return false;
}

bool multicore_thread_exit(){
    if(quit.load()){
        std::cout << "ending thread\n";
        wait.store(false);
        return true;
    }
    return false;
}

void tight_loop_contents(){
    return;
}

#endif // MOK