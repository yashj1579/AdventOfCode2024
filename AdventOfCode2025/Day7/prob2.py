
from collections import OrderedDict

lists = []
laser = []
with open("probfile.txt", "r") as file:
    for idx, line in enumerate(file):
        listss = []
        for k in line:
            listss.append(0 if k != "^" else -1)
        lists.append(listss)
        if line.find("S") != -1:
            laser.append((idx, line.find("S")))
            lists[laser[0][0]][laser[0][1]] = 1
while len(laser) != 0:
    #print(laser)
    x, y = laser.pop(0)
    if x+1 == len(lists):
        continue
    if lists[x+1][y] == -1:
        laser.append((x+1, y+1))
        laser.append((x+1, y-1))
        lists[x+1][y+1] += lists[x][y]
        lists[x+1][y-1] += lists[x][y]
    else:
        laser.append((x+1, y))
        lists[x+1][y] += lists[x][y]
    laser = list(OrderedDict.fromkeys(laser))
#for i in lists:
#    for j in i:
#        print(j, end=" ")
#    print()
count = 0
for i in lists[-1]:
    count += i
print(count)

