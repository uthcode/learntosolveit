import logging

logger = logging.getLogger("simple_example")
logger.setLevel(logging.DEBUG)

ch = logging.StreamHandler()
ch.setLevel(logging.DEBUG)

formatter = logging.Formatter("%(asctime)s - %(name)s - %(levelname)s - %(message)s")
ch.setFormatter(formatter)

logger.addHandler(ch)

logger.debug("This is a debug message")
logger.info("This is a  info message")
logger.warning("This is a  warning message")
logger.error("This is a  error message")
logger.critical("This is a critical message.")
