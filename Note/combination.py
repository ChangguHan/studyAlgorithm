# 조합 : 재귀, 스택, 큐로 사용할 수 있다
# 경우의수 개수가 필요한경우, 각각을 선택했을때 필요한 경우

input = list(range(10))
pickNum = 3

# 재귀로 풀기 1
result = []
def recur(num=0,pick = []) :
    if(len(pick) == pickNum) :
        backup = pick[:]
        result.append(backup)
        return

    for i in range(num,len(input)) :
        pick.append(input[i])
        recur(i+1, pick)
        pick.pop()
recur()
print(result)
print(len(result))

# 재귀로 풀기2
# 변수로 하나는 다음 위치를 위해 들어가야돼, 그리고 다른 하나는 지금까지 나온 결과를 기록하기 위해 들어가야돼
# return 에 하나 넣어서 이걸 줄일 수 있을까?
result = []
def recur(each = []) :
    if(len(each) == 0) : num = 0
    else : num = each[len(each)-1]+1

    if(len(each) == 3) :
        backup = each[:]
        result.append(backup)
        return

    for i in range(num,len(input)) :
        each.append(i)
        recur(each)
        each.pop()

recur()
print(result)
print(len(result))

# 재귀로풀기 3
# 좌표중에 3개 뽑아야하는 경우
input = [[0 for i in range(10)] for j in range(10)]
result = []

def recur(x,y,pick) :
    if(len(pick) == 3) :
        backup = pick[:]
        result.append(backup)
        return

    for j in range(y, len(input)) :
        for i in range(x, len(input[0])) :
            pick.append((i,j))
            recur(i+1,j,pick)
            pick.pop()
        x=0
recur(0,0,[])
print(result)
print(len(result))