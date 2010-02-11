import signal
import subprocess

class Alarm(Exception):
    pass

def alarm_handler(signum, frame):
    raise Alarm

signal.signal(signal.SIGALRM, alarm_handler)
signal.alarm(5)  # 5 seconds
proc = subprocess.Popen(['sleep','10'],stdout=subprocess.PIPE, stderr=subprocess.PIPE)
try:
    stdoutdata, stderrdata = proc.communicate()
    signal.alarm(0)  # reset the alarm
except Alarm:
    print "Oops, taking too long!"

