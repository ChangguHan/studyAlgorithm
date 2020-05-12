

class road :

    def __init__(self, list=[[0,0]]) :
        self.list = list
    def __repr__(self):
        return "-".join(map(str,self.list))
    def getPrice(self):

        price = 100
        for i in range(1,len(self.list)) :
            temp = self.list[i-1]
            try :
                temp2 =self.list[i+1]
            except :
                price += 100
            first =[self.list[i][0] - temp[0],self.list[i][1] - temp[1]]
            second = [temp2[0] - self.list[i][0],temp2[1] - self.list[i][1]]
            if(first == second) :
                price += 100
            else :
                if(i == len(self.list)-1) : continue
                price += 500
        return price
    def getList(self):
        return self.list

def getWay(input,roadList,complete) :

    N = len(input)-1
    result = []
    for i in roadList :
        eachRoadWay = i.list
        lastPosition = eachRoadWay[len(eachRoadWay) - 1]
        if (lastPosition == [N, N]):
            complete.append(i)
        else :
            # left
            if( lastPosition[0]-1 >= 0 and [lastPosition[0]-1,lastPosition[1]] not in eachRoadWay) :
                if(input[lastPosition[1]][lastPosition[0] - 1] == 0) :

                    eachRoadWay2 =eachRoadWay[:]
                    eachRoadWay2.append([lastPosition[0]-1,lastPosition[1]])
                    result.append(road(eachRoadWay2))
            # right
            if (lastPosition[0] + 1 <= N and [lastPosition[0]+1,lastPosition[1]] not in eachRoadWay):
                if(input[lastPosition[1]][ lastPosition[0] + 1] == 0) :
                    eachRoadWay2 = eachRoadWay[:]
                    eachRoadWay2.append([ lastPosition[0] + 1,lastPosition[1]])
                    result.append(road(eachRoadWay2))

            # top
            if (lastPosition[1] - 1 >= 0 and [lastPosition[0],lastPosition[1]-1] not in eachRoadWay):
                if(input[lastPosition[1]-1][ lastPosition[0]] == 0 ) :
                    eachRoadWay2 = eachRoadWay[:]
                    eachRoadWay2.append([lastPosition[0],lastPosition[1]-1])
                    result.append(road(eachRoadWay2))

            # bottom
            if (lastPosition[1] + 1 <= N and [lastPosition[0],lastPosition[1]+1] not in eachRoadWay):
                if(input[lastPosition[1]+1][ lastPosition[0]] == 0 ) :
                    eachRoadWay2 = eachRoadWay[:]
                    eachRoadWay2.append([lastPosition[0],lastPosition[1]+1])
                    result.append(road(eachRoadWay2))
    if(len(result) == 0) :
        print(11)
        return complete
    else :
        return getWay(input, result, complete)


# print(getWay([[0,0,0],[0,0,0],[0,0,0]],[road()],[]))
# print(len(getWay([[0,0,0],[0,0,0],[0,0,0]],[road()],[])))

def solution(board):
    wholecase = getWay(board,[road()],[])
    answer = wholecase[0].getPrice()
    for i in wholecase[1:] :
        answer = min(answer, i.getPrice())
    return answer

print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]))


# print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
# print(solution(["AA", "AB", "AC", "AA", "AC"]	))
# print(solution(["XYZ", "XYZ", "XYZ"]	))
# print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))

# print(gemsList(["AA", "AB", "AC", "AA", "AC"],1,1).getList())