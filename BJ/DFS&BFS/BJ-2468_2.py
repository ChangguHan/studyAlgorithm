
# 똑같은데 bd 조건만 해당 물조건으로 보면 될듯
N = int(input())
bd = []
for _ in range(N) : bd.append(list(map(int, input().split(" "))))
minv = bd[0][0]
maxv = bd[0][0]
for i in range(N) :
    minv = min(minv, min(bd[i]))
    maxv = max(maxv, max(bd[i]))

cntL = [1]
dx = [1,0,-1,0]
dy = [0,1,0,-1]

def bfs(j,i) :
    q = [(j,i)]

    while q :
        eq = q.pop(0)
        ey = eq[0]
        ex = eq[1]
        m[ey][ex] = 1

        for kk in range(4) :
            ny = ey + dy[kk]
            nx = ex + dx[kk]
            if(nx >= 0 and nx < N and ny >=0 and ny <N) :
                if(bd[ny][nx] > k and m[ny][nx] == 0 and (ny,nx) not in q) :
                    q.append((ny,nx))

for k in range(minv, maxv) :
    cnt = 0
    m = [[0]*N for _ in range(N)]
    for j in range(N) :
        for i in range(N) :
            if(bd[j][i] > k and m[j][i] == 0) :
                cnt +=1
                bfs(j,i)
    cntL.append(cnt)

print(max(cntL))