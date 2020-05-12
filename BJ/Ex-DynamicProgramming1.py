p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

def cutRod(p, n) :
    r=[0]
    for i in range(1,n+1) :
        q = -1
        for j in range(1,i+1) :
            q = max(q,p[j]+r[i-j])
        r.append(q)
    return r[n]

print(cutRod(p, 4))
