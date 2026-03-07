count = 0
x = None
with open("testFile.txt", "r") as file:
    x = file.read().split(",")

for i in x:
    start, stop = i.split("-")
    for j in range(int(start), int(stop) + 1):
        for k in range(1,len(str(j))):
            if len(str(j)) % k != 0:
                continue
            occ = False
            for m in range(1,len(str(j))//k):
                if str(j)[0:k] != str(j)[k*m:k*(m+1)]:
                    occ = True
                    break
            if occ:
                continue
            count += j
            break
print(count)
