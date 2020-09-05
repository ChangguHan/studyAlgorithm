def payWay(money) :
    count = 0
    for i in range(int(money/paper[0])+1) :
        iMoney = money-i*paper[0]
        for j in range(int(iMoney/paper[1])+1) :
            jMoney = iMoney -j*paper[1]
            for k in range(int(jMoney/paper[2])+1) :
                kMoney = jMoney-k*paper[2]
                for l in range(int(kMoney/paper[3])+1) :
                    lMoney = kMoney - l*paper[3]

                    for m in range(int(lMoney / paper[4])+1):
                        mMoney = lMoney - m * paper[4]

                        if (mMoney/paper[5] >=0) : count+=1
    return count



global paper,m
paper = [50,20,10,5,2,1]
m = {}
print(payWay(100))