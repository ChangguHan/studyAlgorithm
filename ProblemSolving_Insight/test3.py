def find_kind(list) :
    result = []
    for i in list :
        if(i not in result) :
            result.append(i)
    return result

def check_all(list, kind) :
    for i in kind :
        if(i not in list) : return False
    return True


class gemsList :

    def __init__(self, list=[],start=0,end=0) :
        self.list = list
        self.start = start
        self.end = end
    def __repr__(self):
        return "-".join(self.list)
    def getPosition(self):
        return [self.start, self.end]
    def getList(self):
        return self.list

def getAddList(gems,eachgemsList) :
    list = eachgemsList.list
    start = eachgemsList.start
    end = eachgemsList.end

    result = []

    if(end-1<len(gems)-1) :
        result.append(gemsList(gems[start-1:end+1],start,end+1))

    return result

def solution(gems):
    answer = []
    queue = []
    for i in range(len(gems)) :
        queue.append(gemsList([gems[i]],i+1,i+1))

    kindList = find_kind(gems)
    m = []

    while(queue) :
        each = queue.pop(0)
        # if(each.getPosition()== [3,3]) :
        #     print(11)
        if(check_all(each.getList(),kindList)) :
            return each.getPosition()
        elif(each.getPosition() not in m) :
        # elif (each.getList() not in m):
        # else :
            m.append(each.getList())
            queue.extend(getAddList(gems, each))


    return answer





print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]	))
# print(solution(["XYZ", "XYZ", "XYZ"]	))
# print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))

# print(gemsList(["AA", "AB", "AC", "AA", "AC"],1,1).getList())