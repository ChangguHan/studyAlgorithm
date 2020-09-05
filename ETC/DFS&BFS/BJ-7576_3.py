
from collections import deque

M,N = map(int, input().split(" "))
bd = []
for _ in range(N) : bd.append(list(map(int, input().split(" "))))


q = deque()

for j in range(N) :
    for i in range(M) :
        if(bd[j][i] == 1) : q.append((j,i))

dx = [1,0,-1,0]
dy = [0,1,0,-1]
cnt = 0
while q :
    lq = len(q)

    for qi in range(lq) :
        eq = q.popleft()
        ey = eq[0]
        ex = eq[1]

        # print(1)

        for k in range(4) :
            ny = ey + dy[k]
            nx = ex + dx[k]
            if(nx>=0 and nx<M and ny>=0 and ny<N) :
                if(bd[ny][nx] == 0) :
                    bd[ny][nx] = 1
                    q.append((ny,nx))
    cnt += 1

sw = 0
for j in range(N) :
    for i in range(M) :
        if(bd[j][i] == 0) :
            sw = 1
            print(-1)
            break
    if(sw == 1) : break

if(sw ==0) :
    print(cnt-1)
