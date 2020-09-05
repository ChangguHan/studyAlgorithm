# 가장 가까운곳을 두개 선택해서 거기만 제외

N,M,K = map(int,input().split(" "))
bd = list(map(int,input().split(" ")))
minbd = []
# 최소값 구하기 랭킹 구하기
for i in range(len(bd)) :
    if(i ==0) :
        minbd.append( bd[i+1] - bd[i] )
    elif(i == len(bd)-1) :
        minbd.append(bd[i] -  bd[i-1])
    else :
        minbd.append(min( bd[i+1] - bd[i],bd[i] - bd[i-1]))

minv = minbd[:]
minv.sort(reverse=True)
result = []
for i in range(K) : result.append("0")
for i in range(M) :
    minvalIndex = minbd.index(minv[i])
    minbd[minvalIndex] = 1000001
    result[minvalIndex] = "1"

print("".join(result))



