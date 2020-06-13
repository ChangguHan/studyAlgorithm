
# GA 가능하지않을까
# 4 3 3 5
# 3+3 + 3+3+4 + 3+3+4+5
# 3+4 + 3+5 +3+3+4+5




# def cal(N,list) :
#     if(N**(1/2) == int(N**(1/2))) :
#         loop = int(N**(1/2))
#     else : loop =  int(N**(1/2)) + 1
#     el = []
#     list.sort()
#     for i in range(loop+1) :
#         el.append([])
#     el[0] = list[:]
#     sum = 0
#
#     for i in range(1,loop+1) :
#         el[i-1].sort()
#
#         if(len(el[i-1])%2 == 0) :
#             listLen = int(len(el[i-1])/2)
#         else :
#             listLen = int(len(el[i-1])/2)+1
#
#         for j in range(listLen) :
#             if(j+1 == int(len(el[i-1])/2)+1) :
#                 el[i].append(el[i-1][j*2])
#             else :
#                 jj = j*2
#
#                 el[i].append(el[i-1][jj] + el[i-1][jj+1])
#                 sum += el[i-1][jj] + el[i-1][jj+1]
#
#     return sum

T = int(input())
TI = []
bd = []
for i in range(T) :
    TI.append(int(input()))
    bd.append(list(map(int, input().split(" "))))

for i in range(T) :
    print(cal(TI[i], bd[i]))


# 이렇게하면 문제가, 위에 큰수를 두개 더하는것보다
# 아래 수를 더해서 올라가서 구하는게 더 작을 수가 있음
# 예 : 1 1 1 10
# > 2, 11 > 13 : 26
# 다른방법, 1+1+1 +13 : 2 + 3 + 16 = 21

# 그러면 이럴땐
# 1,1,1,4 > 1+1+1+4 : 2 + 3 + 7 = 12
# 2,5 > 7 : 2 + 5 + 7 = 14

# 1,1,1,3 > 1+1+1+3 : 2 + 3 + 6 = 11
# 2 + 4 > 2 + 4 + 6 = 11

# 1,1,1,2 > 1+1 + 1+2 : 2 + 3 + 5 = 10
# 1+1+1+2 > 2+3+5 = 10

# 3,3,4,5 > 3,3 + 4,5 : 6 + 9 = 15 : 6+9+15 = 30
# 3+3+4+5 : 6+10+15 = 31
# 더한 수가 다음수보다 크면 따로해주는게 낫나?

# 3,3,6,9 > 6 + 15 : 6+15+21 = 42
# 3+3+6+9 > 6+6+9 = 6+12+21 = 42

# 3,3,7,9 > 6+16 : 6+16+22 = 44
# 3+3+7+9 > 6+13+22 = 41

# 3+3 *2 + 7 = 19
#

# 더한수가 다음 수보다 크면 다음수는 다음수랑 더하는것
# 더한수가 다음수보다 작으면 그냥 계속더해주는게 낫고

# Sn-1 > an : Sn-1 =
# Pn =
# Sn-1 < an : Sn = Sn-1 + an
# Pn = Pn-1 *2 + an

# an-2 + an-1 >= an
#   Sn = Sn-2 * 2 + (an-1+an)*2
# an-2 + an-1 < an
#   Sn = Sn-1*2 + an



# Sn = Sn-1

# 40 30 30
# 60 + 60 + 40