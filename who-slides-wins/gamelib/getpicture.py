#!/usr/bin/python
# -*- coding: utf-8 -*-
# vim: ts=4 sw=4 et ai ft=python nowrap

import os
import re
import urllib2

class DesktopWallpaper:
    """Comment."""
    def __init__(self, proxy=None):
        """Comment"""

        if proxy:
            PROXY_IP = proxy['IP']
            PROXY_USER = proxy['USER']
            PROXY_PASSWORD = proxy['PASSWORD']
            PROXY_PORT = proxy['PORT']

            proxy_url = 'http://' + PROXY_USER + ':' + PROXY_PASSWORD + \
                '@' + PROXY_IP + ':' + PROXY_PORT
            proxy_support = urllib2.ProxyHandler({'http': proxy_url})
            opener = urllib2.build_opener(proxy_support, urllib2.HTTPHandler)
            urllib2.install_opener(opener)

    def readnatgeo(self):
        """Comment"""

        SITEURL = 'http://www.nationalgeographic.com/photography/today/'
        req = urllib2.Request(SITEURL)
        data = urllib2.urlopen(req).read()

        p = re.compile('/photography/wallpaper/.*\\.html')
        m = p.search(data)

        WP_URL = 'http://photography.nationalgeographic.com' + str(m.group())
        req = urllib2.Request(WP_URL)
        data = urllib2.urlopen(req)
        content = data.read()
        return content

    def lookforwallpaper(self, content):
        """Comment"""

        lookfor = re.compile('href="(\\S*-lw\\.jpg)')
        picture = lookfor.search(content).group(1)
        wallpaper = 'http://photography.nationalgeographic.com' + str(picture)
        return wallpaper

    def downloadjpg(self, wallpaper):
        """Comment"""

        req = urllib2.Request(wallpaper)
        data = urllib2.urlopen(req).read()
        jpgimgfile = 'picture.jpg'
        imgfile = open(jpgimgfile, 'wb')
        imgfile.write(data)
        imgfile.close()
        path = os.getcwd() + os.sep + jpgimgfile

def getpicture(proxy=None):
    """Run"""
    wallp = DesktopWallpaper(proxy)
    content = wallp.readnatgeo()
    wallpaper = wallp.lookforwallpaper(content)
    wallp.downloadjpg(wallpaper)

if __name__ == '__main__':
    getpicture()
