 # 글자 차이만큼 for 돌려서 글자 차이 구하면 될듯

a,b = input().split(" ")
mv = len(b)
for i in range(len(b)-len(a)+1) :
    rs = 0
    for j in range(len(a)) :
        if(a[j]!=b[j+i]) : rs +=1
    mv = min(rs, mv)
print(mv)
