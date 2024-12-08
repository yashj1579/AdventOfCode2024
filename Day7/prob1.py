import re

def rec(goal=1, x=[], pos=0):
    if (goal < 0):
        return False
    if (pos <= 0):
        return True if (goal == 0) else False
    if goal / int(x[pos]) == goal // int(x[pos]):
        return rec(goal - int(x[pos]), x, pos-1) | rec(goal // int(x[pos]), x, pos-1)
    else:
        return rec(goal - int(x[pos]), x, pos - 1)

res = 0
x = []
for s in[*open("probset.txt")]:
    x.append(s.split(" "))
for i in range(0,len(x)):
    goal = int(x[i][0][:-1])
    if rec(goal, x[i], len(x[i])-1):
        res += goal
print(res)
