# 순열 1차원 기본문제
# input, print 구현에 문제가 중점된듯

# bfs로 풀어보자
inputL = []
while(True) :
    inputS = input()
    if(inputS == '0') : break

    inputL.append(list(map(int, inputS.split(" ")))[1:])

# print(inputL)

# inputL = [[1, 2, 3, 4, 5, 6, 7], [1, 2, 3, 5, 8, 13, 21, 34]]

def comb_bfs(li) :
    q = []
    result = []
    for i in range(len(li)) :
        q.append([str(li[i])])

    while(q) :
        each = q.pop(0)
        if(len(each) == 6) : result.append(each)

        ein = li.index(int(each[len(each)-1]))
        for i in range(ein + 1,len(li)) :
            each.append(str(li[i]))
            bu = each[:]
            q.append(bu)
            each.pop()

    return result

for i in inputL :
    for j in comb_bfs(i) :
        print(" ".join(j))
    print()
