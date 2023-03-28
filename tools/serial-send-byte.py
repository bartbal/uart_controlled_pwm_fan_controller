#!/usr/bin/python3

import sys
import serial

# print(sys.argv)
# ser = serial.Serial(sys.argv[1], sys.argv[2])  # open serial port
ser = serial.Serial('/dev/ttyACM0', 115200, serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE)  # open serial port
print(ser.name)         # check which port was really used

values = bytearray([int(sys.argv[1])])
ser.write(values)

# command = b'\FF' # 'Hello' string in hex
# ser.write(command)

ser.close()             # close port
