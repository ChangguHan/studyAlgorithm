coinList = [500, 100, 50, 10, 5, 1 ]
coinList.sort(reverse=True)

change = 1000 -int(input())

coinNum = 0
for i in coinList :
    eachCoinNum = int(change/i)
    coinNum += eachCoinNum
    change -= i*eachCoinNum
print(coinNum)