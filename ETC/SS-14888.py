import sys
input()
num = list(map(int, input().split(" ")))
oper = list(map(int, input().split(" ")))

# num = list(map(int, "5 6".split(" ")))
# oper = list(map(int, "0 0 1 0".split(" ")))
minimum = sys.maxsize
maximum = sys.maxsize * -1
def bfs(result, count) :
    global minimum, maximum

    if(count == len(num)) :
        if (minimum > result) : minimum = result
        if (maximum < result) : maximum = result


    for i in range(4) :
        if(oper[i] != 0) :
            oper[i] -= 1
            if(i == 0) :
                bfs(result+num[count],count+1)
            elif(i==1) : bfs(result-num[count],count+1)
            elif (i == 2):
                bfs(result * num[count], count + 1)
            elif (i == 3):
                if(result <0) :
                    bfs((int((result*-1) / num[count]))*-1, count + 1)
                else :
                    bfs(int(result / num[count]), count + 1)
            oper[i] += 1


bfs(num[0],1)
print(maximum)
print(minimum)
