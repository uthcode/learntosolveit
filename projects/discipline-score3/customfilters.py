import re
from google.appengine.ext import webapp

register = webapp.template.create_template_register()

def splitdate(value):
    return value[0:2] + '-' + value[2:4] + '-' + value[4:]

register.filter(splitdate)
