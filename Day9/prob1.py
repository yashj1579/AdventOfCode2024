res = 0
id = 0
st = []
for s in[*open("probset.txt")]:

    pos = 0
    for i in s:
        for j in range(0, int(i)):
            st.append(("." if pos % 2 else str(id)))
        if pos % 2:
            id += 1
        pos += 1
    #print(st)

    start = 0
    end = len(st) - 1
    count = 0
    while (start <= end):
        if st[start] == '.':
            if st[end] != '.':
                st[start] = st[end]
                st[end] = '.'
                count += int(st[start]) * start
                end -= 1
                start += 1
            else:
                end -= 1
        else:
            count += int(st[start]) * start
            start += 1
    #print(st)
    print(count)
