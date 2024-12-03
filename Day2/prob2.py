count = 0

def removal(c=[], rec=-1):
    print(c)
    cond = True
    for i in range(1, len(c)):
        if ((int(c[1]) - int(c[0]) > 0 and int(c[i]) - int(c[i-1]) > 0) or (int(c[1]) - int(c[0]) < 0 and int(c[i]) - int(c[i-1]) < 0 )):
            if (abs(int(c[i]) - int(c[i-1])) <= 3):
                x = 1
            else:
                if rec == -1:
                    x = c.pop(i)
                    cond = removal(c, 1)
                    c.insert(i, x)
                    x = c.pop(i-1)
                    cond = cond | removal(c, 1);
                    c.insert(i - 1, x)
                    break
                else:
                    cond = False
                    break
        else:
            if rec == -1:
                x = c.pop(i)
                cond = removal(c, 1)
                c.insert(i, x)
                x = c.pop(i-1)
                cond = cond | removal(c, 1);
                c.insert(i-1, x)
                break
            else:
                cond = False
                break
    return cond


for s in[*open("yash.txt")]:
    c = s.split(" ")
    if (len(c) == 1):
        count += 1;
        continue
    cond = removal(c, -1)
    x = c.pop(0)
    cond = cond | removal(c, 1)
    if cond:
        count += 1=
print(count)
