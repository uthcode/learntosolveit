# Problem
# 
# You are given two vectors v1=(x1,x2,...,xn) and v2=(y1,y2,...,yn). The scalar
# product of these vectors is a single number, calculated as x1y1+x2y2+...+xnyn.
# 
# Suppose you are allowed to permute the coordinates of each vector as you wish.
# Choose two permutations such that the scalar product of your two new vectors is
# the smallest possible, and output that minimum scalar product.
# 
# Input
# The first line of the input file contains integer number T - the number of test
# cases. For each test case, the first line contains integer number n. The next
# two lines contain n integers each, giving the coordinates of v1 and v2
# respectively.
# 
# Output
# 
# For each test case, output a line
# 
# Case #X: Y
# 
# where X is the test case number, starting from 1, and Y is the minimum scalar
# product of all permutations of the two given vectors.
# 
# Limits
# 
# Small dataset
# 
# T = 1000
# 1 ≤ n ≤ 8
# -1000 ≤ xi, yi ≤ 1000
# 
# Large dataset
# 
# T = 10
# 100 ≤ n ≤ 800
# -100000 ≤ xi, yi ≤ 100000
# 
# Sample
# 
# Input
#     
# Output
#  
# 2
# 3
# 1 3 -5
# -2 4 1
# 5
# 1 2 3 4 5
# 1 0 1 0 1
# 
# Case #1: -25
# Case #2: 6

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
