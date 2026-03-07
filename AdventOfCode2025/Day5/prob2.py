
fresh_list = []
with open("probfile.txt", "r") as file:
    for line in file:
        if line.strip() == "":
            break
        fresh_list.append(tuple(map(int, line.strip().split("-"))))

    fresh_list.sort()
    start = 0
    count = 0
    print(fresh_list)
    while start < len(fresh_list):
        start_time = fresh_list[start][0]
        end_time = fresh_list[start][1]
        while start < len(fresh_list) and end_time >= fresh_list[start][0]:
            end_time = max(end_time, fresh_list[start][1])
            start += 1
        count += end_time - start_time + 1

    print(count)
