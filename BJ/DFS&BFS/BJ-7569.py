
# 위,아래가 있는 그래프 탐색
# 마지막에 0이 있는것 확인, 없으면 -1 출력
# 전파 >> 1먼저 찾기 >> dfs
from collections import deque

dx = [1,0,-1,0,0,0]
dy = [0,1,0,-1,0,0]
dz = [0,0,0,0,1,-1]

M,N,H = map(int, input().split(" "))
bd = []
for _ in range(H) :
    ebd = []
    for __ in range(N) : ebd.append(list(map(int, input().split(" "))))
    bd.append(ebd)

q = deque()
for k in range(H) :
    for j in range(N) :
        for i in range(M) :
            if(bd[k][j][i] == 1) :
                q.append((k,j,i,0))

m = [[[0]*M for _ in range(N)] for __ in range(H)]

while q :
    eq = q.popleft()

    ez = eq[0]
    ey = eq[1]
    ex = eq[2]
    ei = eq[3]

    for k in range(6) :
        nz = ez + dz[k]
        ny = ey + dy[k]
        nx = ex + dx[k]
        ni = ei + 1

        if(nz >=0 and nz < H and
            ny >=0 and ny < N and
            nx >=0 and nx < M) :
            if(bd[nz][ny][nx] == 0 and
                    (nz,ny,nx,ni) not in q) :
                bd[nz][ny][nx] = 1
                q.append((nz,ny,nx,ni))
switch = 0
for k in range(H) :
    for j in range(N) :
        for i in range(M) :
            if(bd[k][j][i] == 0) :
                print(-1)
                switch = 1
                break
        if (switch == 1): break
    if (switch == 1): break
if(switch ==0) : print(ni-1)