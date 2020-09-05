# Fibonacci

def fib(n) :
    if(m[n] > 0) : return m[n]
    if(n == 1 or n== 2) :
        m[n] = 1
        return m[n]
    m[n] = fib(n-1) + fib(n-2)
    return m[n]


global m
m = []

n = 10
for i in range(n+1) : m.append(0)
print(fib(n))
print(m)