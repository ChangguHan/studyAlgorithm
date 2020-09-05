from collections import deque
# 동적이 불가능한 이유
# Sn = min(Sn-1, Sn+1, Sn/2)
# 여기서 Sn+1을 구할수가 없음.
# 단계적으로 나갈때 DP 사용

# 이 문제는 BFS로 모든경우 구해서 가장 빠른시간 구할수밖에

N,K = map(int, input().split(" "))
if(N > K) : print(N-K)
else :
    q = deque()
    q.append((N,0))
    m = []
    while q :
        eq = q.popleft()
        ex = eq[0]
        ei = eq[1]

        if(ex in m) :
            continue
        m.append(ex)
        if(ex == K) :
            print(ei)
            break

        # if(ei ==4) :
        #     print(1)

        if(ex+1 <= 100000 and ex+1 not in m and ex+1 not in q) :
            q.append((ex+1,ei+1))
        if (ex - 1 >=0 and ex - 1 not in m and ex - 1 not in q):
            q.append((ex - 1, ei + 1))
        if (ex*2 <= 100000 and ex*2 not in m and ex*2 not in q):
            q.append((ex*2, ei + 1))
