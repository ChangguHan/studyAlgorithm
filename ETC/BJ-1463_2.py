
a = int(input())
m = {1:0}

# def cal(input) :
#     if(input ==1) : return 0
#     elif(m.get(input) != None) : return m[input]
#     else :
#         try :
#             minCal = 1+cal(input-1)
#             if(input%3==0) : minCal = min(minCal, cal(input/3)+1)
#             if(input%2==0) : minCal = min(minCal, cal(input/2)+1)
#
#             m[input] = minCal
#         except :
#             return 1
#         return m[input]

for i in range(2,a+1) :
    minCal = 1 + m[i-1]
    if (i % 3 == 0): minCal = min(minCal, m[i / 3] + 1)
    if (i% 2 == 0): minCal = min(minCal, m[i/ 2] + 1)

    m[i] = minCal

print(m[a])

