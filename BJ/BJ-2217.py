ropeList = []
for i in range(int(input())) :
    ropeList.append(int(input()))

# print(ropeList)

# 1. 모두 썻을때 최대중량구함
# 2. 하나씩 빼면서 최대중량 구함
# 3. 각자 최대값구해서 지정해줌


beforeValue = 0
maxValue = min(ropeList)*len(ropeList)
if(beforeValue < maxValue) : beforeValue = maxValue

def recurFunc(ropeList) :
    global beforeValue
    for i in range(len(ropeList)) :
        ropeList2 = ropeList[:i] + ropeList[i+1:]
        maxValue = min(ropeList2) * len(ropeList2)
        if (beforeValue < maxValue): beforeValue = maxValue

        if (len(ropeList2) > 1):
            recurFunc(ropeList2)


recurFunc(ropeList)

print(beforeValue)

#
# for i in range(len(ropeList)) :
#     ropeList2 = ropeList[:i] + ropeList[i+1:]
#     maxValue = min(ropeList2) * ropeList2
#     if (beforeValue < maxValue): beforeValue = maxValue
#
#     #만약 ropeList2가 길이가 1이상이면, 계속 실행
#     if(len(ropeList2)>1) :
#         for j in range(len(ropeList2))