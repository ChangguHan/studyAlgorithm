
# 그 숫자보다 바로 낮은수는 안통할 수가 있어
# 예 : 12 : 9 + 1 + 1 + 1
# 답 : 12 : 8 + 4

# 그렇다고 바로 점화식으로 바로 아래숫자로 나눌수도 없고...

# Pn = i^2 + P(n-i^2) ((i:1~n보다 작은수))

N = int(input())

m = [0,1]

for i in range(2,N+1) :
    mv = i
    for j in range(1,int(i**(1/2))+1) :
        mv = min(mv,m[i-j*j]+1)
        # if(i==2) :
        #     print(1)
    m.append(mv)
print(m[N])

