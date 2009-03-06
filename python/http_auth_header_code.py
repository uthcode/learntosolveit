import urllib2

if __name__ == '__main__':
    theurl = "http://mail.google.com/mail/#inbox"
    req = urllib2.Request(theurl)
    try:
        handle = urllib2.urlopen(req)
        print 'here'
    except IOError, e:
        if hasattr(e, 'code'):
            if e.code != 401:
                print 'Its some other error!'
                print e.code
            else:
                print e.headers
                print e.headers['www-authenticate']

    print handle.read()

