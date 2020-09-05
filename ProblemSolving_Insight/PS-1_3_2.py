import numpy as np
def choose(n, r) :
    if( r == 0 or n ==1 or n==r) : return 1
    if(m[n-1][r-1] != 0) : return m[n-1][r-1]
    else :
        m[n-1][r-1] =choose(n-1,r-1) + choose(n-1,r)
    return m[n-1][r-1]
global m
n = 4
r = 2
m = np.zeros((n,r))
print(choose(n,r))
print(m)