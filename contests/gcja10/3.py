N = int(raw_input())
letters = {
        'a':'2',
        'b':'22',
        'c':'222',
        'd':'3',
        'e':'33',
        'f':'333',
        'g':'4',
        'h':'44',
        'i':'444',
        'j':'5',
        'k':'55',
        'l':'555',
        'm':'6',
        'n':'66',
        'o':'666',
        'p':'7',
        'q':'77',
        'r':'777',
        's':'7777',
        't':'8',
        'u':'88',
        'v':'888',
        'w':'9',
        'x':'99',
        'y':'999',
        'z':'9999',
        ' ':'0'
        }
i = 1
for tc in range(N):
    text = raw_input()
    res = ''
    for c in text:
        if len(res) > 1 and letters[c][0] != res[-1]:
            res = res + letters[c]
        else:
            res = res + ' ' + letters[c]
    print 'Case #%d:%s' % (i,res)
    i += 1
