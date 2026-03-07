import numpy as np
x = []
count = 0
with open("testFile.txt", "r") as file:
    for line in file:
        x.append(list(line.strip()))
    xdir = [1, 0, -1]
    ydir = [1, 0, -1]
    prev_count = -1
    while prev_count != count:
        prev_count = count
        for i in range(0,len(x)):
            for j in range(0,len(x[i])):
                amount = 0
                if x[i][j] != "@":
                    continue
                for k in range(0,len(xdir)):
                    for l in range(0,len(ydir)):
                        if 0 > xdir[k]+i or ydir[l]+j < 0 or len(x) <= xdir[k]+i or ydir[l]+j >= len(x[i]):
                            continue
                        amount += x[xdir[k]+i][ydir[l]+j] == "@"
                if amount <= 4:
                    count += 1
                    x[i][j] = "."

print(count)
