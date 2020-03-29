def permutation(arr, r) :
    arr = sorted(arr)
    print('arr')
    print(arr)

    used = [0 for _ in range(len(arr))]

    print('used')
    print(used)


    def generate(chosen, used) :
        if len(chosen) == r:
            print(chosen)
            return

        for i in range(len(arr)) :
            if not used[i] :
                chosen.append(arr[i])
                used[i] = 1
                generate(chosen, used)
                used[i] = 0
                chosen.pop()
    generate([], used)

permutation('ABCD',2)

