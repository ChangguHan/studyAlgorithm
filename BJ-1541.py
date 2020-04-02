a = input().split("-")
result = int(a[0])
for i in range(1,len(a)) :
    mid = 0
    arr = a[i].split("+")
    for j in range(len(arr)) :
        mid+= int(arr[j])
    result-=mid
print(result)