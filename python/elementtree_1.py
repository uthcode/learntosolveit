from xml.etree import ElementTree as ET

with open('output') as f:
    content = f.read()

xmlcontent = ET.XML(content)
print xmlcontent.tag
print dir(xmlcontent)
#root = xmlcontent.getroot()
#print root
for elem in xmlcontent.getchildren():
    print elem.tag
