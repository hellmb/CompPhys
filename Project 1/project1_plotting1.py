import numpy as np
import matplotlib.pyplot as plt

# Makes me type in the name of star file in the terminal window
myfile_v10 = "vector_v10.txt"
myfile_v100 = "vector_v100.txt"
myfile_v1000 = "vector_v1000.txt"

# Function to read elements from file
def readfile(name):
    infile = file(name, 'r')
    lines = infile.readlines() 
    v = np.zeros(len(lines))
    for line in lines:
        i = lines.index(line)
        words = line.split()
        v[i] = words[0]

    return v

v10 = readfile(myfile_v10)
v100 = readfile(myfile_v100)
v1000 = readfile(myfile_v1000)

# declaration
n = 1000
h = 1.0/(n+1)

def u(x):
    """ Calculate u(x) """
    u_exact = 1.0 - (1.0 - np.exp(-10.0))*x - np.exp(-10.0*x)
    return u_exact

# declaring x values
x = np.linspace(0, 1, 1002)
x_10 = np.linspace(0, 1, 12)
x_100 = np.linspace(0, 1, 102)

# call u
u_exact = u(x)

print len(v1000)

plt.plot(x, u_exact, label='u_exact')
plt.plot(x_10, v10, '-.', label='v10')
plt.plot(x_100, v100, '-.', label='v100')
plt.plot(x, v1000, '-.', label='v1000')
plt.legend()
plt.xlabel('x')
plt.ylabel('u')
plt.show()




