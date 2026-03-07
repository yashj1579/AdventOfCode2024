count = 0
x = None
with open("testFile.txt", "r") as file:
    x = file.read().split(",")


for i in x:
    start, stop = i.split("-")
    for j in range(int(start), int(stop) + 1):
        if len(str(j)) % 2 == 0 and str(j)[:len(str(j))//2] == str(j)[len(str(j))//2:]:
            count += j
print(count)
