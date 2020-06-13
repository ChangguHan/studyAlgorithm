
# 고립문제 : 고립된 땅 갯수 찾는 문제

# 입력값 세팅(M,N,K,bd,m)

dx = [1,0,-1,0]
dy = [0,1,0,-1]
M = int(input())
N = int(input())
K = int(input())
bd = [[0]*M for _ in range(N)]
m = [[0]*M for _ in range(N)]
for _ in range(K) :
    i,j = map(int, input().split(" "))
    bd[j][i] = 1
cnt = 0


# 0,0부터 M,N까지 조건 맞으면 탐색 수행
# 조건 : bd[j][i] == OO and m[j][i] == 0
for j in range(N) :
    for i in range(M) :
        if(bd[j][i] == 1 and m[j][i] == 0) :
            # 갯수 찾는경우 cnt
            cnt += 1
            bfs(j,i)

# 고립 bfs 사용
def bfs(j,i) :
    q = [(j,i)]

    while q :
        ey,ex = q.pop(0)

        # 각각 Queue마다 수행
        m[ey][ex] = 1

        # 시간초과 날경우, 여기 각각 계산해주는게 효과적
        for k in range(4) :
            ny,nx = ey + dy[k], ex + dx[k]

            # 다음 큐 위치 조건
            if(ny>=0 and ny<N and nx>=0 and nx<M) :
                # 다음 큐 조건
                if (bd[ny][nx] == 1 and m[ny][nx] == 0 and (ny,nx) not in q) :
                    q.append((ny,nx))
        # 시간초과날 경우, 각각 계산


# 고립 DFS
def dfs(j,i) :
    s = [(j,i)]

    while s :
        es = s.pop(0)
        ey = es[0]
        ex = es[1]
        m[ey][ex] = 1

        for k in range(4) :
            ny = ey + dy[k]
            nx = ex + dx[k]

            if(nx>=0 and nx<M and ny>=0 and ny<N) :
                if(bd[ny][nx] == 1 and m[ny][nx] == 0 and (ny,nx) not in s) :
                    s.append((ny,nx))

# 고립 DFS 재귀
def dfsRecur(j,i) :
    m[j][i] = 1
    for k in range(4) :
        ny = j + dy[k]
        nx = i + dx[k]

        if(nx>= 0 and nx<M and ny>=0 and ny<N) :
            if(bd[ny][nx] == 1 and m[ny][nx] ==0 ) :
                dfsRecur(ny,nx)


#########################

# 전파 문제 :전파원이 모두 전파되는데 시간 측정
from collections import deque
# 기본값
M,N = map(int, input().split(" "))
bd = []
for _ in range(N) : bd.append(list(map(int, input().split(" "))))
dx = [1,0,-1,0]
dy = [0,1,0,-1]
q = deque()

# 전파원 찾기
for j in range(N) :
    for i in range(M) :
        # 전파원 조건
        if(bd[j][i] == 1) : q.append((j,i))

# bfs 돌리기
cnt = 0

while q :
    lq = len(q)
    for qi in range(lq) :
        ey,ex = q.popleft()

        # print(1)
        # 시간 초과일경우, 여기를 각각해줌
        for k in range(4) :
            ny,nx = ey + dy[k], ex + dx[k]
            # 경계 조건
            if(nx>=0 and nx< M and ny>=0 and ny<N) :
                # 전파조건
                if(bd[ny][nx] == 0) :
                    bd[ny][nx] = 1
                    q.append((ny,nx))

        # 시간초과일경우 각각
        # if(ex-1 >=0 and bd[ey][ex-1] == 0) :
        #     bd[ey][ex-1] = 1
        #     q.append((ey, ex-1))
        # if (ex + 1 < M and bd[ey][ex + 1] == 0):
        #     bd[ey][ex + 1] = 1
        #     q.append((ey, ex + 1))
        # if (ey - 1 >= 0 and bd[ey-1][ex] == 0):
        #     bd[ey-1][ex] = 1
        #     q.append((ey-1, ex))
        # if (ex + 1 >= 0 and bd[ey+1][ex] == 0):
        #     bd[ey+1][ex] = 1
        #     q.append((ey+1, ex))

    cnt +=1

# 전파 빈곳 확인
sw = 0
for j in range(N) :
    for i in range(M) :
        if(bd[j][i] == 0) :
            sw = 1
            print(-1)
            break
    if(sw==1) : break

if(sw==0) : print(cnt-1)


######################################

# 연결개수 문제

# 시간초과난다는건 데이터 입력 개수 많다는 거니까,
# sys.stdin.readline() 으로 input()대신하면 됨

# 기본세팅
N,M = map(int, input().split(" "))
bd = [[] for _ in range(N+1)]
for _ in range(M) :
    a,b = map(int, input().split(" "))
    bd[a].append(b)
    bd[b].append(a)
m = [0] * (N+1)

def dfs(i) :
    q = deque(i)
    # m 여기서 주는 이유는, q넣을 때 1 주기위해
    # 그러면 q안에 있는지 확인하고 q에 넣는 조건 안쓸수있음
    m[i] = 1

    while q :
        eq = q.popleft()

        for ebd in bd[eq] :
            if(m[ebd] == 0) :
                q.append(ebd)
                m[ebd] = 1

cnt = 0
for i in range(1,N+1) :
    if(m[i] == 1) : continue
    dfs(i)
    cnt +=1
print(cnt)