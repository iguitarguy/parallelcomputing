import numpy as np

def f(a):
	return (4/(1+a*a))

def main():
	n=10000000
	midpoint = .5
	sum = 0.
	h = 1/n
	for i in range (1, n+1):
		sum+= f(midpoint/n)
		midpoint+= 1
	piest = sum * h
	print("Pi estimation = " + str(piest))

if __name__ == "__main__":
	main()
	