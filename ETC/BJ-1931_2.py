bd = []
for i in range(int(input())) :
    bd.append(tuple(map(int,input().split(" "))))

bd.sort(key=lambda x : (x[1],x[0]))

end = 0
result = 0
for i in bd :
    if(end<=i[0]) :
        end = i[1]
        result += 1

print(result)