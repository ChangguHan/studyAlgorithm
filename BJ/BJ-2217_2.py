ropeList = []
for i in range(int(input())) :
    ropeList.append(int(input()))

# 최소값이나 최대값을 구하는거면, 재귀함수대신 정렬을 사용해풀수있음

ropeList.sort()
max = 0;
for i in range(len(ropeList)) :
    eachVal = ropeList[i]*(len(ropeList)-i)
    if(max<eachVal) : max=eachVal
print(max)