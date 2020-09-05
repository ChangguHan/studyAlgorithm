# input = '["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]';
# input = input.replace("[","").replace("]","").replace('"',"").replace(", ",",")
# input = input.split(",")
# inputArr = []
# for i in range(len(input)) :
#     inputArr.append(input[i].split(" "))
# idNameArr = {}
# for j in range(len(inputArr)) :
#     if(inputArr[j][0] != 'Leave') :
#         idNameArr[inputArr[j][1]] =inputArr[j][2]
# print(inputArr)
# result = []
# for k in inputArr :
#     if k[0] == "Enter" :
#         eachResult = idNameArr[k[1]]+"님이 들어왔습니다."
#         result.append(eachResult)
#     elif k[0] =="Leave" :
#         eachResult = idNameArr[k[1]]+"님이 나갔습니다."
#         result.append(eachResult)
# print(result)

def solution(input):
    input = input.replace("[","").replace("]","").replace('"',"").replace(", ",",")
    input = input.split(",")
    inputArr = []
    for i in range(len(input)) :
        inputArr.append(input[i].split(" "))
    idNameArr = {}
    for j in range(len(inputArr)) :
        if(inputArr[j][0] != 'Leave') :
            idNameArr[inputArr[j][1]] =inputArr[j][2]
    result = []
    for k in inputArr :
        if k[0] == "Enter" :
            eachResult = idNameArr[k[1]]+"님이 들어왔습니다."
            result.append(eachResult)
        elif k[0] =="Leave" :
            eachResult = idNameArr[k[1]]+"님이 나갔습니다."
            result.append(eachResult)
    return result

print(solution('["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]'))