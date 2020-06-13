bd = []
for i in range(int(input())) :
    bd.append(int(input()))

bd.sort()
bl = len(bd)
mv = 0
for i in range(bl) :
    mv = max(mv,bd[i] * (bl-i))
    # print(11)

print(mv)