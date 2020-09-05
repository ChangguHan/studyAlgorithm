# 알고리즘이 잘 안떠올리니까 처음에 한두개 해보자
# S0 = 1 0
# S1 = 0 1
# S2 = 1 1
# S3 = 1 2
# Sn = Sn-1 + Sn-2 (n>1)
bd = []
for i in range(int(input())) :
    bd.append(int(input()))

m = {0 : (1,0), 1 : (0,1)}
# def recur(num) :
#     if(m.get(num) != None) : return m.get(num)
#
#     return1 = recur(num-1)[0] + recur(num-2)[0]
#     return2 = recur(num-1)[1] + recur(num-2)[1]
#
#     return (return1, return2)

# 시간초과나니까 메모리제이션 말고 동적프로그래밍으로

for i in range(2,max(bd)+1) :
    m[i] = (m[i-1][0]+m[i-2][0],m[i-1][1]+m[i-2][1])

# for i in bd :
#     print(" ".join(map(str,recur(i))))

for i in bd :
    print(" ".join(map(str,m[i])))
