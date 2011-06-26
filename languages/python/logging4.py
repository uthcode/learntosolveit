import logging

logger1 = logging.getLogger('package1.module1')
logger2 = logging.getLogger('package1.module2')

logging.basicConfig(level=logging.WARNING)

logger1.warning('This is a warning message')
logger2.warning('This is a another warning message')

