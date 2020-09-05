
# 각 위치가 정답에 영향을 줄수도 있고 안줄수도있음
# >> DP에서 한번더 max 해줘야함
# Sn = max(if(bn > bn-i) :Sn-i + 1)

N = int(input())
bd = list(map(int, input().split(" ")))

m = [1]
for i in range(1,N) :
    mv = 1
    for j in range(i) :
        if(bd[i] > bd[j]) :
            mv = max(mv, m[j]+1)
    m.append(mv)
print(max(m))