N,M = map(int,input().split(" "))
board = []
for i in range(N) :
    board.append(list(map(int,input().split(" "))))
N -= 1
M -= 1
dy = [-1,1,0,0]
dx = [0,0,-1,1]
maxV = 0
# top, down, left, right

# 3개먼저 고르자
def pick_dfs(count, x,y) :
    if(count == 3) :
        # to do
        bfs()
        return;
    else :
        for j in range(y,N+1) :
            for i in range(x,M +1) :
                if(board[j][i] == 0) :
                    board[j][i] = 1
                    pick_dfs(count+1,i,j)
                    board[j][i] = 0

def bfs() :
    global maxV

    visited = [[0 for col in range(M+1)]for row in range(N+1)]
    backup = board[:]
    q = []
    for j in range(N+1) :
        for i in range(M+1) :
            if(backup[j][i] == 2) :
                q.append((j,i))
                visited[j][i] = 1

    while(q.empty) :
        eachx,eachy = q.pop()

        for dir in range(4) :
            nx = eachx + dx[dir]
            ny = eachy + dx[dir]

            if(ny<0 or ny >N or nx<0 or nx >M) :
                continue

            if visited[ny][nx] == 0 and backup[ny][nx] == 0 :
                visited[ny][nx] =1
                q.append((nx,ny))
    result = 0
    for j in range(N+1) :
        for i in range(M+1) :
            if (backup[j][i] == 0) : result +=1

    maxV = max(result, maxV)


print(pick_dfs(0,0,0))