import numpy as np
count = 0
with open("probfile.txt", "r") as file:
    for line in file:
        y = list(map(int, line.strip()))
        y.append(0)
        x = np.array(y)
        ans = 0
        pos = 0
        for i in range(12):
            pos = pos + np.argmax(x[pos:-12+i])
            ans = ans * 10 + x[pos]
            pos = pos + 1
        count += ans
print(count)
