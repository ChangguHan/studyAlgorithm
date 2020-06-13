from collections import deque


#     visited = [[False] * m for _ in range(n)]
# 이거 나중에 m 할때 써먹기

# 주위 부터 둘러나가니까 BFS

M,N = map(int, input().split(" "))
bd = []
for i in range(N) : bd.append(list(map(int,input().split(" "))))

q = deque()
# 1있는것 먼저 넣어줌
for j in range(N) :
    for i in range(M) :
        if(bd[j][i] ==1 ) : q.append((j,i,0))


# 근데 이게 첫회인지 아닌지를 어떻게 알려주지?
# list로 구분하나?
# q에 숫자하나 추가해서 넣는게 가장 간편한 방법일듯


def cntT(bd) :
    cnt = 0
    for j in range(N) :
        cnt += bd[j].count(0)
    return cnt

rs = -1
dx = [1,0,-1,0]
dy = [0,1,0,-1]
while(q) :
    eq = q.popleft()
    ey = eq[0]
    ex = eq[1]
    ei = eq[2]

    # if(cntT(bd) == 0) :
    #     rs = ei
    #     break


    for i in range(4) :
        ny = ey+dy[i]
        nx = ex + dx[i]

        if(nx>=0 and nx<M and ny>=0 and ny<N) :
            if(bd[ny][nx] == 0) :
                bd[ny][nx] = 1
                q.append((ny,nx,ei+1))

# 불가능한건 탐색 모두 돌리고 나서, 조건 확인
if(cntT(bd) != 0 ) : print(-1)
else : print(ei)