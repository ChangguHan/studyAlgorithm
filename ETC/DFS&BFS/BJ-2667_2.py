# 한집에 들어가서 주위 모든걸 찾아야함 >> DFS

N = int(input())
bd = []
m = []
for i in range(N) :
    bd.append(list(input()))
    m.append(['0']*N)
rs = []
def dfs(i,j) :
    global cnt
    m[i][j] = '1'
    cnt +=1

    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    for k in range(4) :
        nx = j + dx[k]
        ny = i + dy[k]

        if(nx>=0 and nx<N and ny>=0 and ny<N) :
            if(bd[ny][nx] == '1' and m[ny][nx] != '1') :
                dfs(ny,nx)


for i in range(N) :
    for j in range(N) :
        if(bd[i][j] =='1' and m[i][j] != '1') :
            cnt = 0
            dfs(i,j)
            rs.append(cnt)

rs.sort()
print(len(rs))
for i in range(len(rs)) : print(rs[i])