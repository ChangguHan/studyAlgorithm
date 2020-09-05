# 두가지방법
# 3의배수 방법 이용하는거랑
# 물량적인 방법

num = input()
numList = []
for i in num :numList.append(i)
totalNumList = []
originNumListLen = len(numList);
beforeVal = 0
# for i in range(len(numList)) :
#
#     totalNumList = totalNumList[:originNumListLen-len(numList)]
#     totalNumList.append(numList[i])
#     numList2 = numList[:i] + numList[i + 1:]
#     if(len(numList2)==0) :
#         result = int("".join(totalNumList))%30
#         if(result == 0) :
#             if(beforeVal < result) : beforeVal = result
#     else :
#         for j in range(len(numList2)) :
#             numList3 = numList2[:j]+numList[j+1:]
#             totalNum
    # i,j,k join해서 30으로 나눠지는지확인
    # 나눠지면, 전에값이랑 비교, 더 크면 넣기
def recurFunc(numList) :
    global beforeVal
    global totalNumList
    for i in range(len(numList)) :
        totalNumList = totalNumList[:originNumListLen - len(numList)]
        totalNumList.append(numList[i])
        numList2 = numList[:i] + numList[i + 1:]
        if (len(numList2) == 0):
            result = int("".join(totalNumList))
            if (result % 30 == 0):
                if (beforeVal < result): beforeVal = result
        else:
            recurFunc(numList2)
recurFunc(numList)
if(beforeVal == 0 ) :print(-1)
else :print(beforeVal)
