# 이거에 대한 반례가 있나?
# 계산해보니까 없음
# cutt(n,l) = n*l -1

# 이거말고 DP로도 풀어보자
# Sn,l = min(Sn,l/2 + Sn,l/2 (짝수)
#        Sn,l/2+1 + S,l/2(홀수)) + 1
# 큰데로 자른자

n,l = map(int,input().split(" "))

m = {(0,0) : 0}
for i in range(n) :
    for j in range(l) :
        if(m.get((i,j)) != None) : continue
        if(i==0 ) : m[i,j] = j
        elif(j==0) : m[i,j] = i

        elif (j >= i) :
            if((j+1)%2 == 0) :
                m[(i,j)] = m[(i,((j+1)/2)-1)] *2 + 1
            else :
                m[(i,j)] =  m[(i,j/2)] + m[(i,j/2-1)] + 1
        else :
            if ((i+1) % 2 == 0):
                m[(i, j)] = m[((i+1)/2,j)] * 2 + 1
            else:
                m[(i, j)] = m[(i/2,j)] + m[(i/2-1,j)] + 1

print(m[n-1,l-1])