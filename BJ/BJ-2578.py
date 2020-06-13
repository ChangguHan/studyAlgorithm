xx = []
yy = []
zz = []
# # 매번 계산하는건 너무 오래걸림
# # 가로 5개, 세로 5개, 대각선 2개 리스트구해서
# # 해당 번호 들으면
#
for i in range(5) :
    xx.append(list(map(int,input().split(" "))))
for i in range(5) :
    eachList = []
    for j in range(5) :
        eachList.append(xx[j][i])
    yy.append(eachList)

el = []
for i in range(5) :
    el.append(xx[i][i])
zz.append(el)

el = []
for i in range(5) :
    el.append(xx[i][4-i])
zz.append(el)

# xx = [[11, 12, 2, 24, 10], [16, 1, 13, 3, 25], [6, 20, 5, 21, 17], [19, 4, 8, 14, 9], [22, 15, 7, 23, 18]]
# yy = [[11, 16, 6, 19, 22], [12, 1, 20, 4, 15], [2, 13, 5, 8, 7], [24, 3, 21, 14, 23], [10, 25, 17, 9, 18]]
# zz = [[11, 1, 5, 14, 18], [10, 3, 5, 4, 22]]
call = []
for i in range(5) :
    call.extend(list(map(int,input().split(" "))))
# call = [5, 10, 7, 16, 2, 4, 22, 8, 17, 13, 3, 18, 1, 6, 25, 12, 19, 23, 14, 21, 11, 24, 9, 20, 15]
x = [0,0,0,0,0]
y = [0,0,0,0,0]
z = [0,0]
for i in call :
    for j in range(5) :
        if(xx[j].count(i) > 0) :
            x[j] = x[j] +1
        if (yy[j].count(i) > 0):
            y[j] = y[j] + 1
    for j in range(2) :
        if(zz[j].count(i) > 0) :
            z[j] = z[j] + 1
    if(len(list(filter(lambda x : x>=5, x)))
    +len(list(filter(lambda x : x>=5, y)))
    +len(list(filter(lambda x : x>=5, z)))
     >= 3) :
        print(call.index(i)+1)
        break


