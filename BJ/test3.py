def solution(road, n):
    # 0보다 숫자가 더 많으면 return
    if (road.count('0') <= n ) : return len(road)

    # 0의 인덱스 구하자
    def getIndexOfZero(road) :
        indexOfZero = []
        for i in range(len(road)) :
            if road[i] == '0' : indexOfZero.append(i)
        return indexOfZero

    def calculateLen(road) :
        indexZero = getIndexOfZero(road)
        val = indexZero[0]
        for i in range(1,len(indexZero)-1) :
            val = max(val,indexZero[i]-indexZero[i-1]-1)
        val = max(val, len(road)-indexZero[len(indexZero)-1]-1)
        return val

    originZero = getIndexOfZero(road)


    return calculateLen(road)

    # result = []
    # zeroArr = []
    # def recurFunc(originZero,road,zero,n,result) :
    #
    #     for i in range(len(zero)):
    #         eachRoad = road[:originZero[i]] + "1" + road[originZero[i] + 1:]
    #         zero = zero[:i] + zero[i+1:]
    #         if (len(originZero) - len(zero) >= n):
    #             # result = max(result, calculateLen(eachRoad))
    #             result.append(calculateLen(eachRoad))
    #         else:
    #             recurFunc(originZero,eachRoad, zero,n,result)
    #
    # recurFunc(originZero,road, originZero, n,result)
    # print(result)


    # answer = -1
    # return answer

print(solution("111011110011111011111100011111",3))
# print(solution("111011110011111111111111111111",1))