import re
res = 0
xs = []
xs2 = []
first = True
updown = [""] * 140
for s in[*open("probset.txt")]:
    #print(s)
    x = re.findall("XMAS", s)
    res += len(x)
    x = re.findall("SAMX", s)
    res += len(x)
    if first:
        first = False
        for i in range(len(s)):
            if s[i] == "\n":
                break
            xs.append(s[i]+"")
            xs2.append(s[len(s) - 1 - i - 1] + "")
    else:
        xs.insert(0, s[0])
        xs2.insert(0, s[len(s) - 1])
        for i in range(len(s)):
            if s[i] == "\n":
                break
            xs[i] = xs[i] + s[i]
            xs2[i] = xs2[i] + s[len(s) - 1 - i - 1]
    for i in range(len(s)):
        if s[i] == "\n":
            break
        updown[i] += s[i] + ""

for i in xs:
    x = re.findall("XMAS", i)
    res += len(x)
    x = re.findall("SAMX", i)
    res += len(x)

for i in xs2:
    x = re.findall("XMAS", i)
    res += len(x)
    x = re.findall("SAMX", i)
    res += len(x)

for i in updown:
    x = re.findall("XMAS", i)
    res += len(x)
    x = re.findall("SAMX", i)
    res += len(x)

print(res)
'''
across: 3 2
updown: 1 1
diag: 
....XXMAS.
.SAMXMS...
...S..A...
..A.A.MS.X
XMASAMX.MM
X.....XA.A
S.S.S.S.SS
.A.A.A.A.A
..M.M.M.MM
.X.X.XMASX
'''
