 #케이스 나눠서 계산하면 될듯

N,M,K = map(int,input().split(" "))
result = 0

if(N <= M*2) :
    if(N%2 == 1) :
        y = M - int(N/2) + 1
        t = int(N/2)
    else :
        y = M - int(N/2)
        t = int(N/2)

else :
    y = N - M*2
    t = M

if(K > y) :
    print(int((3*t - (K-y))/3))
else :
    print(t)
