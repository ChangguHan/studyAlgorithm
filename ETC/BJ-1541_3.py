bd = input().split("-")
result = 0
for i in range(1,len(bd)) :
    result += sum(map(int,bd[i].split("+")))

print(sum(map(int,bd[0].split("+"))) - result)