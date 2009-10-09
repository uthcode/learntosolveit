#!/usr/bin/python
import sys
import optparse
import urllib

RFC_BASE = 'http://www.ietf.org/rfc/rfc'

parser = optparse.OptionParser()
parser.add_option('-r','--rfc',
                  dest='rfc_name',
                 )
options, remainder = parser.parse_args()

RFC_NAME = options.rfc_name + '.txt'

RFC = RFC_BASE + RFC_NAME

urllib.urlretrieve(RFC,filename=RFC_NAME)
print 'Here you have:', RFC_NAME
