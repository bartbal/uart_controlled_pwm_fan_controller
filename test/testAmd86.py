'''
File: testAmd86.py
Project: atp humidity control
File Created: Wednesday, 5th April 2023 5:57:03 pm
Author: Bart van Netburg (bartvannetburg@hotmail.com)
-----
Last Modified: Wednesday, 5th April 2023 8:51:38 pm
Modified By: Bart van Netburg (bartvannetburg@hotmail.com>)
-----
Copyright 2023 - 2023 B.J.G. van Netburg
'''
import subprocess
import serial
import threading
import time
import os
import signal

running : bool = True
testValueList : list = [90, 60, 37, 11, 57]
evaluateList : list = []

def sendFanSpeed(newSpeed : int):
    ser = serial.Serial('/dev/pts/4', 115200, serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE)  # open serial port
    values = bytearray([newSpeed])
    ser.write(values)
    ser.close()

def writeLoop():
    for value in testValueList:
        time.sleep(1)
        sendFanSpeed(value)

process = subprocess.Popen(["./pwm_controller"], stdout=subprocess.PIPE)
print("PID: "+str(process.pid))
writeTask = threading.Thread(target=writeLoop)
writeTask.start()

try:
    while running:
        if len(evaluateList) >= len(testValueList):
            break
        output = process.stdout.readline()
        if output == b'' and process.poll() is not None:
            break
        if output:
            line : str = output.strip().decode('utf-8')
            index1 : int = line.find("speed: ")+7
            index2 : int = line[index1:].find("%")
            if index1 == -1 or index2 == -1:
                continue
            index2 += index1
            fanSpeed : int = int(line[index1:index2])
            print(fanSpeed)
            evaluateList.append(fanSpeed)


    if evaluateList == testValueList:
        print("test SUCCESS!")
    else:
        print("test FAIL!")
        print(evaluateList)
        print(testValueList)

except KeyboardInterrupt:
    pass
except Exception as ex:
    os.killpg(os.getpgid(process.pid), signal.SIGTERM)
    raise ex

print("Done, stopping process")
os.killpg(os.getpgid(process.pid), signal.SIGTERM)