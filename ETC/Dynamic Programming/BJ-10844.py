# GA X
# DP : 우선 모르겠으니각각 해보자
# 결국 끝자리가 뭐냐에 따라 딸라짐
# 1 : 1,2,3,4,5,6,7,8,9
#  (0,1,1,1,1,1,1,1,1,1)
# 2 : 10,12,21,23,...
#  (1,1,2,2,2,2,2,2,2,1)
#3 (1,3,3,4,4,4,4,4,3,2)

# Sn,l = Sn-1,l-1 + Sn-1,l+1 (양 끝단 제외)
N = int(input())
m = [[0,1,1,1,1,1,1,1,1,1]]
for i in range(1,N) :
    el = []
    for j in range(10) :
        if(j == 0) : ee = m[i-1][j+1]
        elif (j==9) : ee = m[i-1][j-1]
        else : ee = m[i-1][j+1] +  m[i-1][j-1]
        el.append(ee)
    m.append(el)
print(sum(m[N-1])%1000000000)