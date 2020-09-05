a = input()
a = a.split("-") # -로 나눔
# a = "55-100+22+22-100+200".split("-") # -로 나눔
result = 0
# 첫번째가 더하기로 이뤄질수있으니까, 그때 더해줌
first = a[0].split("+")
for each in first :
    result += int(each)


for i in range(1,len(a)) :
#     -이후에있는걸 한번 더나눔
    splitPlus = a[i].split("+")
    sum = 0
    for j in splitPlus :
        sum+=int(j)
    result -= sum

print(result)
