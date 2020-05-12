def solution(snapshots, transactions):
    usedID = []
    for i in transactions :
        if(usedID.count(i[0])!=0 ) : continue
        usedID.append(i[0])

        if(i[1] == "SAVE") :
            account = []
            for j in range(len(snapshots)) :
                if(snapshots[j][0] == i[2]) :
                    snapshots[j][1] = str(int(snapshots[j][1]) + int(i[3]))
                account.append(snapshots[j][0])
            if(account.count(i[2]) == 0) :
                snapshots.append([i[2],i[3]])
        elif(i[1]=="WITHDRAW") :
            account = []
            for j in range(len(snapshots)):
                if (snapshots[j][0] == i[2]):
                    snapshots[j][1] = str(int(snapshots[j][1]) - int(i[3]))
                account.append(snapshots[j][0])
            if (account.count(i[2]) == 0):
                snapshots.append([i[2], "-"+i[3]])


    return snapshots

snapshots =[  ["ACCOUNT1", "100"],  ["ACCOUNT2", "150"]]
transaction = [["1", "SAVE", "ACCOUNT2", "100"],["2", "WITHDRAW", "ACCOUNT1", "50"], ["1", "SAVE", "ACCOUNT2", "100"], ["4", "SAVE", "ACCOUNT3", "500"], ["3", "WITHDRAW", "ACCOUNT2", "30"]]
print(solution(snapshots, transaction))

