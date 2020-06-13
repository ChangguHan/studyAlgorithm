# GA X
# DP X
# 한집에 들어가서 주변에거를 모두 찾아야함 >> BFS

N = int(input())
bd = []
m = []
# 한글자씩 split 하는 방법 찾기
for i in range(N) :
    sts = input()
    el = []
    eel = []
    for j in range(N) :
        el.append(sts[j])
        el.append(0)
    bd.append(el)
    m.append(eel)

q = [(0,0)]
dx = [0,0,-1,1]
dy = [1,-1,0,0]
result = []
switch = 0
# memo 하기 위해 빈 모두 0인 list 만들기
while(q) :
    eachSt = q.pop(0)
    eachStX = eachSt[0]
    eachStY = eachSt[1]
    if(m[eachStX][eachStY] != 1) :
        m[eachStX][eachStY] =1
        for i in range(4) :
            nextX = eachStX + dx[i]
            nextY = eachStY + dy[i]
            if(nextX>=0 and nextX<N and nextY>=0 and nextY<N) :
                if(bd[nextX][nextY] == 1) :
                    q.append((nextX, nextY))






