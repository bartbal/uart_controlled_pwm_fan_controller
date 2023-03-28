#!/usr/bin/python3

import sys
import serial
"""
@brief
Just a little script to send a byte over uart.
Very usefull for testing
"""
ser = serial.Serial('/dev/ttyACM0', 115200, serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE)  # open serial port
print(ser.name)         # check which port was really used

values = bytearray([int(sys.argv[1])])
ser.write(values)

ser.close()             # close port
