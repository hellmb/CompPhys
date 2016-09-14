#import numpy as np
#import matplotlib.pyplot as plt

from pylab import *

'''
#We could not use this since a few values in v[i] became 0

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
'''

v10 = loadtxt('vector_v10.txt')
v100 = loadtxt('vector_v100.txt')
v1000 = loadtxt('vector_v1000.txt')

err_1 = loadtxt('error_10.txt')
err_2 = loadtxt('error_100.txt')
err_3 = loadtxt('error_1000.txt')
err_4 = loadtxt('error_10000.txt')
err_5 = loadtxt('error_100000.txt')


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

# from debugging an error in the plot -> searchs for 0 in lists
searchval = 0.0
ii = np.where(v1000 == searchval)


# creating file to store the results of max error value in each error list

file = open('max_error_results.txt', 'w')
file.write('Error n=10 Error n=100 Error n=1000 Error n=10000 Error n=100000\n %g    %g     %g      %g      %g' % (max(err_1), max(err_2), max(err_3), max(err_4), max(err_5)) )


'''
plot(x, u_exact, linewidth = 2.0, label='u_exact')
plot(x_10, v10, label='v10')
plot(x_100, v100, '*', label='v100')
plot(x, v1000, '-.', label='v1000')
legend()
xlabel('x')
ylabel('u')
show()
'''


