
# lcs(i,j) = if(bd[i] == bd[j] : lcs(i-1,j-1) + 1
# else : max(lcs(i-1,j), lcs(i,j-1))

ta = input()
tb = input()

lena = len(ta)
lenb = len(tb)

m = {}
a = 0
for i in range(lenb) :

    if(ta[0] == tb[i]) : a=1
    m[0,i] = a
a = 0
for j in range(lena) :

    if(ta[j] == tb[0]) : a=1
    m[j,0] = 1

for i in range(1,lena) :
    for j in range(1,lenb) :
        mv = 0
        if(ta[i] == tb[j]) : mv = max(mv, m[(i-1,j-1)] + 1)
        mv = max(mv, m[(i-1,j)],m[(i,j-1)])
        m[(i,j)] = mv

print(m[lena-1, lenb-1])