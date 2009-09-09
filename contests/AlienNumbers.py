N = int(raw_input())
datasets = []
resultset = []
for dataset in range(N):
    datasets.append(raw_input())

for each in datasets:
    alien_number, source_language, target_language = each.split()
    s_base = len(source_language)
    t_base = len(target_language)
    s_dict = {}
    for i,v in enumerate(source_language):
        s_dict[v] = i
    t_dict = {}
    for i,v in enumerate(target_language):
        t_dict[i] = v
    svalue = 0
    for i,ch in enumerate(reversed(alien_number)):
        svalue = svalue + (s_dict[ch] * pow(s_base, i))
    tvalue = ''
    while (svalue >= t_base):
        svalue,remainder = divmod(svalue,t_base)
        tvalue = tvalue + t_dict[remainder]
    tvalue = tvalue + t_dict[svalue]
    resultset.append(tvalue[::-1])

for i,result in enumerate(resultset):
    print 'Case #%d: %s' % (i+1,result)
