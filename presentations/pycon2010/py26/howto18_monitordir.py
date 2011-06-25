#!/usr/bin/env python2.6

import os
import time

def read_file(filename):
    fh = open(filename)
    contents = fh.read()
    fh.close()
    return contents

def getaccesstime(dir,filename):
    return os.stat(os.path.join(dir,filename)).st_atime

def monitor(directory):
    dirloc = os.path.join(os.getcwd(), directory)
    accessedcontents = os.listdir(dirloc)
    accesstimehash = {}

    for eachfile in accessedcontents:
        accesstimehash[eachfile] = getaccesstime(dirloc,eachfile)

    while True:
        dircontents = os.listdir(dirloc)
        if not (set(dircontents) == set(accessedcontents)):
            for eachfile in dircontents:
                if not eachfile in accessedcontents:
                    print 'newfile:',eachfile
                    print read_file(os.path.join(dirloc,eachfile))
                    accessedcontents.append(eachfile)
                    accesstimehash[eachfile] = getaccesstime(dirloc,eachfile)

        for eachfile in accessedcontents:
            if ( os.stat(os.path.join(dirloc,eachfile)).st_atime >
                accesstimehash[eachfile]):
                print 'updated file:', eachfile
                print read_file(os.path.join(dirloc,eachfile))
                accesstimehash[eachfile] = getaccesstime(dirloc, eachfile)

monitor('logsdir')
