# 최대 20*50으로 풀어볼까
case = int(input())
board = []
for i in range(case) :
    each= []
    for j in range(int(input())+2) :
        each.append(tuple(map(int,input().split(" "))))
    board.append(each)


# print(board)

# board = [[(0, 0), (1000, 0), (1000, 1000), (2000, 1000)], [(0, 0), (1000, 0), (2000, 1000), (2000, 2000)]]
for i in board :
    switch = 0
    for j in range(len(i)) :
        if(j ==0) : continue

        if((i[j][0] - i[j-1][0]) + (i[j][1] - i[j-1][1]) > 1000) :
            print("sad")
            switch = 1
            break
    if(switch == 0) : print("happy")

