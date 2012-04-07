import re
from google.appengine.ext import webapp
import datetime

register = webapp.template.create_template_register()

def splitdate(value):
    return value[0:2] + '-' + value[2:4] + '-' + value[4:]

def removesecs(value):
    if value:
        return value.strftime('%H:%M')
    default = datetime.time()
    default = default.strftime('%H:%M')
    return default

register.filter(splitdate)
register.filter(removesecs)
