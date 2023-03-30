/*
 * File: uart.cpp
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:22:04 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 9:41:40 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */


#ifdef MOK
extern "C"{
    #include "hardware/uart.h"
    #include "stdio.h"
    #include <fcntl.h>
    #include <termios.h>
    #include <unistd.h>
    #include <stdlib.h>
}

#include <iostream>

uint uart_init(uart_inst_t *uart, uint baudrate){
    if(uart != uart0){
        printf("wrong uart pointer\n");
        return 0;
    }
    if(baudrate != 115200){
        printf("wrong baudrate, should be 115200\n");
        return 0;
    }
    return 1;
}

void uart_set_format(uart_inst_t *uart, uint data_bits, uint stop_bits, uart_parity_t parity){
    if(uart != uart0){
        printf("wrong uart pointer\n");
    }
}

char uart_getc(uart_inst_t *uart){
    // Open the serial port for reading
    int uart_fd = open("/dev/ptx/11", O_RDONLY | O_NOCTTY | O_NDELAY);
    if (uart_fd < 0) {
        std::cerr << "Failed to open UART device\n";
        return 30;
    }

    // Configure the serial port settings
    struct termios settings;
    tcgetattr(uart_fd, &settings);
    cfsetispeed(&settings, B9600);  // Set baud rate to 9600
    settings.c_cflag &= ~PARENB;    // Disable parity
    settings.c_cflag &= ~CSTOPB;    // Set one stop bit
    settings.c_cflag &= ~CSIZE;     // Clear data size bits
    settings.c_cflag |= CS8;        // Set data bits to 8
    settings.c_cflag &= ~CRTSCTS;   // Disable hardware flow control
    settings.c_iflag = 0;           // Disable input processing
    settings.c_oflag = 0;           // Disable output processing
    settings.c_lflag = 0;           // Disable line processing
    tcsetattr(uart_fd, TCSANOW, &settings);

    // Read bytes from the serial port
    char buf[3]; //TODO: maybe make buf smaller
    int bytes_read = 0;
    bytes_read = read(uart_fd, buf, sizeof(buf));
    while (true) {
        if (bytes_read > 0) {
            // Process the received data here
            return buf[0];
            // for (int i = 0; i < bytes_read; i++) {
            //     // std::cout << buf[i];
            // }
        }
    }

    // Close the serial port
    close(uart_fd);
    return 0;
}

bool stdio_init_all(void){
    return true;
}

#endif // MOK