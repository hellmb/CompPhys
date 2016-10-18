from pylab import *

# loading eigenvalues.txt
eigenvalues = loadtxt('eigenvalues.txt')

# sort eigenvalues from lowest to highest
sort_eigenvalues = sorted(eigenvalues)

# write three lowest eigenvalues to file
file = open('three_eigenvalues.txt', 'w')
file.write( 'Lamdba_0 = %.4f\nLamdba_1 = %.4f\nLamdba_2 = %.4f' % (sort_eigenvalues[0], sort_eigenvalues[1], sort_eigenvalues[2]) )
file.close()