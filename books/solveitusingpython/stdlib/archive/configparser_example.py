from ConfigParser import ConfigParser
import os

filename = 'config.ini'
config = ConfigParser()
config.read([filename])

url = config.get('section','url')
print url
