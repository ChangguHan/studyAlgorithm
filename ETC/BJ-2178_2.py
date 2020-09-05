N,M = input().split(" ")
N = int(N) -1
M = int(M) - 1
board = []
for i in range(N+1) :
    re = []
    a = str(input())
    for j in range(len(a)) :
        re.append(int(a[j]))
    board.append(re)

visited = {}
for i in range(N+1) :
    visited[i] = {}

class way :
    def __init__(self, position, num):
        self.position = position
        self.num = num

    def __repr__(self):
        return str(self.position)
    def getXY(self):
        return self.position
def findWay(wayi,board) :

    num = wayi.num+1
    x,y = wayi.getXY()

    result = []
    # left
    if x>0 and board[y][x-1] ==1:
        result.append(way((x-1,y),num))
    # right
    if x<M and board[y][x+1] ==1:
        result.append(way((x+1,y),num))
    # top
    if y >0 and board[y-1][x] == 1
        result.append(way((x, y-1), num))
    # down
    if y < N and board[y+1][x] == 1:
        result.append(way((x, y+1), num))
    return result

queue = [way((0,0),1)]
while(queue) :
    eachWay = queue.pop(0)
    x,y = eachWay.getXY()
    if((x,y) == (M,N)) :
        print(eachWay.num)
        break
    elif(visited[y].get(x) == None) :
        visited[y][x] = True
        queue.extend(findWay(eachWay, board))


# N,M = input().split(" ")
# N = int(N) -1
# M = int(M) - 1
# board = []
# for i in range(N+1) :
#     re = []
#     a = str(input())
#     for j in range(len(a)) :
#         re.append(int(a[j]))
#     board.append(re)
#
#
# class way :
#     def __init__(self, position, num,history):
#         self.position = position
#         self.num = num
#         self.history = history
#     def __repr__(self):
#         return str(self.position)
#     def getXY(self):
#         return self.position
# def findWay(wayi,board) :
#     position = wayi.position
#     num = wayi.num+1
#     x,y = wayi.getXY()
#     his = wayi.history
#     his.append((x,y))
#     result = []
#     # left
#     if x>0 and board[y][x-1] ==1 and (x-1,y) not in his :
#         result.append(way((x-1,y),num,his))
#     # right
#     if x<M and board[y][x+1] ==1  and (x+1,y) not in his:
#         result.append(way((x+1,y),num,his))
#     # top
#     if y >0 and board[y-1][x] == 1 and (x,y-1) not in his:
#         result.append(way((x, y-1), num,his))
#     # down
#     if y < N and board[y+1][x] == 1 and (x,y+1) not in his:
#         result.append(way((x, y+1), num,his))
#     return result
#
# queue = [way((0,0),1,[])]
# while(queue) :
#     eachWay = queue.pop(0)
#     if(eachWay.getXY() == (M,N)) :
#         print(eachWay.num)
#         break
#     else :
#         queue.extend(findWay(eachWay, board))
#
#
