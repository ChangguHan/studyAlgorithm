
# 다시 나혼자 스스로 풀어보자
# for로 전라인 돌면서 1 만나면
# dfs들어가서 해당 인접한것 모두 가져오기

N = int(input())
bd = []
m = []
rs = []
for i in range(N) :
    bd.append(list(input()))
    m.append(['0']*N)

def dfs(j,i) :
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    global cnt
    cnt +=1
    m[j][i] = '1'

    for k in range(4) :
        ny = j+dy[k]
        nx = i+dx[k]

        if(nx>=0 and nx<N and ny>=0 and ny<N) :
            if(bd[ny][nx] == '1' and m[ny][nx] != '1') :
                dfs(ny,nx)


for j in range(N) :
    for i in range(N) :
        if(bd[j][i] =='1' and m[j][i] != '1') :
            cnt = 0
            dfs(j,i)
            rs.append(cnt)

rs.sort()
lenRs = len(rs)
print(lenRs)
for i in range(lenRs) : print(rs[i])