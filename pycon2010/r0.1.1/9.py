#-*- coding:utf-8 -*-
german_ae = unicode('\xc3\xa4','utf8')
sentence = "this is a " + german_ae
print sentence
sentence2 = 'easy!'
para = ". ".join([sentence, sentence2])
bytestr = german_ae.decode('utf8')
print bytestr
