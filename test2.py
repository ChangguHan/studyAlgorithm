arr = ['a','b','c','d','e','f']

def a(arr) :
    if (len(arr) == 0): return
    print(arr[0])
    del arr[0]
    a(arr)
#
# for i in range(len(arr)) :
#     arr2 = arr[:i] + arr[i+1:]
#     for j in range(len(arr2)) :
#         arr3 = arr2[:j] + arr2[j+1:]
#         for k in range(len(arr3)) :
#             arr4 = arr3[:k] + arr3[k+1:]
#             for x in range(len(arr4)) :
#                 print([arr[i],arr2[j],arr3[k],arr4[x]])


def b(input,arr,each,result) :

    if(len(arr)==0) :
        result.append(each)
        print('result')
        print(result)
        return result

    for i in range(len(arr)) :
        print('i')
        print(i)
        print('arr')
        print(arr)

        arr2 = arr[:i] + arr[i+1:]
        print('arr2')
        print(arr2)
        each = each[:(len(input)-len(arr))]
        print('eachbefore')
        print(each)

        each.append(arr[i])
        print('each')
        print(each)

        b(input,arr2,each,result)

print(b(arr,arr,[],[]))