x = 50
count = 0
with open("probFile.txt", "r") as file:
    for line in file:
        direction, amount = line.strip()[0], int(line.strip()[1:])
        prev_x = x
        if direction == "L":
            x = x - amount
            count += abs(int((x+1) / 100)) + (x < 0) * (prev_x != 0)
        else:
            x = x + amount
            count += int((x-1) / 100)
        x = x % 100
        count += x == 0
print(count)
