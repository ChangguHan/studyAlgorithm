
# 각 부등호 세서, 규칙을 적용하면 되지 않을까
# 최대값 : <개수 새서, 9-n으로 시작하면돼지
#  >갯수는 셀필요가 없음, 얼마든지 할수 있으니까
# 최소값 : >갯수 새서, 넣으면됨

# 어렵다 패스...

N = int(input())
bd = list(input().split(" "))

ct1 = bd.count(">")
ct2 = bd.count("<")

maxv = []
minv = []

maxli = [0,1,2,3,4,5,6,7,8,9]
minli = maxli[:]
maxli.sort(reverse=True)

def checkSeries(li,ch) :

    for i in range(len(li)+1) :
        if(li[i] != ch) : return i


# 연속되냐안되느냐가 중요하네
for i in N :
    if(bd[i] == ">") :
        bn = checkSeries(bd,">")
        maxv.append(maxli[bn])
        minli.append(minli[bn])
        maxli.pop(bn)
        minli.pop(bn)

    else :
        bn = checkSeries(bd, "<")
        maxv.append(maxli[bn])
        minli.append(minli[bn])
        maxli.pop(bn)
        minli.pop(bn)


print(checkSeries(["<","<",">"],">"))