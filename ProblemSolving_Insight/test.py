inL = [(i + 1) * 10 for i in range(10)]

# 숫자 인덱스로 값 저장 하는방법
def bfs() :
    q = []
    result = []
    # 큐 초기값 넣어줌
    for i in range(len(inL)) :
        q.append([i])

    while(q) :
        each = q.pop(0)
        if(len(each) == 3) :
            result.append(each)

        for i in range(each[len(each)-1]+1,len(inL)) :
            each.append(i)
            bu = each[:]
            q.append(bu)
            each.pop()

    return result

print(bfs())
print(len(bfs()))

# 값으로 저장하는 방법

# 인덱스로 해서 체크해서 있으면 넘기는 방법
# 값으로 해서 체크해서 있으면 넘기는 방법