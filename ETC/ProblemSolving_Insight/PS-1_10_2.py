bills = [1,2,5,10,20,50]
money = 100
bills.sort(reverse=True)
count = 0
m = [{} for i in range(len(bills))]
def recur(count, money) :
    if m[count].get(money) != None : return m[count][money]
    if count == len(bills)-1 :
        m[count][money] = 1
        return 1
    num = int(money / bills[count])
    result = 0
    for i in range(num+1) :
        result += recur(count+1,money - bills[count]*i)
    m[count][money] = result
    return result

print(recur(0,money))