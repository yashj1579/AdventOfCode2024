import numpy as np
count = 0
with open("probfile.txt", "r") as file:
    for line in file:
        maxx = 0
        x = np.array(list(map(int, line.strip())))
        first = np.argmax(x[:-1])
        last = np.argmax(x[first+1:])
        ans = x[first] * 10 + x[last+first+1]
        #print(ans)
        count += ans
print(count)
