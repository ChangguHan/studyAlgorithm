
# 시간초과남 >> for를 줄일수 있는 방법 있을까
# 각각 나눠서 몫을 더해주는 부분을 줄일수있는 방법
# 없는것 같음 >> m을 dict 쓰지말고, list 써볼까

N,V = map(int, input().split(" "))
bd = []
for i in range(N) : bd.append(int(input()))
bd.sort()

m = []
for i in range(N) : m.append([])

# 초기값
for i in range(V+1) :
    if(i%bd[0] == 0) :
        m[0].append(1)
    else :
        m[0].append(0)

for i in range(1,N) :
    for j in range(0,V+1) :
        if(j==0) : m[i].append(1)
        else :
            divMock = int(j/bd[i])
            sv = 0
            for k in range(divMock+1) :
                nv = j-k*bd[i]
                try :
                    sv += m[i-1][nv]
                except : continue
            m[i].append(sv)

try : print(m[N-1][V])
except : print(0)

