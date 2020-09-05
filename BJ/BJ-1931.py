list = []
for i in range(int(input())) :
    a,b = map(int, input().split(' '))
    list.append([a,b])
print(list)
print(sorted(list, reverse=True, key=lambda list:list[1]))
print(list)