
def solution(inputString) :
    gwalMap = {'(': ')', '{': '}', '[': ']', '<': '>'}
    gwalCount = 0
    for i in gwalMap:
        # 괄호 여는것 위치확인
        print(i)
        gwalIndex = inputString.find(i)
        gwalPairIndex = inputString.find(gwalMap[i])
        # 없으면 다음꺼 확인해보고 없으면 다음, 있으면 -1
        if (gwalIndex == -1):
            if gwalPairIndex != -1 : return -1
            else : continue
        else:

            if (gwalPairIndex == -1):
                return -1
            # 둘다 있을경우
            elif gwalPairIndex > gwalIndex:
                gwalCount += 1
                #        문자열지우기
                inputString = inputString[:gwalIndex] + inputString[gwalIndex + 1:]
                gwalPairIndex = inputString.find(gwalMap[i])
                inputString = inputString[:gwalPairIndex] + inputString[gwalPairIndex + 1:]
                print(inputString)
                gwalMapValue = gwalMap[i]
                del gwalMap[i]
                gwalMap[i] = gwalMapValue
                print(gwalMap)
            elif gwalIndex > gwalPairIndex:

                return -1

    return gwalCount




input = '>_<	'

print(solution(input))
