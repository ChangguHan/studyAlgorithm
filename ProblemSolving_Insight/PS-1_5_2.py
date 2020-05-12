
def payWay(money,num,count) :
    for i in range(int(money/paper[num])+1) :
        if money- i*paper[num] == 0:
            return 1
        elif money- i*paper[num] >0 and num<5:
            return payWay(money- i*paper[num],num+1, count)




global paper,m, count
count=0
paper = [50,20,10,5,2,1]
m = {}
print(payWay(100,0,count))
print(count)