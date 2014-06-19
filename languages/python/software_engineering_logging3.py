import logging
import sys

LEVELS = {'debug': logging.DEBUG,
        'info': logging.INFO,
        'warning': logging.WARNING,
        'error': logging.ERROR,
        'critical': logging.CRITICAL
        }

if len(sys.argv) > 1:
    log_level = sys.argv[1]
    level = LEVELS.get(log_level, logging.NOTSET)
    logging.basicConfig(level=level)

    logging.debug('This is a debug message')
    logging.info('This is a  info message')
    logging.warning('This is a warning message.')
    logging.error('This is a error message.')
    logging.critical('This is a critical message.')
