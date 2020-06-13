# 경우의수 반복되는 문제이므로 DP
# 해당 수를 1,2,3 빼서 가각ㄱ의 값으로 더하면 됨
# 그럼 중복되는 경우는 없을까? >> 없어

bd = []
for i in range(int(input())) :
    bd.append(int(input()))

m = [0,1,2,4]
if (max(bd) >3) :
    for i in range(4,max(bd)+1) :
        mv = m[i-1] + m[i-2] + m[i-3]
        m.append(mv)

for i in bd :
    print(m[i])


# 마지막에 적은수도 생각해주기