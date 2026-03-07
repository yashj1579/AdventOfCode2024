import re
res = 0
id = 0
st = []

class ForFun:
    def __init__(self, id):
        self.id = id

def largestseq(s=[], size=1): #returns first spot that fits the needed size
    count = 0
    loc = 0
    for i in s:
        if (type(i) == str):
            count += 1
        else:
            count = 0
        loc += 1
        if count >= size:
            return loc - size
    return len(s)

def sizing(s=[], pos=1):
    currpos = pos
    count = 0
    while (currpos >= 0 and type(s[currpos]) != str and s[currpos].id == s[pos].id):
        count += 1
        currpos -= 1
    return count

for s in[*open("probset.txt")]:

    pos = 0
    for i in s:
        for x in range(int(i)):
            st.append("." if pos % 2 else ForFun(id))
        if pos % 2:
            id += 1
        pos += 1
    #print(st)


    end = len(st) - 1
    while (0 <= end):
        if type(st[end]) != str: #determine if this needs to be moved
            #find length of what needs to be moved
            size = sizing(st, end)

            #find location to move to
            pos = largestseq(st, size)

            #perform move (switch end to be string '.'
            # if move not possible, skip
            if pos < end:
                for i in range(size):
                    st[pos+i] = st[end-i]
                    st[end-i] = "."

            end -= size
        else:
            end -= 1

    #does weighted sum
    pos = 0
    count = 0
    for i in st:
        if type(i) != str:
            count += i.id * pos
        pos += 1
    #print(st)
    print(count)
