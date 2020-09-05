
# BFS로 풀수있을까?
# 같은 방법인데 BFS로 풀수있을것같음

N = int(input())
bd= []
m = []
rs = []
for i in range(N) :
    bd.append(list(input()))
    m.append(['0']*N)

def bfs(j,i) :
    dy = [0,1,0,-1]
    dx = [1,0,-1,0]

    st = [(j,i)]
    cnt = 0


    while(st) :
        es = st.pop(0)
        esy = es[0]
        esx = es[1]

        m[esy][esx] = '1'

        cnt += 1

        for k in range(4) :
            ny = esy+dy[k]
            nx = esx+dx[k]

            if(nx>=0 and nx<N and ny>=0 and ny<N) :
                if(bd[ny][nx] == '1' and m[ny][nx] !='1') :
                    if (ny,nx) not in st :
                        st.append((ny,nx))


    return cnt


for j in range(N) :
    for i in range(N) :
        if(bd[j][i] == '1' and m[j][i] == '0') :
            rs.append(bfs(j,i))


rs.sort()
lenRs = len(rs)
print(lenRs)
for i in range(lenRs) : print(rs[i])