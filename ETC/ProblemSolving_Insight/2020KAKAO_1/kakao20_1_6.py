

def solution(input) :
    queue = [node()]
    N = len(input)-1
    m = []

    while(queue) :
        node_ = queue.pop(0)
        if(node_.getXY() == (N,N) or node_.getXY2() == (N,N)) :
            return node_.dist
        if((node_.getXY(), node_.getXY2()) not in m) :
            m.append((node_.getXY(), node_.getXY2()))
            addedQueue = add_queue(input,node_)
            queue.extend(addedQueue)
    return 0

class node :
    def __init__(self,x=0,y=0, dist=0, state=True):
        # state :True - 가로, False - 세로
        self.dist = dist
        self.x = x
        self.y = y
        self.state = state
        if self.state :
            self.x2 = x+1
            self.y2 = y
        else :
            self.x2 = x
            self.y2 = y+1
    def __repr__(self):
        return "(" + str(self.x)+","+str(self.y)+"),("+str(self.x2)+","+str(self.y2)+")"
    def getXY(self):
        return self.x,self.y
    def getXY2(self):
        return self.x2,self.y2

def add_queue(input,ex_node) :
    dist = ex_node.dist+1
    N = len(input)-1
    x,y = ex_node.getXY()
    x2,y2 = ex_node.getXY2()
    result = []
    if (x>=0 and y>=0 and x2>=0 and y2>=0) :


        if(ex_node.state) : #가로
            if(x2+1 <= N and input[y][x2+1] ==0 ) : # 오른쪽 한칸 이 벽보다 안쪽이고, 0일때
                result.append(node(x+1,y,dist,True))
            if(x-1>=0 and input[y][x-1] == 0 ) :
                result.append(node(x - 1, y, dist, True))
            if (y+1 <= N and input[y+1][x] == 0 and input[y+1][x2]==0 ):  # 아래로 내려갈때
                result.append(node(x, y+1, dist, True))
                result.append(node(x, y, dist, False))
                result.append(node(x+1, y, dist, False))
            if (y-1 >= 0 and input[y-1][x] == 0 and input[y2-1][x2] == 0): # 위로 올라갈때
                result.append(node(x, y - 1, dist, True))
                result.append(node(x, y-1, dist, False))
                result.append(node(x + 1, y-1, dist, False))
        else : #세로
            if (y - 1 >=0 and input[y-1][x] == 0):  # 위로
                result.append(node(x, y-1, dist, False))
            if (y2+ 1 <= N and input[y2+1][x] == 0): #아래로
                result.append(node(x, y+1, dist, False))
            if (x-1 >= 0 and input[y][x-1] == 0 and input[y2][x-1] == 0):  # 왼쪽
                result.append(node(x-1, y, dist, False))
                result.append(node(x-1, y, dist, True))
                result.append(node(x-1, y+1, dist, True))
            if (x+1 <= N and input[y][x+1] == 0 and input[y2][x2+1] == 0):  # 오른쪽
                result.append(node(x+1, y, dist, False))
                result.append(node(x, y, dist, True))
                result.append(node(x, y + 1, dist, True))
    return result
input = [[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]
print(solution(input))
        # class node:
        #     def __init__(self, x=0, y=0, x2=0, y2=0, dist=0, state=True):
        #         # state :True - 가로, False - 세로
        #         self.dist = dist
        #         self.x = x
        #         self.y = y
        #         self.x2 = x2
        #         self.y2 = y2
        #         self.state = state
        #
        #     def getXY(self):
        #         return self.x, self.y
        #
        #     def getXY2(self):
        #         return self.x2, self.y2
        #
        # def add_queue(input, node):
        #     dist = node.dist + 1
        #     N = len(input) - 1
        #     x, y = node.getXY()
        #     x2, y2 = node.getXY2()
        #     result = []
        #
        #     if (node.state):  # 가로
        #         if (x2 + 1 <= N and input[y][x2 + 1] == 0):  # 오른쪽 한칸 이 벽보다 안쪽이고, 0일때
        #             result.append(node(x + 1, y, x2 + 1, y2, dist, True))
        #         if (x - 1 >= 0 and input[y][x - 1] == 0):
        #             result.append(node(x - 1, y, x2 - 1, y2, dist, True))
        #         if (y + 1 <= N and input[y + 1][x] == 0 and input[y + 1][x2] == 0):  # 아래로 내려갈때
        #             result.append(node(x, y + 1, x2, y2 + 1, dist, True))
        #             result.append(node(x, y, x2 - 1, y2 + 1, dist, False))
        #             result.append(node(x + 1, y, x2, y2 + 1, dist, False))
        #         if (y - 1 >= 0 and input[y - 1][x] == 0 and input[y2 - 1][x2] == 0):  # 위로 올라갈때
        #             result.append(node(x, y - 1, x2, y2 - 1, dist, True))
        #             result.append(node(x, y, x2 - 1, y2 + 1, dist, False))
        #             result.append(node(x + 1, y, x2, y2 + 1, dist, False))
        #
        #
        #     else:  # 세로