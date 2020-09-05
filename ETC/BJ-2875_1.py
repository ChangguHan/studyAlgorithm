import math
# 하나는 알고리즘으로
# 하나는 정량적으로 풀어보기
a,b,c = input().split(' ')
woman = int(a)
man = int(b)
needed = int(c)
oldTeam = 0
team = 0

for i in range(len(needed)+1) :
    womanNew = woman-i
    manNew = man-needed+i

    if(int(womanNew/2) >= manNew) :team =manNew
    else : team = int(womanNew)

    if(oldTeam < team) : oldTeam = team
print(oldTeam)
    