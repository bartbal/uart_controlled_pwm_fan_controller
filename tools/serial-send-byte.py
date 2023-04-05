'''
File: serial-send-byte.py
Project: atp humidity control
File Created: Thursday, 30th March 2023 10:15:15 am
Author: Bart van Netburg (bartvannetburg@hotmail.com)
-----
Last Modified: Wednesday, 5th April 2023 7:45:43 pm
Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
-----
Copyright 2023 - 2023 B.J.G. van Netburg
'''

#!/usr/bin/python3

import sys
import serial

ser = serial.Serial(sys.argv[1], sys.argv[2], serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE)  # open serial port
print(ser.name)         # check which port was really used

values = bytearray([int(sys.argv[3])])
ser.write(values)

ser.close()             # close port