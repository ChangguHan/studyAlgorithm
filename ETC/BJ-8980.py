# N, C = map(int, input().split(" "))
# bd = []
# for i in range(int(input())) :
#     bd.append(list(map(int, input().split(" "))))

N,C = 4,40
bd = [[3, 4, 20], [1, 2, 10], [1, 3, 20], [1, 4, 30], [2, 3, 10], [2, 4, 20]]
bd.sort(key=lambda x : (x[0],x[1]))
result = 0
truck = {}
total = 0

for i in bd :

    if(truck.get(i[0]) != None) :
        truck[i[0]] = 0
        result += truck[i[1]]
        total -= truck[i[1]]

    if (total >= C):
        continue
    elif (total + i[2] <= C):
        truck[i[1]] = i[2]
        total += i[2]
    else:
        truck[i[1]] = C - total
        total = C



print(total)