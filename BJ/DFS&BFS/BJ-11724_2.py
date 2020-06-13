from collections import deque
# 그래프 탐색 문제

N,M = map(int, input().split(" "))
bd = [[] for _ in range(N+1)]
for _ in range(M) :
    a,b = map(int, input().split(" "))
    bd[a].append(b)
    bd[b].append(a)
m = []


def dfs(i) :
    q = deque([i])

    while q :
        eq = q.popleft()
        m.append(eq)

        for ebd in bd[eq] :
            if ebd not in m :
                q.append(ebd)


cnt = 0
for i in range(N) :
    if(i+1 in m) : continue
    dfs(i+1)
    cnt +=1

print(cnt)