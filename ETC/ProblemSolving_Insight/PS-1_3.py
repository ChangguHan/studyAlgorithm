def choose(n, r) :

    try :
        if m[n][r] >0 :
            return m[n][r]
    except :
        print(11)
    if (n == r or r== 0):
        m[n][r] = 1
        return m[n][r]
    print(m)
    m[n][r] = choose(n - 1, r - 1) + choose(n-1, r)
    return m[n][r]

global m
m = []
n = 4
r = 2
for i in range(n+1) :
    for j in range(r+1) :
        if(j==0) : insertList = [0]
        else : insertList.append(0)
    m.append(insertList)
print(choose(4,2))


