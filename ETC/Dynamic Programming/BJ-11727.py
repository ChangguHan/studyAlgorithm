
# GA 불가능
# Sn = Sn-1 + Sn-2*2(n>=3)

m = [1,3]
N = int(input())
for i in range(2,N) :
    m.append(m[i-1] + m[i-2]*2)

print(m[N-1]%10007)