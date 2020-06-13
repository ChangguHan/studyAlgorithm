
# 최대값이라면 GA로 했을텐데, 경우의수니까 해볼수밖에 없음
# DP로 풀면 될듯
# Sn,v = sum(Sn-1,v-bd[n]*개수) bd[n]*개수

N,V = map(int, input().split(" "))
bd = []
for i in range(N) : bd.append(int(input()))
bd.sort()

m = {}
for i in range(V+1) :
    if(i%bd[0] == 0) :
        m[0,i] = 1

for i in range(1,N) :
    for j in range(0,V+1) :
        if(j==0) : m[i,j] = 1
        else :
            divMock = int(j/bd[i])
            sv = 0
            for k in range(divMock+1) :
                nv = j-k*bd[i]
                if(m.get((i-1,nv)) == None) :
                    continue
                else :sv += m[i-1,nv]
            m[(i,j)] = sv

if(m.get((N-1,V)) == None) : print(0)
else : print(m[N-1,V])


# 시간초과남 >> for를 줄일수 있는 방법 있을까
# 각각 나눠서 몫을 더해주는 부분을 줄일수있는 방법
# 없는것 같음 >> m을 dict 쓰지말고, list 써볼까