import numpy as np
#fibonacci

def fib(n) :
    if(n<=2) : return 1
    elif (m[n]>0) : return m[n]
    else :
        m[n] = fib(n-1) + fib(n-2)
        return m[n]

global m
n=10
m = np.zeros(n+1)
print(fib(n))
print(m)