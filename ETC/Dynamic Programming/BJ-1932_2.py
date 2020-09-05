# GA로 각각 칸만다 해도될듯
# DP로 해보기
# Sn,l = bn,l + max(Sn-1,l , Sn-1,l+1)

N = int(input())
bd = []
m = []
for i in range(N) :
    bd.append(list(map(int, input().split(" "))))
    m.append([])
m[0] = bd[0]
for i in range(1,N) :
    bdLen = len(bd[i])
    for j in range(bdLen) :
        if(j==0) : mv = m[i-1][j]
        elif (j==bdLen-1) : mv = m[i-1][j-1]
        else : mv = max(m[i-1][j],m[i-1][j-1])
        m[i].append(bd[i][j] + mv)

print(max(m[N-1]))