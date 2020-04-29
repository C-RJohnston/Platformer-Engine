import random as r
file = open("level0.dat",'w')

for i in range(0,29):
    for j in range(0,50):
        if(i==23):
            s="1"+' '
        else:
            s="0"+' '
        file.write(s)
    file.write("\n")
file.close()

file = open("level0.dat",'r')
file.read(100)
