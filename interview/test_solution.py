tc = 1
N = int(raw_input())
while N:
    content = []
    for line in range(N):
        content.append(raw_input())
    input_html = "".join(content)
    print "Case #%d: %s" % (tc, input_html)
    tc += 1
    N = int(raw_input())

