from pylab import *

# loading files
ground_ni01 = loadtxt('ground_omega_0.01.txt')
ground_ni05 = loadtxt('ground_omega_0.5.txt')
ground_ni1 = loadtxt('ground_omega_1.0.txt')
ground_ni5 = loadtxt('ground_omega_5.0.txt')

ground_i01 = loadtxt('int_ground_omega_0.01.txt')
ground_i05 = loadtxt('int_ground_omega_0.5.txt')
ground_i1 = loadtxt('int_ground_omega_1.0.txt')
ground_i5 = loadtxt('int_ground_omega_5.0.txt')

# list of each ground state list
nonint_ground = [ground_ni01, ground_ni05, ground_ni1, ground_ni5]
int_ground = [ground_i01, ground_i05, ground_i1, ground_i5]\

# omega values
omega = [0.01, 0.5, 1.0, 5.0]

# rho
rho = linspace(0, 6, 400)

# plotting interactive and non-interacting electrons
for i in range(4):
	plot(rho, nonint_ground[i], label=r'Non-interacting')
	plot(rho, int_ground[i], label=r'Interacting')
	title(r'Non-interacting and interacting electrons in harmonic oscillator when $\omega_{\rho}$ = %g' % omega[i])

	xlabel(r'$\rho$', fontsize=14)
	ylabel(r'$|u(\rho)|^2$', fontsize=14)
	legend(loc = 'best')
	show()	
