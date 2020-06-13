N, M = map(int,input().split(" "))
# N,M = 100,50
result = 1
# 경우 나눠서 해보자
if(N == 2) :

    result += int((M-1)/2)
    # 4번보다 적은경우
    if(result > 4) : result = 4

elif(N>2) :
    if(M-1 == 1) : result +=1
    elif(M-1 == 2) : result +=2
    elif(M-1==3 or M-1 == 4 or M-1 == 5 ) : result += 3
    elif(M-1 >= 6) : result +=M-3


print(result)