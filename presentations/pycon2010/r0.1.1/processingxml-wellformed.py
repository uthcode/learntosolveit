#!/usr/bin/python
# Credit: Paul Prescod, Farhad Fouladi

from xml.sax.handler import ContentHandler
from xml.sax import make_parser
from glob import glob
import sys

def parsefile(filename):
    parser = make_parser()
    parser.setContentHandler(ContentHandler())
    parser.parse(filename)

for arg in sys.argv[1:]:
    for filename in glob(arg):
        try:
            parsefile(filename)
            print '%s is well-formed' % filename
        except Exception, e:
            print '%s is not well-formed' % filename
