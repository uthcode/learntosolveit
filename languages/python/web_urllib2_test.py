import urllib2


class FixedPasswordMgr:
    def __init__(self, user, password):
        self.user = user
        self.password = password

    def add_password(self, realm, uri, user, passwd):
        pass

    def find_user_password(self, realm, authuri):
        print 'auth: ' + authuri + ' ' + self.user
        return self.user, self.password


authhandler = urllib2.HTTPDigestAuthHandler(FixedPasswordMgr('phoe6', 'xxxxx'))

opener = urllib2.build_opener(authhandler)
urllib2.install_opener(opener)

for user in ['shortcipher', 'numberland', 'adrian2084', 'rocketjon', 'si1entdave', 'nightshade37']:
    url = 'http://' + user + '.livejournal.com/data/atom?auth=digest'
    pagehandle = urllib2.urlopen(url)
    print 'ok ' + user
