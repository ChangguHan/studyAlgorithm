 # 경우의수 나눠서 해야함
 #
input()
crain = list(map(int,input().split(" ")))
crain.sort(reverse = True)
input()
box = list(map(int, input().split(" ")))
box.sort(reverse = True)

# 최대값이 작을경우, -1 출력
# 최대한 무거운걸 드는게 최소의 경우의수

if(crain[0] < box[0]) :
    print(-1)
else :
    result = 0
    while(box) :
        for eachCrain in crain :
            for eachBox in box :
                if(eachCrain < eachBox) :
                    continue
                else :
                    box.remove(eachBox)
                    break
        result += 1
    print(result)

