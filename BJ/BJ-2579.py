
# 마지막 하나 더하니까, 이전까지 점수 + 마지막 계단으로 구하자
# 그럼 Sn = max(Sn-1 + b[n-1], Sn-2 +b[n-2])의 점화식
# S1 = b[1]
# S2 = max(b[1],b[2])
# S3 = ...

# bd = []
# for i in range(int(input())) : bd.append(int(input()))
#
# m = [bd[0],max(bd[0],bd[1])]
# for i in range(2,len(bd)-1) :
#     mv = max(m[i-1] + bd[i-1], m[i-2]+bd[i-2])
#     m.append(mv)
#
# print(m[len(bd)-2] + bd[len(bd)-1])

# 아니 근데 잠만, 이건 2칸을 신경안쓴거잖아/...
# 2칸신경쓰면 멘붕...

# 한칸씩 두버밟을수 있는거잖아
# 그럼 마지막 종료전 두칸밟고 한칸을 밟거나, 한칸밟고 두칸밟아야되잖아
# 그럼 이전 경우의 수를 보자고
# S5는 1칸씩 연속해서 두번을 밟아서 오는 경우의 수가 없잖아

# 맨 마지막전까지 일반적으로 갈수 있는 경우의 수를 구하는데
# 2칸이라는 것이 있으니까 끝이 2라는 것을 정하자
# Sn = bn + bn-2 + bn-3 + Sn-4(한칸 두번 가고 두칸 한번 간 경우)
# Sn = bn + bn-2 + Sn-3(한칸 한번, 두칸 한번)
# Sn = bn + Sn-2 (그냥 두칸 한번)
# (끝이 두칸으로 끝나는 경우 중 최대인 경우)
# Sn =max(bn + bn-2 + bn-3 + Sn-4, bn + bn-2 + Sn-3,
# bn+Sn-2)
# 그럼 정답은 한칸, 한칸한칸 이 있겠군
# Cn = max(bn + Sn-1, bn + bn-1 + Sn-2)

bd = []
N = int(input())
for i in range(N) : bd.append(int(input()))

m = []
for i in range(N) :
    if(i==0) : m.append(0)
    elif(i==1) : m.append(bd[1])
    elif(i==2) : m.append(bd[0]+bd[2])
    elif(i==3) : m.append(bd[3]+bd[1]+bd[0])

# m = [0,bd[1],bd[0]+bd[2], bd[3]+bd[1],bd[4]+bd[2]+bd[1]]
for i in range(4,N-1) :
    mv = max(bd[i] + bd[i-2] + m[i-3],
    bd[i] + m[i-2])
    m.append(mv)

print(max(bd[N-1] + m[N-2],bd[N-1]+m[N-3]))

# print(bd[len(bd)-1] + m[len(bd)-2])
# print(bd[len(bd)-1] + bd[len(bd)-2] + m[len(bd)-3])
