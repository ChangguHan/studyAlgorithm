
# 전파 문제
from collections import deque

dx = [1,0,-1,0]
dy = [0,1,0,-1]
M, N = map(int, input().split(" "))
bd = []
for _ in range(N) : bd.append(list(map(int, input().split(" "))))

# 전파원 먼저 큐에넣기
q = deque()
for j in range(N) :
    for i in range(M) :
        if(bd[j][i] == 1) : q.append((j,i))

cnt = -1
while q :
    for lq in range(len(q)) :
        eq = q.popleft()
        ey = eq[0]
        ex = eq[1]

        # print(1)
        for k in range(4) :
            ny = ey + dy[k]
            nx = ex + dx[k]
            if(ny>=0 and ny< N and nx>=0 and nx<M) :
                # if(bd[ny][nx] == 0 and (ny, nx) not in q) :
                if(bd[ny][nx] == 0) :
                    bd[ny][nx] = 1
                    q.append((ny,nx))
    cnt += 1

# 0 있는지 확인
switch = 0
for j in range(N) :
    for i in range(M) :
        if(bd[j][i] == 0) :
            print(-1)
            switch = 1
            break
    if(switch==1) : break
if(switch == 0) : print(cnt)

