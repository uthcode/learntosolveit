# -*- coding: utf8 -*-
import cStringIO as StringIO

from twisted.internet import reactor
from twisted.web.client import getPage
from twisted.python.util import println
from lxml import etree

def parseHtml(html):
    parser = etree.HTMLParser(encoding='utf8')
    tree = etree.parse(StringIO.StringIO(html), parser)
    return tree

def extractTitle(tree):
    titleText = unicode(tree.xpath("//title/text()")[0])
    return titleText

d = getPage('http://www.google.com')
d.addCallback(parseHtml)
d.addCallback(extractTitle)
d.addBoth(println)

reactor.run()
