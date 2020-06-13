M,N,K = map(int,input().split(" "))
board = [[0 for i in range(N)] for j in range(M)]
for i in range(K) :
    x,y,x2,y2 = map(int,input().split(" "))
    for j in range(x,x2) :
        for k in range(y,y2) :
            board[k][j] = 1
# print(M,N,K)
# print(board)


# M,N,K = 5,7,3
# board = [[0, 0, 0, 0, 1, 1, 0], [0, 1, 0, 0, 1, 1, 0], [1, 1, 1, 1, 0, 0, 0], [1, 1, 1, 1, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0]]


# for j in range(M) :
#     for i in range(N) :
#         if(board[j][i] == 0) :
#             q.append((i,j))

dx = [0,0,-1,1]
dy = [1,-1,0,0]

# bfs
def bfs(q) :
    count = 0

    while(q) :
        ex,ey = q.pop(0)
        if (board[ey][ex] == 0):
            count +=1
            board[ey][ex] = 1

        for i in  range(4) :
            nx = ex+dx[i]
            ny = ey+dy[i]
            if(nx>=0 and nx<N and ny>=0 and ny<M and (ex,ey) not in q) :
                if(board[ny][nx] == 0) :
                    q.append((nx,ny))
    return count

# print(bfs([(6,0)]))
result = []
for j in range(M) :
    for i in range(N) :
        if(board[j][i] == 0) :
            result.append(bfs([(i,j)]))

result.sort()

for i in range(len(result)) :
    result[i] = str(result[i])
print(len(result))
print(" ".join(result))