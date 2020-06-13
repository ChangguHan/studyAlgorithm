
# GA : N번째 색이 낮은게 항상 최선이 아님
# N+1 색이 더 낮은게 최선이 될수 있음

# 각 경우의 수로해서
# Sn,0 = min(Sn-1,1 , Sn-1,2)
# Sn,1 = min(Sn-1,0 , Sn-1,2)
# Sn, 2 = min(Sn-1,0, Sn - 1, 1)

N = int(input())
bd = []

for i in range(N) : bd.append(list(map(int, input().split(" "))))

m = []
for i in range(N) : m.append([])

m[0] = bd[0]

for i in range(1, N) :
    m[i].append(min(m[i-1][1], m[i-1][2]) + bd[i][0])
    m[i].append(min(m[i - 1][0], m[i - 1][2])+ bd[i][1])
    m[i].append(min(m[i - 1][0], m[i - 1][1])+ bd[i][2])

print(min(m[N-1]))
