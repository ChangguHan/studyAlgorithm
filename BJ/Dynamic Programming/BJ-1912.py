# 경우의 수를 구하는건 너무 많고
# 동적프로그래밍으로 구해야할 것 같은데
# if(b[n] >= 0) Sn = Sn-1 + b[n]
# else : Sn = Sn-1

# 이렇게하면 반례 : b[n] = -1, b[n+1] = 2 인경우
# 연속해서 더한것이 작았잖아

# 이런식으로 연속해서 계산해야하는 문제는
# DP로 각각의 위치에서 값을 구해준다음
# 최대값을 구해주면 됨
# 이때 각 위치에서부터 뒤로 연속한 것의 최대값은
# if(S[n-1] + b[n] > b[n]) : S[n] = S[n-1] + b[n]
# else :S[n] = b[n]
input()
bd = list(map(int,input().split(" ")))

m = [bd[0]]

for i in range(1, len(bd)) :
    if(bd[i] + m[i-1] < bd[i]) : m.append(bd[i])
    else : m.append(bd[i] + m[i-1])

print(max(m))
