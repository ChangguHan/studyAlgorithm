
# 최대값이 전거를 이용할수가 있나?
# 각 케이스별로 나눠야함 : 전에 볼륨을 올린경우, 내린경우
# Sn = Sn-1,0 Sn-1,1
# [3 +5, -1], [3+5+3, 3+5-3], [3+5+3+7, 3+5+3-7, 3+5-3+7, 3
# 왜이렇게 뭔가가 찝찝하지
# 우선 문제구현해보자




# N,S,M = map(int, input().split(" "))
# bd = list(map(int, input().split(" ")))

# m = []
# for i in range(N) : m.append([])
#
# if(S + bd[0] >10) : m[0].append(-1)
# else : m[0].append(S + bd[0])
#
# if(S - bd[0] <0) : m[0].append(-1)
# else : m[0].append(S - bd[0])
#
# for i in range(1,N) :
#     if(m[i-1][0] >= 0) :
#         plusPlus = m[i-1][0] + bd[i]
#         plusMinus = m[i-1][0] - bd[i]
#     else :
#         plusPlus = -1
#         plusMinus = -1
#
#     if (m[i - 1][1] >= 0):
#         subPlus =m[i-1][1] + bd[i]
#         subMinus = m[i-1][1] - bd[i]
#     else :
#         subPlus = -1
#         subMinus = -1
#
#     if(plusPlus >10) : plusPlus = -1
#     if (subPlus > 10): subPlus = -1
#
#     m[i].append(max(plusPlus, subPlus))
#     m[i].append(max(plusMinus, subMinus))
#
# print(max(m[N-1]))


# 전전에 볼륨을 내리고, 전에 볼륨을 올린경우인데
# 전전에 볼륨을 올리고, 전에 볼륨을 올려서
# 최대값이 안되서 값으로 선정되지 않았지만
# 이번과 숫자가 딱 맞아서 최대값이 될수도 있잖아

# 그럼 숫자가 딱맞을수 있는 경우를 찾아보자

# S(n,S(n-1,i) + bd[n]) = true or false

N,S,M = map(int, input().split(" "))
bd = list(map(int, input().split(" ")))

m = []
for i in range(N) :
    m.append([-1]*(M+1))

if(S+bd[0] >=0 and S+bd[0] <=M) :
    m[0][S+bd[0]] = 1
if (S - bd[0] >= 0 and S - bd[0] <= M):
    m[0][S - bd[0]] = 1

for i in range(1,N) :
    for j in range(len(m[i])) :
        # 더할때
        if(j-bd[i] >=0 and j-bd[i] <=M ) :
            if(m[i-1][j-bd[i]] == 1) :
                m[i][j] =1
        # 뺄때
        if (j+bd[i] >=0 and j+bd[i] <=M) :
            if (m[i - 1][j + bd[i]] == 1):
                m[i][j] = 1
        # if(i==2 and j==10) :
        #     print(1)
switch = -1
for i in range(M+1) :
    if(m[N-1][M-i] == 1) :
        switch = M-i
        break
print(switch)