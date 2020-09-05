from collections import deque


M,N,H = map(int, input().split(" "))
bd= []
for hi in range(H) :
    ebd = []
    for ni in range(N) :
        ebd.append(list(map(int, input().split(" "))))
    bd.append(ebd)

dx = [1,0,-1,0,0,0]
dy = [0,1,0,-1,0,0]
dz = [0,0,0,0,1,-1]
q = deque()
numdata = 0

zeroCount = 0
for k in range(H) :
    for j in range(N) :
        for i in range(M) :
            if(bd[k][j][i] == 1) :
                q.append((k,j,i))
                # numdata += 1
            # if (bd[k][j][i] == 0):
            #     zeroCount +=1
            #     numdata += 1


# if(zeroCount == 0) : print(0)
else :
    cnt = 0
    # dataCount = 0

    while q :

        lq = len(q)
        # dataCount += lq
        for qi in range(lq) :
            eq = q.popleft()
            ez, ey, ex = eq

            if(ex-1 >=0 and bd[ez][ey][ex-1] == 0) :
                bd[ez][ey][ex-1] = 1
                q.append((ez,ey,ex-1))
            if (ex + 1 <M and bd[ez][ey][ex + 1] == 0):
                bd[ez][ey][ex + 1] = 1
                q.append((ez, ey, ex + 1))
            if (ey - 1 >= 0 and bd[ez][ey-1][ex] == 0):
                bd[ez][ey-1][ex] = 1
                q.append((ez, ey-1, ex))
            if (ey + 1 < N and bd[ez][ey+1][ex] == 0):
                bd[ez][ey+1][ex] = 1
                q.append((ez, ey+1, ex))
            if (ez - 1 >= 0 and bd[ez-1][ey][ex] == 0):
                bd[ez-1][ey][ex] = 1
                q.append((ez-1, ey, ex))
            if (ez + 1 < H and bd[ez+1][ey][ex] == 0):
                bd[ez+1][ey][ex] = 1
                q.append((ez+1, ey, ex))
        cnt += 1




            #
            # for di in range(6) :
            #     # nz = ez + dz[di]
            #     # ny = ey + dy[di]
            #     # nx = ex + dx[di]
            #
            #     nz,ny,nx = ez + dz[di], ey + dy[di], ex + dx[di]
            #
            #     if(nz>=0 and nz<H and ny >=0 and ny<N
            #             and nx>=0 and nx<M) :
            #         if(bd[nz][ny][nx] == 0) :
            #             bd[nz][ny][nx] = 1
            #             q.append((nz,ny,nx))



    sw=0
    for k in range(H) :
        for j in range(N) :
            for i in range(M) :
                if(bd[k][j][i] == 0) :
                    sw=1
                    print(-1)
                    break
            if(sw==1) : break
        if(sw==1) : break
    if(sw==0) : print(cnt-1)

    # if(numdata == dataCount) : print(cnt-1)
    # else : print(-1)