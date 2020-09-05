item = [[60,10],[100,20],[120,30]]
# 맨 큰거 넣은경우랑 안넣은경우
# 그럼 재귀함수 써서 하면 돼긴해
weight=[50]
beforeValue = 0
value = [0]
result = -1
initItemLen = len(item)
def recurFunc(item) :
    global weight
    global initItemLen
    global value
    global beforeValue
    for i in range(len(item)) :
        newItem = item[:i] + item[i+1:]
        newWeight = weight[initItemLen - len(item)] - item[i][1]
        weight = weight[:initItemLen - len(item)+1]
        weight.append(newWeight)
        newValue = value[initItemLen - len(item)] + item[i][0]
        value = value[:initItemLen - len(item)+1]
        value.append(newValue)
        # 언제 중단하지?, 새로뺏는데 0일때, 혹은 0보다 작을때 빼기전
        # 그럼 어떤값을 가지고 나오지? price
        if newWeight<0 :
            newValue -= item[i][0]
            beforeValue = max(newValue, beforeValue)
            continue
        elif newWeight ==0 :
            beforeValue = max(newValue, beforeValue)
            continue
        else : recurFunc(newItem)
    return beforeValue
print(recurFunc(item))
# 다른방법은?, 동프 사용하면, 한번싸용한걸 빼야하는걸 구현해야하잖아
# 그럼 각각 빼고 안뺀거를 구별해서 구현해?