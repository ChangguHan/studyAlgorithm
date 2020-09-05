def solution(v) :
    a=v
    distance = []
    calList = []
    for i in range(len(a)):
        # 각각 거리계산해서 가장 먼 두개끼리 중간값 구하자.
        b = a[:i] + a[i + 1:]
        for j in range(len(b)):
            distance.append((a[i][0] - b[j][0]) ** 2 + (a[i][1] - b[j][1]) ** 2)
            calList.append([a[i], b[j]])

    twoPoint = calList[distance.index(max(distance))]
    middlePoint = [(twoPoint[0][0] + twoPoint[1][0]) / 2, (twoPoint[0][1] + twoPoint[1][1]) / 2]
    b = a[:]
    for i in twoPoint:
        b.remove(i)
    answer = [int(middlePoint[0] + middlePoint[0] - b[0][0]), int(middlePoint[1] + middlePoint[1] - b[0][1])]

    return answer


print(solution([[1,4],[3,4],[3,10]]))
print(solution([[1,1],[2,2],[1,2]]))

# a = [[1,1],[2,2],[1,2]]
# distance = []
# calList = []
# for i in range(len(a)) :
#     # 각각 거리계산해서 가장 먼 두개끼리 중간값 구하자.
#     b = a[:i] + a[i+1:]
#     for j in range(len(b)) :
#         distance.append((a[i][0]-b[j][0])**2 + (a[i][1]-b[j][1])**2)
#         calList.append([a[i],b[j]])
#
# twoPoint = calList[distance.index(max(distance))]
# middlePoint = [(twoPoint[0][0]+twoPoint[1][0])/2,(twoPoint[0][1]+twoPoint[1][1])/2]
# b = a[:]
# for i in twoPoint :
#     b.remove(i)
# result = [int(middlePoint[0] + middlePoint[0]-b[0][0]), int(middlePoint[1] + middlePoint[1]-b[0][1])]

