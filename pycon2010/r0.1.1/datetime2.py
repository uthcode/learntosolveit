# Scheduling Commands.
# Credit: Peter Cogolo

import time
import os
import sys
import sched

schedule = sched.scheduler(time.time, time.sleep)

def perform_command(cmd, inc):
    schedule.enter(inc, 0, perform_command, (cmd, inc))
    os.system(cmd)

def main(cmd, inc=60):
    schedule.enter(0, 0, perform_command, (cmd, inc))
    schedule.run()

if __name__ == '__main__':
    numargs = len(sys.argv) - 1
    if numargs < 1 or numargs > 2:
        print "usage: " + sys.argv[0] + " command [seconds_delay]"
        sys.exit(1)

    cmd = sys.argv[1]
    if numargs < 3:
        main(cmd)
    else:
        inc = int(sys.argv[2])
        main(cmd, inc)
