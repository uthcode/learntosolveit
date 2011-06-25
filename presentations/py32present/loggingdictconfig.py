import logging
import json, logging.config
import logging
logger = logging.getLogger('myapp')
with open('conf.json', 'r') as f:
        conf = json.load(f)
print(conf)
logging.config.dictConfig(conf)
logging.info("Transaction completed normally")
logging.critical("Abnormal termination")
