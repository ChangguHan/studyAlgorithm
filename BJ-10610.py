# 두가지방법
# 3의배수 방법 이용하는거랑
# 물량적인 방법

num = input()
numList = []
for i in num :numList.append(i)

if(numList.count('0') == 0) :
    print(-1)
else :
    sum=0
    numList.remove('0')
    for j in numList :
        sum+=int(j)
    if(sum%3==0) :
        numList.sort(reverse=True)
        print("".join(numList)+"0");

    else : print(-1)