import re

def rec(goal=1, x=[], pos=1, sum=0, tester=""):
    if (goal - sum < 0):
        return False
    if (pos >= len(x)):
        return True if (goal == sum) else False
    res = 0
    if pos == 1:
        res = rec(goal, x, pos+1, sum + int(x[pos]), tester=tester)
    else:
        res = rec(goal, x, pos+1, sum + int(x[pos]), tester=tester+"+") | rec(goal, x, pos+1, sum * int(x[pos]),tester=tester+"*")
    x[pos] = str(sum) + x[pos]
    res = res | rec(goal, x, pos+1, int(x[pos]), tester=tester+"|")
    x[pos] = x[pos][len(str(sum)):]
    return res

res = 0
x = []
for s in[*open("probset.txt")]:
    x.append(s.split(" "))
for i in range(0,len(x)):
    goal = int(x[i][0][:-1])
    if rec(goal, x[i], 1):
        #print(x[i])
        res += goal
    #print(x[i])
print(res)
