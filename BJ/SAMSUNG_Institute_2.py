# 3칸 먼저 순열로 고르고 : 재귀
# 바이러스 확산시켜서
# 0 개수 새면 되지

N,M = map(int, input().split(" "))
board=  []
result = 0
for i in range(N) :
    board.append(list(map(int, input().split(" "))))

def dfs(count,x,y) :
    if( count == 3 ) :
        #  to do
        return bfs()
    for j in range(y,N) :
        for i in range(x,M) :
            if(board[j][i] == 0) :
                board[j][i] = 1
                dfs(count+1, i+1,j)
                board[j][i] = 0
        x = 0

def bfs() :
    global result

    backup = []
    q = []
    for j in range(N) :
        temp = []
        for i in range(M) :
            temp.append(board[j][i])
            if(board[j][i] == 2) : q.append((i,j))
        backup.append(temp)
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    visited = [[0 for i in range(M)] for j in range(N)]
    while(q) :
        ex,ey = q.pop(0)
        backup[ey][ex] = 2

        for i in range(4) :
            ny = ey + dy[i]
            nx = ex + dx[i]
            if(nx >=0 and nx <= M-1 and ny >=0 and ny <= N-1) :
                if(board[ny][nx] == 0 and visited[ny][nx] == 0) :
                     visited[ny][nx] = 1
                     q.append((nx,ny))

    count = 0
    for j in range(N) :
        for i in range(M) :
            if(backup[j][i] == 0) : count +=1
    result = max(count, result)
dfs(0,0,0)
print(result)