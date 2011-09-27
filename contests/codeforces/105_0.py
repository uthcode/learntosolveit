# Transmigration

n, m, k = map(float, raw_input().split())

n = int(n)
m = int(m)

newskills = []
oldskills = []

for i in range(n):
    skill, rating = raw_input().split()
    rating = int(rating)
    rating = int(rating * k)
    if rating > 100:
        newskills.append((skill, rating))
        oldskills.append(skill)

for i in range(m):
    skill = raw_input()
    if skill not in oldskills:
        newskills.append((skill,0))

newskills.sort(key=lambda x: x[0])

print len(newskills)
for (skill, rating) in newskills:
    print skill, rating
