import anydbm

db = anydbm.open('cache','c')

db['www.python.org'] = 'Python website'
db['www.bbc.com'] = 'BBC'

for k, v in db.iteritems():
    print k, '\t', v

db.close()
