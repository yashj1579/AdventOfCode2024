import re
import numpy as np

s1 = ""
s2 = ""
s3 = ""
count = 1
sum = 0
for s in[*open("probset.txt")]:
    #print(s)
    if count % 4 == 3:
        s3 = s;
        a = s1.split(",")
        x1 = int(a[0][12:])
        y1 = int(a[1][3:])
        a = s2.split(",")
        x2 = int(a[0][12:])
        y2 = int(a[1][3:])
        a = s3.split(",")
        xgoal = int(a[0][9:])
        ygoal = int(a[1][3:])
        max_sum = 1e10
        x = np.array([[x1, x2], [y1, y2]])
        b = np.array([xgoal, ygoal])
        try:
            sol = np.linalg.solve(x, b)
            #print(sol)
            if abs(sol[0] - int(sol[0])) <= 1e-4 or abs(sol[1] - int(sol[1])) <= 1e-4:
                #print("\t\t",sol)
                sum += sol[0] * 3 + sol[1] * 1

        except:
            #assume infinite solutions
            #print("occ")
            i = 0
            while (xgoal - x1 * i) / x1 >= 0:
                if int((xgoal - x1 * i) / x1) == (xgoal - x1 * i) / x1:
                    max_sum = min(max_sum, i * 3 + ((xgoal - x1 * i) / x1) * 1)
                i += 1
            sum += 0 if max_sum == 1e10 else max_sum

    if count % 4 == 1:
        s1 = s
    if count % 4 == 2:
        s2 = s;
    count += 1
print(sum)
#24609
