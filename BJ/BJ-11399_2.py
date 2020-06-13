
# 뒤에사람은 앞에사람 하는걸 기다려야돼
# 그니까 우선 빠르게 시작하는게 낫지 >> 그리디 알고리즘

input()
bd = list(map(int,input().split(" ")))
bd.sort()
result = 0
for i in range(len(bd)) :

    if(i>=1) :
        for j in range(i) :
            result += bd[j]
    result += bd[i]

print(result)