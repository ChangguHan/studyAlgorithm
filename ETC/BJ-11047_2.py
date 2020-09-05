
# 왜 4로하면 안되냐면, 최대공약수가 100이 아니거든

M,N = map(int,input().split(" "))
bd = []
for i in range(M) :
    bd.append(int(input()))

bd.sort(reverse=True)
result = 0

for i in bd :
    if(N >= i) :
        result += int(N/i)
        N  = N%i
    if(N == 0) :
        break

print(result)

