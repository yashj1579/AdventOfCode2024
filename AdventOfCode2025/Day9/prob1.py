pos = []
maxx = 0
with open("probfile.txt", "r") as file:
    for line in file:
        x, y = map(int, line.strip().split(","))
        for i in range(len(pos)):
            maxx = max(maxx, abs(pos[i][0] - x + 1) * abs(pos[i][1] - y + 1))
        pos.append([x, y])

print(maxx)
