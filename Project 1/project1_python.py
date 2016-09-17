from pylab import *

# importing vector files and 
v10 = loadtxt('vector_v1.txt')
v100 = loadtxt('vector_v2.txt')
v1000 = loadtxt('vector_v3.txt')

# function to calculate u(x)
def u(x):
    """ Calculate u(x) """
    u_exact = 1.0 - (1.0 - exp(-10.0))*x - exp(-10.0*x)
    
    return u_exact

# declaring x values for the three different arrays
x = linspace(0, 1, 1002)
x_10 = linspace(0, 1, 12)
x_100 = linspace(0, 1, 102)

# if flag is true, we plot the figures
plot_figure = True
if plot_figure:
	# plotting u(x) against the three vectors of v values
	plot(x, u(x), linewidth = 2.0, label=r'$u(x)$')
	plot(x_10, v10, label=r'$v_i$ for $n$ = 10')
	plot(x_100, v100, '*', label=r'$v_i$ for $n$ = 100')
	plot(x, v1000, '-m', label=r'$v_i$ for $n$ = 1000')
	title(r'Closed-form solution vs. tridiagonal matrix algorithm')
	xlabel(r'$x$')
	ylabel(r'$u$')
	legend()
	show()


# importing big error files takes time, so we created a flag 
# to let us run the program without the repeated delay of this
import_error = True
if import_error:
	# importing error files
	err_1 = loadtxt('error_1.txt')
	err_2 = loadtxt('error_2.txt')
	err_3 = loadtxt('error_3.txt')
	err_4 = loadtxt('error_4.txt')
	err_5 = loadtxt('error_5.txt')
	err_6 = loadtxt('error_6.txt')
	err_7 = loadtxt('error_7.txt')

	# creating file to store the results of max error value in each error list
	file = open('max_error_results.txt', 'w')
	# we are taking the minimum values since all values in the lists are negative
	file.write('Error n=10 Error n=100 Error n=1000 Error n=10000 Error n=1E5 Error n=1E6 Error n=1E7\n %g    %g     %g      %g      %g     %g      %g' % (min(err_1), min(err_2), min(err_3), min(err_4), min(err_5), min(err_6), min(err_7)) )



