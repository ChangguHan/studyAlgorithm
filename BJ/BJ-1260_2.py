N,M,V = map(int,input().split(" "))
board = [[0 for i in range(N+1)] for i in range(N+1)]

for i in range(M) :
    a,b = map(int,input().split(" "))
    board[a][b] = 1
    board[b][a] = 1

print(board)
# print(N,M,V)
# print(board)

# N,M,V  = 4, 5, 1
# board = {1: [2, 3, 4], 2: [4], 3: [4]}


# DFS
# s = [V]
# rsDFS = []
# while(s) :
#     each = s.pop()
#     if (each not in rsDFS):
#         rsDFS.append(each)
#         list = board.get(each)
#         if(list != None) :
#             list.reverse()
#             for i in list :
#                 s.append(i)
#
# for i in range(len(rsDFS)) :
#     rsDFS[i] =str(rsDFS[i])
# print(" ".join(rsDFS))
#
#
#
# # BFS
# q = [V]
# rsBFS = []
# while(q) :
#     each = q.pop(0)
#     if (each not in rsBFS):
#         rsBFS.append(each)
#         list = board.get(each)
#         if(list != None) :
#             list.reverse()
#             for i in list :
#                 q.append(i)
#
# for i in range(len(rsBFS)) :
#     rsBFS[i] =str(rsBFS[i])
# print(" ".join(rsBFS))

