# 바이러스 골라서
# bfs로 퍼치면 된다

import copy
N, M = map(int,input().split(" "))
bd = []
for i in range(N) :
    bd.append(list(map(int,input().split(" "))))

# print(N,M)
# print(bd)
#
# N,M = 7,3
# bd = [[2, 0, 0, 0, 1, 1, 0], [0, 0, 1, 0, 1, 2, 0], [0, 1, 1, 0, 1, 0, 0], [0, 1, 0, 0, 0, 0, 0], [0, 0, 0, 2, 0, 1, 1], [0, 1, 0, 0, 0, 0, 0], [2, 1, 0, 0, 0, 0, 2]]

# 바이러스 M개 만큼 고르기,
result = []
def comb(pick =[]) :
    if(len(pick) == M) :
        bu = pick[:]
        result.append(bu)
        return
    if(len(pick) == 0) : x,y = 0,0
    else :
        x,y = pick[len(pick)-1]
        x += 1

    for j in range(y,N) :
        for i in range(x,N) :
            if(bd[j][i] == 2) :
                pick.append((i,j))
                comb(pick)
                pick.pop()
        x = 0
comb()

class e :
    def __init__(self,init,board,count):
        self.init = init
        self.board=  board
        self.count = count
    def __repr__(self):
        return "".join(["{"," ".join(list(map(str,self.init))),"}"])

q = []
for i in result :
    q.append(e(i,copy.deepcopy(bd),0))


dx = [0,0,1,-1]
dy = [1,-1,0,0]

while(q) :
    each = q.pop(0)
    eachB = copy.deepcopy(each.board)
    eachI = each.init[:]
    eachC = each.count
    newList = []



    for i in eachI :
        for j in range(4) :
            nx =i[0]+dx[j]
            ny =i[1] + dy[j]
            if(nx>=0 and nx<N and ny>=0 and ny<N) :
                if(eachB[ny][nx] == 0) :
                    eachB[ny][nx] = 2
                    newList.append((nx,ny))

    if(len(newList) != 0) :
        q.append(e(newList, eachB,eachC+1))
    else :
        ttc = 0
        for i in range(N) :
            ttc +=eachB[i].count(0)

        if(ttc == 0) :
            print(eachC)
            break

if(ttc != 0) : print(-1)

