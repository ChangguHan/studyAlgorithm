N,M = map(int,input().split(" "))
y,x,d = map(int,input().split(" "))
board = []
for j in range(N) :
    board.append(list(map(int, input().split(" "))))
dy = [-1,0,1,0]
dx = [0,1,0,-1]
def algo(x,y,d) :
    board[y][x] = 2
    for i in range(1,5) :
        nd = (d+4-i)%4
        ny = y + dy[nd]
        nx = x + dx[nd]
        if(nx >= 0 and nx <= M-1 and ny >= 0 and ny<=N-1) :
            if (board[ny][nx] == 0):
                algo(nx,ny,nd)
                return
    ny = y + dy[(d+4-2)%4]
    nx = x + dx[(d + 4 - 2) % 4]
    if(board[ny][nx] == 1) : return
    else : algo(nx,ny,d)
algo(x,y,d)
count = 0
for j in range(N) :
    for i in range(M) :
        if(board[j][i] == 2) : count +=1
print(count)

