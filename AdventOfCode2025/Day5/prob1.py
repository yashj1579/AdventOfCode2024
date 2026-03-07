count = 0
fresh_list = []
with open("probfile.txt", "r") as file:
    new_line = False
    for line in file:
        if line.strip() == "":
            new_line = True
            continue
        if not new_line:
            fresh_list.append(list(map(int, line.strip().split("-"))))
        if new_line:
            for i in range(len(fresh_list)):
                if fresh_list[i][0] <= int(line) <= fresh_list[i][1]:
                    count += 1
                    break
print(count)
