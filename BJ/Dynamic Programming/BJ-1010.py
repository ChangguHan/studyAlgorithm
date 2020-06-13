
# 다리가 꼬이면 문제가어려워지기 시작함
# 이런 문제는 조합일 확률이 큼
# nCr을 구하는 문제 >> DP
# nCr = n-1Cr + n-1Cr-1
# >> m[n,r] = m[n-1,r] + m[n-1,r-1]

N = int(input())
bd = []
for i in range(N) :
    bd.append(tuple(map(int,input().split(" "))))
m = {}
for i in range(N) :
    r,n = bd[i]
    for i in range(1,n+1) :
        for j in range(0,i+1) :
            if(m.get((i,j)) != None) : continue
            elif(j == 0) : m[(i,j)] = 1
            elif(j==1) :
                m[(i,j)] = i
                # print(1)
            elif(i==j) : m[(i,j)] = 1
            else :
                m[i,j] = m[i-1,j] + m[i-1,j-1]

            # print(1)
    print(m[n,r])