from cStringIO import StringIO

def scanner(fileobject, linehandler):
    for line in fileobject:
        linehandler(line)


def firstword(line): print line.split()[0]
string = StringIO('one\ntwo xxx\nthree\n')
scanner(string, firstword)
