import re
res = 0
togg = True
for s in[*open("yash.txt")]:
x = re.findall("mul[(][0-9]+[,][0-9]+[)]|do[(][)]|don't[(][)]", s)
for i in x:
print(i)
if i=="do()":
togg = True
elif i=="don't()":
togg = False
elif togg:
t = re.findall("[0-9]+", i)
res += int(t[0]) * int(t[1])

print(res)
