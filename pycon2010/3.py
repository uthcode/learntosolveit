import re
astring = 'A pound of salt will not sweeten a single cup of tea.'
revwords = re.split(r'(\s+)',astring)
revwords.reverse()
revwords = ''.join(revwords)
print revwords

