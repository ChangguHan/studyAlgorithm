bills = [1,2,5,10,20,50]
money = 100
bills.sort(reverse=True)
count = 0

def recur(bill=0) :
    global money, count

    # if(money == 0 or bill == len(bills)-1) :
    #     count += 1
    #     return
    if (money == 0 or bill == len(bills)-1):
        count += 1
        return
    # if (bill < len(bills)):
    for i in range(int(money/bills[bill])+1) :
        money -= bills[bill] * i

        recur(bill+1)
        money += bills[bill] * i

recur()
print(count)