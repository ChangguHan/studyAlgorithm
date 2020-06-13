import collections
N,M = map(int,input().split(" "))
board= []
for i in range(N) :
    li = []
    txt = input()
    for j in range(len(txt)) :
        li.append(int(txt[j]))
    board.append(li)

# print(N,M)
# print(board)

# N,M = 4,6
# board = [[1, 0, 1, 1, 1, 1], [1, 0, 1, 0, 1, 0], [1, 0, 1, 0, 1, 1], [1, 1, 1, 0, 1, 1]]


q = collections.deque((0,0,[]))

dx = [-1,1,0,0]
dy = [0,0,1,-1]

while(q) :
    [ex,ey,visited] = q.popleft()

    nv = visited[:]
    nv.append((ex,ey))


    if((ex,ey) == (M-1,N-1)) :
        print(len(nv))
        break

    for i in range(4) :
        ny = ey + dy[i]
        nx = ex + dx[i]
        # if(nx >= 0 and nx<M and ny >= 0 and ny < N and (nx,ny) not in nv) :
        if (nx >= 0 and nx < M and ny >= 0 and ny < N and (nx, ny) not in nv):
            if(board[ny][nx] == 1) :
                q.append([nx,ny,nv])

