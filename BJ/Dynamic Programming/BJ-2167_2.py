# 그냥 for 쓰면 안되나?
# 시간초과남 >> 메모이제이션 사용
# 우선 한번 다 더한다음에 빼주면 됨

N,M = map(int, input().split(" "))
bd = []
for i in range(N) :
    bd.append(list(map(int, input().split(" "))))
K = int(input())
posi = []
for i in range(K) : posi.append(list(map(int, input().split(" "))))

m = []
for i in range(N) : m.append([0] * M)

for i in range(N) :
    for j in range(M) :
        sv = bd[i][j]
        if(i==0 and j==0) :
            sv += 0
        elif(j==0) :
            sv += m[i-1][M-1]
        else :
            sv += m[i][j-1]
        m[i][j] = sv

for i in range(K) :
    [a,b,c,d] = posi[i]
    if(a-1 == 0)  a = N
    if()
    print(m[c-1][d-1] -m[a-1][b-1] + bd[a-1][b-1])
print(m)
