/*
 * File: uartInterface.cpp
 * Project: atp humidity control
 * File Created: Tuesday, 28th March 2023 4:31:19 pm
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 1:16:38 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

extern "C"{
    #include "stdio.h"
    #include "hardware/gpio.h"
    #include "pico/stdlib.h"
    #include "hardware/uart.h"
}

#include "uartInterface.hpp"

void UartInterface::setupUart(){
    // init uart with correct baud rate
    uart_init(UART_ID, BAUD_RATE);
    // set rx and tx pin to uart function
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    // configure the data format
    uart_set_format(UART_ID, DATA_BITS, STOP_BITS, UART_PARITY_NONE);
    // init the std::cout and printf stuff to work with this uart
    stdio_init_all();
}