# 그리디방법
#     해당 문자열에서 옮겨다니면서 최대한 다른면을 찾음
# 정량적
#     앞에 뒤에 하나씩 붙여가면서 하면 될것같은데 이건 할필요 없겠다.
start, wanted = input().split(" ")
result = len(start)
for i in range(len(wanted)-len(start)+1) :
    eachResult=0
    for j in range(len(start)) :
        if start[j] != wanted[j+i] : eachResult +=1
        # print(i,j,eachResult)
    if(result > eachResult) : result = eachResult
print(result)