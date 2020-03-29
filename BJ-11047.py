coinTypeNumber, price = input().split(" ")
coinTypeNumber = int(coinTypeNumber)
price = int(price)
coinType = []
for i in range(coinTypeNumber) :
    coinType.append(int(input()))

coinType.sort(reverse=True)
# print(coinType)

result = 0

for i in coinType :
    each = int(price/i)
    result += each
    price -= i*each
# print(price)
print(result)