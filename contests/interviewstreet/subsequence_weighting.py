# http://pastebin.com/9igvHsdq

C = int(raw_input())
for tc in range(C):
    raw_input()
    a = map(int,raw_input().split())
    w = map(int,raw_input().split())
    A = zip(a,w)
    inttoscore = [[0,0]]
    # binary search our way to the weight.

    for i in range(len(a)):
        left, right = 0, len(inttoscore)-1
        while right - left > 1:
            average = int((left+right)/2)

            if a[i] > inttoscore[average][0]:
                left = average
            else:
                right = average
        if a[i] < inttoscore[left][0]:
            place = left
        elif a[i] < inttoscore[right][0]:
            place = right
        else:
            place = right + 1

        while place > 0 and a[i] == inttoscore[place-1][0]:
            place -= 1

        inttoscore.insert(place, [a[i], w[i] + inttoscore[place-1][1]])

        while place+1 < len(inttoscore) and inttoscore[place][1] >= inttoscore[place+1][1]:
            inttoscore.pop(place+1)

    print inttoscore[-1][1]
