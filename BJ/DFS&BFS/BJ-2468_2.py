
# 노트 사용
# bd 조건만 바꿔주면 됨


dx = [1,0,-1,0]
dy = [0,1,0,-1]
N = int(input())
bd = []
for _ in range(N) :
    bd.append(list(map(int, input().split(" "))))



# 고립 bfs 사용
def bfs(j,i) :
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
            if(ny>=0 and ny<N and nx>=0 and nx<N) :
                # 다음 큐 조건
                if (bd[ny][nx] > rain and m[ny][nx] == 0 and (ny,nx) not in q) :
                    q.append((ny,nx))
minv = bd[0][0]
maxv = bd[0][0]
for i in range(N) :
    minv = min(minv, min(bd[i]))
    maxv = max(maxv, max(bd[i]))
rsL = [1]

for rain in range(minv, maxv) :
    cnt = 0
    m = [[0]*N for _ in range(N)]
# 0,0부터 M,N까지 조건 맞으면 탐색 수행
# 조건 : bd[j][i] == OO and m[j][i] == 0
    for j in range(N) :
        for i in range(N) :
            if(bd[j][i] > rain and m[j][i] == 0) :
                # 갯수 찾는경우 cnt
                cnt += 1
                bfs(j,i)
    rsL.append(cnt)
print(max(rsL))