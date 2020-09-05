 # 가로를 2로 나눠서 하면더 어려워지는것같아
 # 다이나믹 프로그래밍 쓴다면
 # Sn = Sn-1 + Sn-2
m = {1 : 1, 2 : 2}
inp = int(input())
for i in range(3,inp+1) :
    m[i] = m[i-1] + m[i-2]
print(m[inp]%10007)
