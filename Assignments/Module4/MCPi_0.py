from random import random, seed
from math import sqrt
import timeit

def main():
	"Monte Carlo Calculation of Pi"
	inside=0
	seed(6188)
	nArray=[10,100,1000,10000,100000,1000000]
	f = open('outputfile.txt','w')
	for n in nArray:
		inside = 0
		for i in range(0, n):
			x=random()
			y=random()
			if sqrt(x*x+y*y)<=1:
				inside+=1
		pi=4*inside/n
		f.write(str(pi)+ "\n")
	f.close()
if __name__ == "__main__":
	print(main.__doc__)
	print(timeit.timeit(main, number=1))

