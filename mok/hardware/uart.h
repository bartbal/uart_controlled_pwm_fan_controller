/*
 * File: uart.h
 * Project: atp humidity control
 * File Created: Thursday, 30th March 2023 10:20:17 am
 * Author: Bart van Netburg (bartvannetburg@hotmail.com)
 * -----
 * Last Modified: Friday, 31st March 2023 12:37:18 pm
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

// This is for moking the uart0 defenition
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

// declare uart_parity_t type
typedef enum {
    UART_PARITY_NONE,
    UART_PARITY_EVEN,
    UART_PARITY_ODD
} uart_parity_t;

/**
 * @brief 
 * Mok initialize the uart. This will just verify the given params
 * @param uart 
 * Pointer to uart0
 * @param baudrate 
 * The baud rate as uint
 * @return 
 * 1 if succes 0 if not succesful
 */
uint uart_init(uart_inst_t *uart, uint baudrate);

/**
 * @brief 
 * Mok function for setting the format. This will just verify the given params
 * @param uart 
 * @param data_bits 
 * @param stop_bits 
 * @param parity 
 */
void uart_set_format(uart_inst_t *uart, uint data_bits, uint stop_bits, uart_parity_t parity);

/**
 * @brief 
 * Mok uart_getc. Gets a character from uart device. Defice is defined by AURT_DEVICE constant
 * @param uart 
 * Pointer to uart0
 * @return 
 * The byte that was read from the uart
 */
char uart_getc(uart_inst_t *uart);

/**
 * @brief 
 * Mok initialize stdio initialization.
 * Simply always returns true.
 * @return true 
 */
bool stdio_init_all(void);

#endif // UART_H
#endif // MOK

