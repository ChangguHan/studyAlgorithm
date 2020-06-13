
# 패키지 최소값, 각 줄 최소값 가지고와서 두개 구분해서 사면 될듯
# GA !!

N, M = map(int,input().split(" "))
pack = []
each = []
for i in range(M) :
    a,b = map(int, input().split(" "))
    pack.append(a)
    each.append(b)

# if(N%6 == 0) : packNeed = N/6
# else : packNeed = int(N/6) + 1

# 6개먼저 비교해보자 >> pack 더 싸면, pack 먼저 쓸고,
# 나머지 남은것 비교해서 pack 더 싸면 pack

price = 0
if(min(pack) <= min(each) * 6) :
    price += int(N/6) * min(pack)
#     남은것
    if( (N%6)*min(each) < min(pack)) :
        price += (N%6) * min(each)
    else : price += min(pack)
else :
    price = min(each) * N



print(price)