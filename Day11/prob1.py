import re
res = 0
id = 0
st = []

for s in[*open("probset.txt")]:
    st = s.split()
print(st)
for i in range(0,25):
    newlist = []
    for j in range(len(st)):
        if st[j] == '0':
            newlist.append('1')
        elif len(st[j]) % 2 == 0: #1234 len=4, (0, 2), (2,end)
            newlist.append(str(int(st[j][0:len(st[j])//2])))
            newlist.append(str(int(st[j][len(st[j])//2:])))
        else:
            newlist.append(str(int(st[j]) * 2024))
    st = newlist
    #print(st)

print(len(st))
