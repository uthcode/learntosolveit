import logging
FILENAME = 'logfile.txt'
logging.basicConfig(filename=FILENAME, level=logging.DEBUG, filemode='w')
logging.debug("This message will go into the logfile")
