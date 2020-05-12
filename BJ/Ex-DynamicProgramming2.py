def LCS(x,y) :
    i = len(x)
    j = len(y)
    result = []
    for k in range(i+1) :
        result.append([])

    for k in range(i+1) :
        for l in range(j+1) :
            # base value
            if k==0 or l==0 :
                result[k].append(0);
            #     둘이 만약 같으면
            elif x[k-1] == y[l-1] :
                result[k].append(result[k-1][l-1] +1)
            #     이제 둘이 다르면
            else  :
                result[k].append(max(result[k-1][l],result[k][l-1]))
    return result[i][j]

print(LCS('ABCBDAB','BDCABA'))