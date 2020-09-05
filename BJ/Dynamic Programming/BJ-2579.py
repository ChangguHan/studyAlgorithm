# GA : X
# DP : 점화식 구해보자
# 마지막 계단은 반드시밟아야하니까 그 이전까지 구하기
# 2칸으로 끝이나는 최대값 Sn 을 구하자
# Sn = max(bd[n] + Sn[n-2] (두칸하고 끝)
#        bd[n] + bd[n-2] + S[n-3]) (한칸 오르고 두칸 끝)

# 아 문제를 잘못본거였어,
# 마지막에 한칸을 가는게 아니라,
# 마지막을 찍어야한다는 거였어
# 그러면 이렇게 2로 끝나는거에서 1칸 가는경우와, 2칸가는 경우중 큰걸로하면되겠다

N = int(input())
bd = []
for i in range(N) :
    bd.append(int(input()))


if(N>3) :
    m = [0, bd[1], bd[2] + bd[0], bd[0] + bd[1] + bd[3]]
    for i in range(4, N - 1):
        mv = max(bd[i] + m[i - 2], bd[i] + bd[i - 2] + m[i - 3])
        m.append(mv)

    print(max(m[N-2] + bd[N-1],m[N-3]+bd[N-1],bd[N-1] + bd[N-3] +m[N-4] ))
else :
    if(N==1) : print(bd[0])
    elif(N==2) : print(bd[0]+bd[1])
    elif(N==3) : print(max(bd[0]+bd[2],bd[1]+bd[2]))

# 작은 값일때 처리 해주기