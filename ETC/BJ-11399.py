input()
input = input().split(" ")
inputMap = {}
for i in range(len(input)) :
    inputMap[i] = int(input[i])

def johap(input) :

    initArray = input[:]
    result = []
    each = []

    def calJohap (initArray,input,each,result) :
        for i in range(len(input)) :
            each = each[:(len(initArray)-len(input))]
            each.append(input[i])
            input2 = input[:i] + input[i+1:]

            # print('input2')
            # print(input2)

            if (len(input2) == 0):
                # 마지막에 결과값에 집어넣기
                result.append(each)
                continue
            else :
                calJohap(initArray,input2, each, result)

        return result



    return calJohap(initArray, input,each,result)
    # return addAll(input)


def addAll(arr):
    result = 0
    for i in range(len(arr)):
        result += int(arr[i]) * (len(arr) - i)
    return result
johapList = johap(input)
beforeVal = addAll(johapList[0])
for i in johap(input) :
    val = addAll(i)
    if(beforeVal>val) :
        beforeVal = val
print(beforeVal)