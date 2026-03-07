def remove(x:list, y:str):
    if y == "":
        return True
    for i in range(len(x)):
        res2 = False
        #remove from start
        if len(y) >= len(x[i]) and y[-1 * len(x[i]):] == x[i] and remove(x, y[:-1 * len(x[i])]):
            return True
    return False

with open("yash2.txt", "r") as f:
    line_num = -1
    count = 0
    for line in f:
        line_num += 1
        if line_num == 0:
            x = line.strip().split(", ")
        elif line_num == 1:
            continue
        else:
            res = remove(x, line.strip())
            if res == True:
                count += 1
                print(line.strip())
    print(count)

#not 400
