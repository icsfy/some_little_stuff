#! /usr/bin/python3

import time

while True:
    receive = []
    transmit = []
    with open('/proc/net/dev') as f:
        f.readline()    # Inter-| Receive | Transmit
        f.readline()    # face |bytes packets errs drop...
        i = 0
        for line in f:
            s = line.split()
            receive.append(int(s[1]))
            transmit.append(int(s[9])) # s[1]: Receive, s[9]: Transmit
            i = i + 1
    time.sleep(1)
    print(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()))
    print('{:>10} {:>12} {:>12}'.format('interface', 'download', 'upload'))
    with open('/proc/net/dev') as f:
        f.readline()
        f.readline()
        i = 0
        for line in f:
            s = line.split()
            downSpeed = (int(s[1]) - receive[i])
            downSpeedText = 'B/s'
            if downSpeed > 1024:
                downSpeed = downSpeed / 1024
                if downSpeed > 1024:
                    downSpeed = downSpeed / 1024
                    downSpeedText = 'MB/s'
                else:
                    downSpeedText = 'KB/s'
            upSpeed = (int(s[9]) - transmit[i])
            upSpeedText = 'B/s'
            if upSpeed > 1024:
                upSpeed = upSpeed / 1024
                if upSpeed > 1024:
                    upSpeed = upSpeed / 1024
                    upSpeedText = 'MB/s'
                else:
                    upSpeedText = 'KB/s'
            print("{:>10} {:8.2f}{:>4} {:8.2f}{:>4}".format(s[0], float(downSpeed), downSpeedText, float(upSpeed), upSpeedText))
            i = i + 1
    print()

