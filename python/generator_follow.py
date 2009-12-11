import time

def follow(thefile):
    thefile.seek(0,2)
    while True:
        line = thefile.readline()
        if not line:
            time.sleep(0.1)
            continue
        yield line

logfile = open('/var/log/apache2/access.log')
for line in follow(logfile):
    print line,
