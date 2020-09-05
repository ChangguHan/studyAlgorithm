# GA : 불가능
# DP
# 해당일을 할수도 있고 안할수도 있음 >> 마지막에 max 다시 돌려줘야함
# 뒤에서부터
# Sn = max (mv[n] + m[n + md[n]], (if md[n] < n)
#       m[n+1]


N = int(input())
md = []
mv = []
for i in range(N) :
    ip = tuple(map(int, input().split(" ")))
    md.append(ip[0])
    mv.append(ip[1])

m = []
if(md[N-1] == 1) : m.append(mv[N-1])
else : m.append(0)

for i in range(1,N) :
    eachDay = N-1-i
    if(md[eachDay] <= i+1) :
        if(i-md[eachDay]) == -1 :
            maxv = max(mv[eachDay] , m[i - 1])
        else :

            maxv = max(mv[eachDay] + m[i-md[eachDay]], m[i-1])
    else : maxv = m[i-1]
    m.append(maxv)

print(m[N-1])