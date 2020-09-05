# 그냥 for 쓰면 안되나?
def sumL(list, posi) :
    rs = 0
    for i in range(posi[0], posi[2]+1) :
        for j in range(posi[1], posi[3]+1) :
            rs += list[i-1][j-1]
    return rs

N,M = map(int, input().split(" "))
bd = []
for i in range(N) :
    bd.append(list(map(int, input().split(" "))))
K = int(input())
posi = []
for i in range(K) : posi.append(list(map(int, input().split(" "))))

for i in range(K) :
    print(sumL(bd,posi[i]))

