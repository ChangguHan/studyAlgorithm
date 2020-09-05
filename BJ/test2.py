def solution(answer_sheet, sheets):
    answer = []
    # 각 수험자마다 0으로 만듬
    for i in sheets :
        answer.append(0)


    # 맞은건 우선 없애주자
    for eachSheet in range(len(sheets)):
        for testIndex in range(len(answer_sheet)) :
            if sheets[eachSheet][testIndex] ==answer_sheet[testIndex] :
                sheets[eachSheet] = sheets[eachSheet][:testIndex] + " " +sheets[eachSheet][testIndex+1:]



    for eachSheet in range(len(sheets)) :
        sheets2 = sheets[:eachSheet] + sheets[eachSheet+1:]
        eachCount = 0
        for eachSheet2 in sheets2 :
            maxSeries = 0
            series = 0
            each2Count=0
            for i in range(len(sheets[eachSheet])) :
                if sheets[eachSheet][i] == ' ' :
                    maxSeries = max(maxSeries, series)
                    series = 0
                    continue

                if sheets[eachSheet][i] == eachSheet2[i] :
                    # count 1세고, 연속하는지 확인
                    each2Count +=1
                    series += 1
                else :
                    maxSeries = max(maxSeries, series)
                    series = 0
            maxSeries = max(maxSeries, series)
            eachCount = max(eachCount, each2Count+maxSeries**2)
        answer[eachSheet] = eachCount


    return max(answer)

print(solution("53241",["53241", "42133", "53241", "14354"]))