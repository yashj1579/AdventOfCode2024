storage = {"": 1}
def remove(x:set, y:str):
    if y in storage:
        return storage[y]

    actual_counter = 0
    for i in x:
        if len(y) >= len(i) and y[-1 * len(i):] == i:
            actual_counter += remove(x, y[:-1 * len(i)])

    storage[y] = actual_counter
    return actual_counter

with open("yash2.txt", "r") as f:
    total_sum = 0
    keys = set()
    for line_num, line in enumerate(f):
        if line_num == 0:
            x = line.strip().split(", ")
            keys = set(x)
            #print(line, storage)
        elif line_num == 1:
            continue
        else:
            ans = remove(keys, line.strip())
            total_sum += ans
    print(total_sum)

