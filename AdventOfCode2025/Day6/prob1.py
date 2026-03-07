import re

lists = []
sum = 0
with open("probfile.txt", "r") as file:
    for line in file:
        x = re.split(r' +', line.strip())
        if len(lists) == 0:
            lists = [[] for i in range(len(x))]
        if x[0] == "*" or x[0] == "+":
            for i in range(len(lists)):
                oper = 0 if x[i] == "+" else 1
                for j in range(len(lists[i])):
                    if x[i] == "+":
                        oper += lists[i][j]
                    else:
                        oper *= lists[i][j]
                sum += oper
            break
        for i in range(len(x)):
            lists[i].append(int(x[i]))

print(sum)
