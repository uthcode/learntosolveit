no_of_tests = int(raw_input())
for test in range(no_of_tests):
    no_elements_in_vec = input()
    vec1=[]
    vec2=[]
    in1 = raw_input()
    in2 = raw_input()
    list1 = in1.split(' ')
    list2 = in2.split(' ')
    for element in range(no_elements_in_vec):
        vec1.append(int(list1[element]))
    for element in range(no_elements_in_vec):
        vec2.append(int(list2[element]))
    sum = 0
    vec1.sort()
    vec2.sort()
    vec2.reverse()
    for x,y in zip(vec1,vec2):
        sum = sum + x*y
    print 'Case #%d: %d' % (test+1, sum)
