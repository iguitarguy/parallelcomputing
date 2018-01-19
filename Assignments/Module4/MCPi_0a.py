from random import random, seed
from math import sqrt
import numpy as np
import timeit

def main():
	"Monte Carlo Calculation of Pi"
	inside=0
	seed(6188)
	nArray=[10,100,1000,10000,100000,1000000]
	f = open('outputfileV.txt','w')
	pi = []
	for n in nArray:
		x = np.random.uniform(size=n)
		y = np.random.uniform(size=n)
		sums = np.sum(x*x + y*y <=1)
		pi.append(4 * sums / n)
	f.write(str(pi))
	f.close()
if __name__ == "__main__":
	print(main.__doc__)
	print(timeit.timeit(main, number=1))

