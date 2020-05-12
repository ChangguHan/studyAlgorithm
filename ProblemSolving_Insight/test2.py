def solution(expression):
    cal = ['-','*','+']
    priorList = []
    for i in range(len(cal)) :
        result = []
        result.append(cal[i])
        cal2 = cal[0:i] + cal[i+1:len(cal)]
        for j in range(len(cal2)) :
            result2 = result[:]
            result2.append(cal2[j])

            cal3 = cal2[0:j] + cal2[j+1:len(cal2)]
            result2.append(cal3[0])
            priorList.append(result2)


    max = 0
    for each_prior in priorList :
        max = max(max,calculate(each_prior, expression))

    answer = max

    return answer



def calculate(priorList, expression) :

    list = []

    if(expression.find(priorList[0])!= -1) :

        expression = expression.split(priorList[0])
        temp = []
        for i in expression :
            temp.append(i)
            temp.append(priorList[0])
        temp.pop()
        expression = temp

    # if ("".join(expression).find(priorList[1]) != -1):
    temp = []
    for i in expression:

        for j in i.split(priorList[1]) :
            temp.append(j)
            if (i.find(priorList[1]) != -1):
                temp.append(priorList[1])
    if(not temp[len(temp)-1].isdigit()) : temp.pop()
    expression = temp

    # if ("".join(expression).find(priorList[2]) != -1):
    temp = []
    for i in expression:

        for j in i.split(priorList[2]):
            temp.append(j)
            if (i.find(priorList[2]) != -1):
                temp.append(priorList[2])
    if(not temp[len(temp)-1].isdigit()) : temp.pop()
    expression = temp


    list = expression

    if (len(list) == 1): return expression

    cal = priorList.pop(0)
    calIndex = list.index(cal)
    if(cal == '-') :
        result = list[calIndex-1] - list[calIndex+1]
    elif (cal == '+') :
        result =list[calIndex-1] + list[calIndex+1]
    elif (cal == '*') :
        result = list[calIndex-1] * list[calIndex+1]

    list.pop(calIndex-1)
    list.pop(calIndex )
    list.pop(calIndex + 1)

    list.insert(calIndex-1,result)

    expression = "".join(list)


    calculate(priorList,expression)


print(calculate(['-','*','+'],"100-200-300*500-400+299"))