# GA로 각각 칸만다 해도될듯
N = int(input())
bd = []
for i in range(N) :
    bd.append(list(map(int,input().split(" "))))
m = [bd[0]]
for i in range(1,N) :
    el = []
    eachLen = len(bd[i])
    for j in range(eachLen) :
        if(j==0) : mv = m[i-1][j]
        elif(j==eachLen-1) : mv = m[i-1][j-1]
        else : mv = max(m[i-1][j], m[i-1][j-1])
        el.append(mv+bd[i][j])
    m.append(el)
print(max(m[N-1]))

