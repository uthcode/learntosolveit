import ConfigParser
import string

config = ConfigParser.ConfigParser()
config.read('config1.ini')

for section in config.sections():
    print string.upper(section)
    for option in config.options(section):
        print " ", string.capitalize(option), " = ", config.get(section, option)
