N = int(input())
app = []
for i in range(int(input())) :
    app.append(tuple(map(int,input().split(" "))));
turn = []
for i in range(int(input())) :
    turn.append(input().split(" "));


# N = 6
# app = [(3, 4), (2, 5), (5, 3)]
# turn = [['3', 'D'], ['15', 'L'], ['17', 'D']]

for i in range(len(app)) :
    app[i] = (app[i][0]-1,app[i][1]-1)

time = 0
pos = [(0,0)]
dx = [0,1,0,-1];
dy = [-1,0,1,0];
eq = turn.pop(0)
d = 1

while(True) :
    time += 1
    nx = pos[0][0] + dx[d%4]
    ny = pos[0][1]+dy[d%4]
    if (nx== -1 or nx == N or ny == -1 or ny == N): break
    head = (nx,ny)


    if (head in pos) :break

    if (head in app) :
        pos = [head].extend(pos)
    else :
        if(len(pos) == 1) : pos = [head]
        else :
            pos.pop()
            pos = [head].extend(pos)

    if (time == int(eq[0])):

        if(eq[1]=='D') : d += 1
        else : d -= 1
        if(len(turn)>0) :
            eq = turn.pop(0)


print(time)