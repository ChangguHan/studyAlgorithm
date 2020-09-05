 # 3의 배수니까 더해서 3이 되는지 먼저 체크 안되면 -1
bd = []
n = str(input())
check = 0
for i in range(len(n)) :
    check += int(n[i])
    bd.append(int(n[i]))
if(check%3 != 0 or 0 not in bd) : print(-1)
else :
    bd.sort(reverse=True)
    bd = list(map(str,bd))
    print(int("".join(bd)))