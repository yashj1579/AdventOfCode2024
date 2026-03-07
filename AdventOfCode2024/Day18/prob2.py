

low = 1024
high = 3450
while low < high:
    print(low, high)
    rest = (low + high) // 2
    n = 71
    x = [[n * n for i in range(n)] for i in range(n)]
    count = 0
    with open("yash2.txt", "r") as f:
        for line in f:
            if count >= rest:
                break
            count += 1
            x1, y1 = map(int, line.split(","))
            x[x1][y1] = 0


    x[0][0] = 0
    x_dir = [1, 0, -1, 0]
    y_dir = [0, 1, 0, -1]
    pos = [(0, 0, 0)]
    min_steps = n*n
    paths = 0
    while len(pos) != 0:
        #print(pos)
        res = pos.pop()
        curr_x, curr_y, steps = res[0], res[1], res[2]
        if curr_x == n - 1 and curr_y == n - 1:
            min_steps = min(min_steps, steps)
            paths += 1
            continue
        for i in range(3, -1, -1):
            if 0 <= curr_x + x_dir[i] < n and 0 <= curr_y + y_dir[i] < n and x[curr_x + x_dir[i]][curr_y + y_dir[i]] > 1 + steps:
                x[curr_x + x_dir[i]][curr_y + y_dir[i]] = steps + 1
                pos.append([curr_x + x_dir[i], curr_y + y_dir[i], steps + 1])
    if paths == 0:
        high = (high + low) // 2
        paths += 1
    else:
        low = (low + high) // 2
        high -= 1
print(low)
"""
def prints(x):
    for i in range(len(x)):
        for j in range(len(x[i])):
            print(x[i][j], end=" ")
        print()

prints(x)
"""
