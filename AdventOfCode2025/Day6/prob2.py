import re

from numpy.ma.core import multiply

lists = []
summ = 0
with open("probfile.txt", "r") as file:
    for line in file:
        lists.append(line[:-1])
    print(lists)
    for idx, oper in enumerate(lists[-1]):
        if oper == " ":
            continue
        nums = []
        count = idx
        while count < len(lists[0]) and (len(nums) == 0 or nums[-1] != 0):
            number = ""
            for i in range(4):
                number += lists[i][count] if lists[i][count] != " " else ""
            count += 1
            if number == "":
                break
            nums.append(int (number))
        if oper == "*":
            vall = 1
            for num in nums:
                vall *= num
            summ += vall
        if oper == "+":
            summ += sum(nums)

print(summ)
#20310144535
