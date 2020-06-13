
# 연속으로 3잔을 마시지 않는 경우
# GA 불가
# DP : 연속 0잔, 1잔, 2잔의 경우로 나눠서 하면 되지 않을까
# Sn,0 = max(Sn-1,0,Sn-1,1,Sn-1,2)
# Sn,1 = max(Sn-1,0)
# Sn,2 = max(Sn-1,1)


N = int(input())
bd = []
for i in range(N) : bd.append(int(input()))

m = []
for i in range(N) : m.append([])

m[0] = [0,bd[0],bd[0]]

for i in range(1, N) :
    m[i].append(max(m[i-1][0],m[i-1][1],m[i-1][2]))
    m[i].append(m[i - 1][0] + bd[i])
    m[i].append(m[i - 1][1] + bd[i])

print(max(m[N-1]))