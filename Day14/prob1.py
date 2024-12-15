import re
import numpy as np

count = 1
sum = 0
p=[]
v=[]
wide = 101 #to change
tall = 103
#wide = 11
#tall = 7
for s in[*open("probset.txt")]:
    s1=s.split(" ")
    s2 = s1[0].split(",")
    s3 = s1[1].split(",")
    p.append([int(s2[1]), int(s2[0][2:])])
    v.append([int(s3[1]), int(s3[0][2:])])
sec = [0, 0, 0, 0]
for i in range(0,len(p)):
    pos = p[i]
    vel = v[i]
    print(pos)
    for j in range(0,100):
        pos[0] =(pos[0] + vel[0]) % tall
        pos[1] =(pos[1] + vel[1]) % wide
        print(pos)
    if not (pos[0] == tall // 2 or pos[1] == wide // 2): #in a quadrant
        sec[2*int(pos[0] / (tall//2+1)) + int(pos[1] / (wide//2+1))] += 1
sum = 1
for i in sec:
    sum *= i
print(sum)


#221835159
