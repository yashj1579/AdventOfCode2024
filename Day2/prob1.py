count = 0
for s in[*open("yash.txt")]:
c = s.split(" ")
if (len(c) == 1):
count += 1;
continue
cond = True
for i in range(1, len(c)):
if ((int(c[1]) - int(c[0]) > 0 and int(c[i]) - int(c[i-1]) > 0) or (int(c[1]) - int(c[0]) < 0 and int(c[i]) - int(c[i-1]) < 0 )):
if (abs(int(c[i]) - int(c[i-1])) <= 3):
x = 1
else:
cond = False
else:
cond = False
if cond:
count += 1;
print(count)
