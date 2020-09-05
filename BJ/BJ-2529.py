# # 순열을 구해서 각 가방에 넣을 수 있는지 확인
#
# # 순열부터 구하자
#
jewelN,bagN = map(int, input().split(" "))
jW = []
jV = []
for i in range(jewelN) :
    moo,val = map(int,input().split(" "))
    jW.append(moo)
    jV.append(val)

bag = []
for i in range(bagN) :
    bag.append(int(input()))

print(jW, jV)
print(bag)
# 근데 가방을 다 채우라는 보장이 없지
# 개수를 하나씩 빼서도 순열을 구해야돼
result = []
def permu(pick,num) :
    if(len(pick) == num) :
        bu = pick[:]
        result.append(bu)
        return

    for i in range(len(jW)) :
        if(i not in pick) :
            pick.append(i)
            permu(pick,num)
            pick.pop()




for i in range(len(bag)+1 ) :
    permu([], i)
maxv = 0
for i in result :
    ev = 0
    for j in range(len(i)) :
        if( )
        if(jW[i[j]] < bag[j]) :
            ev += jV[j]
    maxv = max(maxv, ev)

print(maxv)