# 과목별 최소값을 구해서, 그게 같은 사람이면 제외, 아닐경우 답
# 루프돌면서, 한사람씩 떨어지
# 각각인원이 다른사람이랑 비교해서 떨어지는지 안떨어지는지 구하면 되지

# 근데 최대부터 빼면, 

# 정답까지 보고 내가 생각하는 문제가 맞는지 확인하자

# for i in range(int(input())) :

aList = []
bList = []
candidate = []
for j in range(int(input())) :
    a,b = input().split(" ")
    aList.append(int(a))
    bList.append(int(b))
    candidate.append((int(a),int(b)))
aMin = min(aList)
bMin = min(bList)

for each in candidate :
    if(each[0] == aMin) :
        if(each[1] == bMin) :
            candidate.remove(each)
print(len(candidate))

