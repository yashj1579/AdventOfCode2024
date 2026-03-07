import re
res = 0
id = 0
sa = []

for s in[*open("probset.txt")]:
    sa = s.split()
st = {}
for i in sa:
    if st.get(i) is None:
        st[i] = 1
    else:
        st[i] += 1

print(st)
for i in range(0,25):
    newlist = {}
    x = list(st.keys())
    for j in range(len(x)):
        if x[j] == '0':
            if newlist.get('1') is None:
                newlist['1'] = st[x[j]]
            else:
                newlist['1'] += st[x[j]]
        elif len(x[j]) % 2 == 0: #1234 len=4, (0, 2), (2,end)
            if newlist.get(str(int(x[j][0:len(x[j])//2]))) is None:
                newlist[str(int(x[j][0:len(x[j])//2]))] = st[x[j]]
            else:
                newlist[str(int(x[j][0:len(x[j]) // 2]))] += st[x[j]]

            if newlist.get(str(int(x[j][len(x[j])//2:]))) is None:
                newlist[str(int(x[j][len(x[j])//2:]))] = st[x[j]]
            else:
                newlist[str(int(x[j][len(x[j])//2:]))] += st[x[j]]
        else:
            if newlist.get(str(int(x[j]) * 2024)) is None:
                newlist[str(int(x[j]) * 2024)] = st[x[j]]
            else:
                newlist[str(int(x[j]) * 2024)] += st[x[j]]
    st = newlist
    print(i)
x = st.keys()
sum = 0
for i in x:
    sum += st[i]
print(sum)
#224869647102559
