
def a() :
    a = 1
    def b():
        return 2*a
    return b()

print(a())