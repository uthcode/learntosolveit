#-*- coding:utf-8 -*-
# example of convertibility

http://code.activestate.com/recipes/361742/

german_ae = unicode('\xc3\xa4','utf8')
print german_ae
bytestr = german_ae.encode('utf8')
print map(hex,map(ord,bytestr))
