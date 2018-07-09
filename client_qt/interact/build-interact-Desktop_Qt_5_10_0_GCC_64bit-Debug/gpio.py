#!/usr/bin/env python

import mraa
import time
import sys


def open_door(target):
    motor = mraa.Gpio(10)
    sensor = mraa.Gpio(8)
# for our sensor, 1 means empty, 0 means something there
    lock = mraa.Gpio(12)
    motor.dir(mraa.DIR_OUT)
    sensor.dir(mraa.DIR_IN)
    lock.dir(mraa.DIR_OUT)
    def tick():
        motor.write(1)
        time.sleep(0.002)
        motor.write(0)
        time.sleep(0.002)

    durcount = 0
    state = 0
# 0 = init, 1 = at the first divide, 2 = now is at the first space after the first divide
    prestate = 0

    durcount = 230
### this part is used to locate start position
    state = 0
# 0 = finding next divide, 1 = count the length of the divide, 2 = end of the divide

    print('gpio stage0')

    while True:
        if sensor.read() == 1:
            break
        tick()
    print('gpio stage1')

    state = 0

    while True:
        nowstate = sensor.read()
        if(0 == state):
            count = 0
            if(0 == nowstate):
                state = 1
        if(1 == state):
            count += 1
            if(1 == nowstate):
                state = 2
        if(2 == state):
            if(count > int(durcount / 2)):
                state = 3
            else:
                state = 0
        if(state == 3):
            break;
        tick()


    print('gpio stage2')
### this part is used to go to the location
    state = 0
    count = 0
# 0 = end of a divide, 1 = empty space, 2 = at a divide
    while True:
        nowstate = sensor.read()
        if(0 == state):
            if(count == target):
                state = 3
            else:
                state = 1
        if(1 == state):
            if(0 == nowstate):
                state = 2
                count += 1
        if(2 == state):
            if(count == 19):
                state = 0
            elif(1 == nowstate):
                state = 0
        if(state == 3):
            break;
        tick()
    print('after wheel')
    lock.write(1)
    time.sleep(0.5)
    lock.write(0)
    time.sleep(0.5)
    print('after lock')

if __name__ == '__main__':
    open_door(sys.argv[1])
