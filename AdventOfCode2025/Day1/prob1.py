x = 50
count = 0
with open("probfile.txt", "r") as file:
    for line in file:
        direction, amount = line.strip()[0], int(line.strip()[1:])
        x = (x + (-1 if direction == "L" else 1) * amount) % 100
        count += x == 0
print(count)
