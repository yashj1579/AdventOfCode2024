import re
res = 0
x = []
for s in[*open("probset.txt")]:
    x.append(list(s))
#print(x)
xs = [["M", "-", "M"], ["-", "A", "-"], ["S", "-", "S"]]
xs2 = [["M", "-", "S"], ["-", "A", "-"], ["M", "-", "S"]]
xs3 = [["S", "-", "S"], ["-", "A", "-"], ["M", "-", "M"]]
xs4 = [["S", "-", "M"], ["-", "A", "-"], ["S", "-", "M"]]
for i in range(0,len(x) - 2):
    for j in range(0,len(x[i]) - 2):
        sc1 = False
        sc2 = False
        sc3 = False
        sc4 = False
        for k in range(0,len(xs)):
            for l in range(0,len(xs[k])):
                if xs[k][l] == "-":
                    continue
                if xs[k][l] != x[i+k][j+l]:
                    sc1 = True
                if xs2[k][l] != x[i+k][j+l]:
                    sc2 = True
                if xs3[k][l] != x[i+k][j+l]:
                    sc3 = True
                if xs4[k][l] != x[i+k][j+l]:
                    sc4 = True

        if (not sc1) or (not sc2) or (not sc3) or (not sc4):
            res += 1

print(res)
