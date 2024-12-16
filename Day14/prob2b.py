#x cong 31 mod 103
#x cong 72 mod 101
mod1 = 103
mod2 = 101
x1 = 31
x2 = 72
for i in range(mod1*mod2):
    if (i % mod1 == x1 and i % mod2 == x2):
        print(i)
