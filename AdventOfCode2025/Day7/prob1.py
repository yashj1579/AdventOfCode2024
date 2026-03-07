
from collections import OrderedDict

lists = []
laser = []
with open("probfile.txt", "r") as file:
    for idx, line in enumerate(file):
        lists.append(list(line))
        if line.find("S") != -1:
            laser.append((idx, line.find("S")))
count = 0
while len(laser) != 0:
    #print(laser)
    x, y = laser.pop(0)
    if x+1 == len(lists):
        continue
    if lists[x+1][y] == "^":
        laser.append((x+1, y+1))
        laser.append((x+1, y-1))
        count += 1
    else:
        laser.append((x+1, y))
    laser = list(OrderedDict.fromkeys(laser))
print(count)

