
# 이건 진짜 어떻게할지 감도 안옴
# 직접 해보는 수밖에
# 1 : 0,1,2,3,4,5,6,7,8,9
# 2 : 00,01,02, ..., 09, 11~19, 22~29, ... 99
# 3 : 000,001,...099, 111, 112, 113, ...

# S1 : a1,0 ~a1,9
# S2 : a2,0 : a1,0~a1,9, a2,1 : a1,1~a1,9, ...

# an,l = an-1,(l~9)
# 그리고 마지막에 print(an,l(l=0~9))

N = int(input())
m = []
for i in range(N) :
    m.append([])
m[0] = [1,1,1,1,1,1,1,1,1,1]

for i in range(1,N) :
    for j in range(10) :
        sv = 0
        for k in range(j,10) :
            sv += m[i-1][k]
        m[i].append(sv)

print(sum(m[N-1])%10007)