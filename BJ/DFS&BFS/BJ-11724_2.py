# 연결요소 개수 정
from collections import deque
import sys
# 그래프 탐색 문제

N, M = map(int, sys.stdin.readline().split(" "))
bd = [[] for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, sys.stdin.readline().split(" "))
    bd[a].append(b)
    bd[b].append(a)
m = [0] * (N+1)


def dfs(i):
    q = deque([i])
    m[i] = 1

    while q:
        eq = q.popleft()


        for ebd in bd[eq]:
            if m[ebd] == 0 :
                q.append(ebd)
                m[ebd] = 1


cnt = 0
for i in range(N):
    if (m[i+1] == 1): continue
    dfs(i + 1)
    cnt += 1

print(cnt)