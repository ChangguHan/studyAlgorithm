
# 정리된것 사용해서 풀기


# 고립문제 : 고립된 땅 갯수 찾는 문제

# 입력값 세팅(M,N,K,bd,m)
dx = [1,0,-1,0]
dy = [0,1,0,-1]

T = int(input())
ML = []
NL = []
bdL = []
mL = []
for _ in range(T) :
    M,N,K = map(int, input().split(" "))
    ML.append(M)
    NL.append(N)

    bd = [[0]*M for _ in range(N)]
    m = [[0]*M for _ in range(N)]
    for _ in range(K) :
        i,j = map(int, input().split(" "))
        bd[j][i] = 1
    bdL.append(bd)
    mL.append(m)
import sys
sys.setrecursionlimit(100000)
def dfs(j,i) :
    q = [(j,i)]

    while q :
        eq = q.pop(0)
        ey = eq[0]
        ex = eq[1]

        # 각각 Queue마다 수행
        m[ey][ex] = 1


        for k in range(4) :
            ny = ey + dy[k]
            nx = ex + dx[k]

            # 다음 큐 위치 조건
            if(ny>=0 and ny<N and nx>=0 and nx<M) :
                # 다음 큐 조건
                if (bd[ny][nx] == 1 and m[ny][nx] == 0 and (ny,nx) not in q) :
                    q.append((ny,nx))


# def dfs(j,i) :
#     m[j][i] = 1
#     for k in range(4) :
#         ny = j + dy[k]
#         nx = i + dx[k]
#
#         if(nx>= 0 and nx<M and ny>=0 and ny<N) :
#             if(bd[ny][nx] == 1 and m[ny][nx] ==0 ) :
#                 dfs(ny,nx)

for ti in range(T) :
    M = ML[ti]
    N = NL[ti]
    bd = bdL[ti]
    m = mL[ti]
    cnt = 0

    # 0,0부터 M,N까지 조건 맞으면 탐색 수행
    # 조건 : bd[j][i] == OO and m[j][i] == 0
    for j in range(N) :
        for i in range(M) :
            if(bd[j][i] == 1 and m[j][i] == 0) :
                # 갯수 찾는경우 cnt
                cnt += 1
                dfs(j,i)

    print(cnt)