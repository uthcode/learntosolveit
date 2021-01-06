import urllib.request, urllib.error, urllib.parse

if __name__ == '__main__':
    theurl = "http://mail.google.com/mail/#inbox"
    req = urllib.request.Request(theurl)
    try:
        handle = urllib.request.urlopen(req)
        print('here')
    except IOError as e:
        if hasattr(e, 'code'):
            if e.code != 401:
                print('Its some other error!')
                print(e.code)
            else:
                print(e.headers)
                print(e.headers['www-authenticate'])

    print(handle.read())

