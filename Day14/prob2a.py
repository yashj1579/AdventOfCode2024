import re
import numpy as np
import matplotlib.pyplot as plt


def visualize_grid(grid, it):
    fig, ax = plt.subplots()
    ax.imshow(grid, cmap='Greys', interpolation='none')  # Use 'Greys' colormap
    ax.set_xticks(np.arange(-0.5, grid.shape[1], 1), minor=True)
    ax.set_yticks(np.arange(-0.5, grid.shape[0], 1), minor=True)
    ax.grid(which="minor", color="black", linestyle='-', linewidth=0.5)
    ax.tick_params(which="minor", size=0)  # Hide tick marks

    # Optionally, remove major axis ticks
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_title(f"Iteration {it}", fontsize=14, pad=10)
    plt.show()

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

for j in range(0,105):
    x = np.array([[0] * wide] * tall)
    for i in range(0,len(p)):
        pos = p[i]
        vel = v[i]
        pos[0] =(pos[0] + vel[0]) % tall
        pos[1] =(pos[1] + vel[1]) % wide
        p[i] = pos
        x[pos[0]][pos[1]] = 1
    visualize_grid(x, str(j+1))
    #print(j)
    #print("\n\n\n")

#iteration 31 (horizontal)
#iteration 72 (vertical)
#x cong 31 mod 103
#x cong 72 mod 101
