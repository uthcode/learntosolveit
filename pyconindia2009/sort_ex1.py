import re

li=[
'my283.jpg',
'my23i.jpg',
'web7-s.jpg',
'fris88large.jpg',
]

def compare_nums(x, y):
    def getnum(str): return float(re.findall(r'\d+',str)[0])
    return cmp(getnum(x), getnum(y))

li.sort(cmp=compare_nums)
print li 
