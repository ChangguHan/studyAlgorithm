# 순열 1차원 기본문제
# input, print 구현에 문제가 중점된듯

inputL = []
while(True) :
    inputS = input()
    if(inputS == '0') : break

    inputL.append(list(map(int, inputS.split(" ")))[1:])

# print(inputL)

# inputL = [[1, 2, 3, 4, 5, 6, 7], [1, 2, 3, 5, 8, 13, 21, 34]]

def dfs(eachList) :
    global el,result
    el = eachList
    result = []
    comb()
    return result

def comb(pick = []) :
    if(len(pick) == 6) :
        bu = pick[:]
        result.append(bu)
        return

    if(len(pick)==0) :x=0
    else :
        x = el.index(int(pick[len(pick)-1])) +1

    for i in range(x,len(el)) :
        pick.append(str(el[i]))
        comb(pick)
        pick.pop()

for i in inputL :
    result = dfs(i)
    for j in result :
        print(" ".join(j))
    print()