
# 모르겠으니 우선 어떻게 구하는지 보자
# 1 1 1 2 2 3 4 5 7 9 12
# 12 : 9 + 3(10 + 6)
# 9 : 7 + 2(9 + 5)
# 점화식 : Sn = Sn-1 + Sn-5(n>6)


N = int(input())
bd = []
for i in range(N) :
    bd.append(int(input()))

m = [1,1,1,2,2]

if(max(bd) > 5) :
    for i in range(5,max(bd)) :
        m.append(m[i-1] + m[i-5])
for i in bd :
    print(m[i-1])

