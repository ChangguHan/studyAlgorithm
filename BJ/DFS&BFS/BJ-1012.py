
# 전형적인 고립문제

T = int(input())
ML = []
NL = []
KL = []
bdT = []
for _ in range(T) :
    M,N,K = map(int, input().split(" "))
    ML.append(M)
    NL.append(N)
    KL.append(K)

    el = [[0]*M for __ in range(N)]
    for ki in range(K) :
        i,j = map(int, input().split(" "))
        el[j][i] = 1
    bdT.append(el)

dx = [1,0,-1,0]
dy = [0,1,0,-1]

def bfs(j,i) :
    s = [(j,i)]

    while s :
        es = s.pop()
        ey = es[0]
        ex = es[1]

        m[ey][ex] = 1

        for k in range(4) :
            ny = ey+dy[k]
            nx = ex+dx[k]
            # if(ny == 3 and nx == 4) :
            #     print(1)
            if(nx>=0 and nx<M and ny>=0 and ny<N) :
                if(bd[ny][nx] == 1 and m[ny][nx] == 0 and (ny,nx) not in s) :
                    s.append((ny,nx))


for et in range(T) :
    M = ML[et]
    N = NL[et]
    bd = bdT[et]
    m = [[0]*M for _ in range(N)]
    cnt = 0
    for j in range(N) :
        for i in range(M) :
            if(bd[j][i] == 1 and m[j][i] == 0) :
                bfs(j,i)
                cnt += 1
    print(cnt)