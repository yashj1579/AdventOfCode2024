import re
res = 0
for s in[*open("probset.txt")]:
    x = re.findall("mul[(][0-9]+[,][0-9]+[)]", s)
    for i in x:
        print(i)
        t = re.findall("[0-9]+", i)
        res += int(t[0]) * int(t[1])

print(res)
