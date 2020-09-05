
# 동적다이나믹? 밑에서부터 1씩 올려서 가능한지?
# 근데 1개 사용하면 더이상 못쓰잖아
# 전체 조합을 가지고 하는방법
# 재귀함수 써서, 각각 가능한지?

input()
cl = list(map(int,input().split(" ")))
# cl = [3, 1, 6, 2, 7, 30, 1]
#
# def check(W, choo) :
#
#     if(W == 0) : return True
#     elif(W<0) : return False
#     elif(len(choo) <=0) : return False
#     else :
#         for i in range(len(choo)) :
#             ec = choo.pop(0)
#             if(check(W-ec,choo) == True) : return True
#             [ec].extend(choo)
# # i=0
# while(True) :
#     i += 1
#     if(check(i,cl) == False) : break

# print(i)



# print(cl)

# 이거 너무 복잡하게 하는것같아
# 순열 조합으로 가는거야
#
# cl.sort()
# result = []
# def comb(pick = [],N) :
#     if(len(pick) == 0) :
#         bu = pick[:]
#         result.append(bu)
#         return
#     if(len(pick))


# 정답
# n번째까지의 합이 n+1의 합보다 2이상 작으면 n번째까지 합 +1은 구할 수 없음


cl.sort()
m = 1
if(cl[0] == 1) :
    for i in range(1,len(cl)) :
        if(m+2 <=cl[i]) :
            break
        else :
            m += cl[i]
else : m=0

print(m+1)


