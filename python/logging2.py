import glob
import logging
import logging.handlers

mylogger = logging.getLogger("toolserver")
mylogger.setLevel(logging.DEBUG)

FILENAME = "log2.txt"

handler = logging.handlers.RotatingFileHandler(FILENAME,
                                               maxBytes=20,
                                               backupCount=5)
mylogger.addHandler(handler)

for i in range(20):
    mylogger.debug(i)

files = glob.glob("%s.*" % FILENAME)

for f in files:
    print f
