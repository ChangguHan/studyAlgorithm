##으아 모르겠다


meetingTime = [];
for i in range(int(input())) :
    a,b = input().split(' ')
    meetingTime.append([int(a), int(b)])
print(meetingTime)
# beforeCount = 0
# initialListLength = len(meetingTime)
# for i in range(len(meetingTime)) :
#     # meetingTime에서 방금 쓴거 빼기.
#     count = initialListLength - len(meetingTime)
#     meetingTime2 = meetingTime[:i] + meetingTime[i + 1:]
#     for j in range(len(meetingTime2)) :
#         # 조건 맞으면 카운트 1 챙기고,
#         if (meetingTime2[j][0] > meetingTime[i][1]):
#             count=initialListLength - len(meetingTime2)
#             meetingTime3 = meetingTime2[:j] + meetingTime2[j + 1:]
#             #아직 meetingTime 남아있으면 다음꺼 고
#             if(meetingTime3.length ==0) :
#                 if(beforeCount < count) : beforeCount = count
#             else :
#                 for k in


def countMeeting(meetingTimeList) :
    beforeCount = 0
    initialListLength = len(meetingTimeList)
    def returnFunc(meetingTime2,beforeSecondValue) :
        eachCount = 0
        for j in range(len(meetingTime2)) :
            if(meetingTime2[j][0] > beforeSecondValue) :
                count = initialListLength - len(meetingTime2)
                meetingTime3 = meetingTime2[:j] + meetingTime2[j+1:]
                if(len(meetingTime3) == 0) :
                    if(beforeCount < count) :
                        beforeCount = count
                else : returnFunc(meetingTime3, meetingTime2[j][1])
            else : eachCount +=1
        if(eachCount == len(meetingTime2)) :
            if (beforeCount < count):
                beforeCount = count
    for i in range(initialListLength) :

        count =len(meetingTimeList) - initialListLength
        print(count)
        meetingTimeList2 = meetingTimeList[:i]+meetingTimeList[i+1:]
        returnFunc(meetingTimeList2,meetingTimeList[i][1])
    print(beforeCount)

countMeeting(meetingTime)