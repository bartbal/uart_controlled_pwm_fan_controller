/*
 * File: uartInterface.hpp
 * Project: atp humidity control
 * File Created: Tuesday, 28th March 2023 4:30:12 pm
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Tuesday, 28th March 2023 4:39:02 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

// config uart
#define UART_ID uart0
#define BAUD_RATE 115200
#define UART_TX_PIN 0
#define UART_RX_PIN 1
#define DATA_BITS 8
#define STOP_BITS 1

class UartInterface{
private:
    
public:

    /**
     * @brief 
     * Setup all uart stuff for communication
     */
    static void setupUart();
};
