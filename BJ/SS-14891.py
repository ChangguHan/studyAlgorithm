# top = []
# for i in range(4) :
#     top.append(input())
# cont = []
# for i in range(int(input())) :
#     cont.append(tuple(map(int, input.split(" "))))

top = ['10101111','01111101','11001110','00000010']
cont = [(3,-1),(1,1)]

def turnCase(i,wise) :
    # 오른방향
    if (i ==0 and i ==3) : top[i] = turnTop(top[i], wise)

    if i<3 and top[i][2] != top[i+1][6] :
        turnCase(i+1,wise*-1)
        # top[i+1] = turnTop(top[i+1],wise*-1)

    if i >0 and top[i][6] != top[i-1][2]:
        turnCase(i-1,wise*-1)
        # top[i-1] = turnTop(top[i - 1], wise * -1)




def turnTop(eachTop, wise) :
    N = len(eachTop)
    if(wise == 1) : return eachTop[N-1] +eachTop[:N-1]
    elif(wise == -1) : return eachTop[1:N] + eachTop[0]


for each in cont:
    turnCase(each[0], each[1])

# 점수
result = 0
if top[0][0] == '1' : result +=1
if top[1][0] == '1' : result +=2
if top[2][0] == '1' : result +=4
if top[3][0] == '1' : result +=8

print(result)