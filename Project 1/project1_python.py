from pylab import *


v10 = loadtxt('vector_v10.txt')
v100 = loadtxt('vector_v100.txt')
v1000 = loadtxt('vector_v1000.txt')

err_1 = loadtxt('error_10.txt')
err_2 = loadtxt('error_100.txt')
err_3 = loadtxt('error_1000.txt')
err_4 = loadtxt('error_10000.txt')
err_5 = loadtxt('error_100000.txt')
err_6 = loadtxt('error_1E6.txt')
err_7 = loadtxt('error_1E7.txt')


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
file.write('Error n=10 Error n=100 Error n=1000 Error n=10000 Error n=1E5 Error n=1E6 Error n=1E7\n %g    %g     %g      %g      %g     %g      %g' % (max(err_1), max(err_2), max(err_3), max(err_4), max(err_5), max(err_6), max(err_7)) )


plot(x, u_exact, linewidth = 2.0, label=r'$u(x)$')
plot(x_10, v10, label=r'$v_i$ for $n$ = 10')
plot(x_100, v100, '*', label=r'$v_i$ for $n$ = 100')
plot(x, v1000, '-m', label=r'$v_i$ for $n$ = 1000')
title(r'Closed-form solution vs. tridiagonal matrix algorithm')
xlabel(r'$x$')
ylabel(r'$u$')
legend()
show()



