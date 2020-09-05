# DP로 각각 사기위해 경우의 수를 구하면 됨
# Sn = max(P1 + Sn-1,P2 + Sn-2 + ... Pn)

N = int(input())
bd = list(map(int,input().split(" ")))

m = [0]
for i in range(1,N+1) :
    mv = 0
    for j in range(1,i+1) :
        mv = max(mv, bd[j-1] + m[i-j] )
    m.append(mv)

print(m[N])