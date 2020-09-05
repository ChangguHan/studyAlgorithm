
# GA X : 매 순간마다 최선의 선택을 할 수가 없잖아
# 반례 : 해당 순번이 아무것도 안고른게 더 클수가 있음

# Sn,l
# l==0 :max( Sn-1,1 Sn-1,2)
# l==1 : max (Sn-1,0 , Sn-1,2)
# l==2 : max (Sn-1,0 , Sn-1,1)

N = int(input())
eN = []
bd = []
for i in range(N) :
    eN.append(int(input()))
    el = []
    el.append(list(map(int,input().split(" "))))
    el.append(list(map(int, input().split(" "))))
    bd.append(el)

for i in range(N) :
    m0 = [0]
    m1 = [bd[i][0][0]]
    m2 = [bd[i][1][0]]

    for j in range(1,eN[i]) :
        m0.append(max(m0[j-1], m1[j-1], m2[j-1]))
        m1.append(max(m0[j-1], m2[j-1]) + bd[i][0][j])
        m2.append(max(m0[j-1], m1[j-1]) + bd[i][1][j])
        # print(1)
    print(max(m0[eN[i]-1], m1[eN[i]-1],m2[eN[i]-1]))



