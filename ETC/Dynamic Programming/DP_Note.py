
# 조합의 개수 DP로 구현하는 것이 생각보다 오래걸림
# 여기서 한번 정리하고 넘어가자


n,r = 6,4
m = {}
for i in range(1,n+1) :
    for j in range(1,i+1) :
        if(j==0) : v = 0
        elif(j==1) : v = i
        elif(j==i) : v=1
        else :
            v = m[i-1,j] + m[i-1,j-1]
        m[i,j] = v
print(m[n,r])