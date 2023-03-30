/*
 * File: uart.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:20:17 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Thursday, 30th March 2023 5:55:30 pm
 * Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
 * -----
 * Copyright 2023 - 2023 B.J.G. van Netburg
 */

// #define MOK

#ifdef MOK
#ifndef UART_H
#define UART_H

#include "types.h"
#include <stdlib.h>

#define _REG_(x)
#define _u(x) x ## u
#define UART_UARTDMACR_OFFSET _u(0x40034000)
typedef struct {
    _REG_(UART_UARTDMACR_OFFSET) 
} uart_hw_t;
#define UART0_BASE _u(0x40034000)
typedef struct uart_inst uart_inst_t;
#define uart0_hw ((uart_hw_t *)UART0_BASE)
#define uart0 ((uart_inst_t *)uart0_hw) ///< Identifier for UART instance 0

typedef enum {
    UART_PARITY_NONE,
    UART_PARITY_EVEN,
    UART_PARITY_ODD
} uart_parity_t;


// uart_inst_t *const uart0;

uint uart_init(uart_inst_t *uart, uint baudrate);

void uart_set_format(uart_inst_t *uart, uint data_bits, uint stop_bits, uart_parity_t parity);

char uart_getc(uart_inst_t *uart);

//TODO: doesn't really belong here
bool stdio_init_all(void);

#endif // UART_H
#endif // MOK

