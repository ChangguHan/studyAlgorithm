def solution(N, stages) :
    counts = {}
    # 1부터 총스테이지보다 하나 많은수까지
    for i in range(N+1) :
        i=i+1
        counts[i] = 0
    for j in stages :
        counts[j] += 1
    print(counts)

    # 총인원수
    people = {}
    ppValue = 0
    # 실패율
    succes = {}

    # [6, 5, 4, 3, 2, 1]
    for k in reversed(sorted(counts.keys())) :
        ppValue += counts[k]
        people[k] = ppValue
        # 현재 스테이지에 있는사람 없으면 실패율 0
        if counts[k] == 0 : succes[k] = 0
        elif ppValue==0 : succes[k] =0
        # 현재 스테이지에 있는 사람 있으면 현재 스테이지 사람수/지나간사람 전체
        else : succes[k] = counts[k] / ppValue
    print(succes)

    success = {}
    # 1,2,3,...,6
    for kk in sorted(succes.keys()) :
        success[kk] = succes[kk]
    # 가장 높은 스테이지 날림
    success.pop(N+1)

    result = []

    success_key_order = list(reversed(sorted(list(success.values()))))
    print(success)
    print(success_key_order)

    successke = list(success.keys())
    for ii in range(len(success_key_order)) :
        for jj in successke :
            if success[jj] == success_key_order[ii] :
                result.append(jj)
                successke.remove(jj)
                break

    return result

print(solution(5,[4,3,3,4]))