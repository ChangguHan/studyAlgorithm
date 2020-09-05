# N,L = list(map(int, input().split(" ")))
# board = []
# for i in range(N) :
#     board.append(list(map(int,input().split(" "))))

N,L = 6,2
board = [[3, 3, 3, 3, 3, 3], [2, 3, 3, 3, 3, 3], [2, 2, 2, 3, 2, 3], [1, 1, 1, 2, 2, 2], [1, 1, 1, 3, 3, 1], [1, 1, 2, 3, 3, 2]]

# for돌면서 각 경사가 그 조건에 맞는지 확인하면 되지.

# 세로먼저
result = 0
for i in range(N) :
    last = board[0][i]
    count = 0
    for j in range(1,N) :

        # 만났을때, 기존것이 L개가 있어야됌, 안만나면 끝이고, 안되면 continue
        if(board[j][i] == last) :
            count += 1
        else :
            if(count <= L ) :
                count = 0
            else :
                break
        if(j == N-1) : result +=1





