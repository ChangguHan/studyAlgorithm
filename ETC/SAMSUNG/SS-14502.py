N,M = map(int,input().split(" "))
board = []
for i in range(N) :
    board.append(list(map(int,input().split(" "))))

# M,N = 7,7
# board = [[2, 0, 0, 0, 1, 1, 0], [0, 0, 1, 0, 1, 2, 0], [0, 1, 1, 0, 1, 0, 0], [0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 1], [0, 1, 0, 0, 0, 0, 0], [0, 1, 0, 0, 0, 0, 0]]

# 3칸 조합으로 선택 : 재귀 조합
result = []
def pick3point(x=0,y=0,pick=[]) :
    if(len(pick) == 3 ) :
        backup = pick[:]
        result.append(backup)
        return

    for j in range(y,N) :
        for i in range(x,M) :
            if(board[j][i] == 0) :
                pick.append((i,j))
                pick3point(i+1,j,pick)
                pick.pop()
        x = 0
pick3point()


dx = [1,-1,0,0]
dy = [0,0,-1,1]

def spread2(x,y) :
    global backup
    for i in range(4) :
        nx = x + dx[i]
        ny = y + dy[i]
        if(nx>=0 and nx<=M-1 and ny>=0 and ny <= N-1) :
            if(backup[ny][nx] == 0 ) :
                backup[ny][nx] = 2
                spread2(nx,ny)

# 4칸 퍼지면됨, 재귀
maxv = 0
for each in result :

    backup = []
    for j in range(N):
        backup.append(board[j][:])

    for i in each :
        backup[i[1]][i[0]] = 1

    # 2찾기
    initial2Position = []
    for j in range(N) :
        for i in range(M) :
            if(backup[j][i]) == 2 :
                initial2Position.append((i,j))
    for eachPosi in initial2Position :
        spread2(eachPosi[0],eachPosi[1])

    count = 0
#     0 카운트
    for j in range(N) :
        for i in range(M) :
            if(backup[j][i] == 0) : count +=1
    maxv = max(count, maxv)

print(maxv)