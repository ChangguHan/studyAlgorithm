bd = [500,100,50,10,5,1]
m = 1000 - int(input())
c = 0
for i in bd :
    if(m>=i) :
        c += int(m/i)
        m = m%i
        # print(11)
print(c)