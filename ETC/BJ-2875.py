import math
# 하나는 알고리즘으로
# 하나는 정량적으로 풀어보기
a,b,c = input().split(' ')
woman = int(a)
man = int(b)
needed = int(c)

# 잉여인력 몇명인지 구하기
# 잉여인력 보다 필요인력이 많은경우
# 3으로 나눠 올림한 팀만큼 차감
if(woman/2 > man) :
    plus = woman-man*2
    team = man
else :
    if woman%2 == 0 : plus = man-woman/2
    else : plus=man-int(woman/2) +1
    team = int(woman/2)

if(needed > plus) :

    team -= math.ceil((needed-plus)/3)
print(team)