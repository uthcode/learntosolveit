#!/usr/bin/env python2.6
from xml.etree.ElementTree import ElementTree
tree = ElementTree()
tree.parse('index.xhtml')
p = tree.find('body/p')
print p
links = p.getiterator('a')
print links
for i in links:
    i.attrib['target'] = "blank"
tree.write("output.xhtml")
