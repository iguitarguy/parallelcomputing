# Monte Carlo Calculation of Pi
from random import random, seed
from math import sqrt
from joblib import Parallel, delayed
import multiprocessing
import numpy as np
import time

np.random.seed(6188)
nArray = [10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000]
num_cores = 8
times = []
inside = 0

def main(i):
	start_time = time.time()
	x = np.random.uniform(size=i)
	y = np.random.uniform(size=i)
	sums = np.sum(x*x + y*y <= 1)
	pi = 4 * sums / i
	return [pi, time.time() - start_time]    

if __name__ == "__main__":
	timeArray = []
	piArray = []
	f = open("piEstimate.txt", "w")
	results = Parallel(n_jobs=2)(delayed(main)(i) for i in nArray)
	for element in results:
		pi, time = element
		timeArray.append(time)
		piArray.append(pi)
	f.write("Time = " + str(timeArray))
	f.write("\nTime average = " + str(np.average(timeArray)))
	f.write("\nPI = " + str(timeArray))
	f.write("\nPI average = " + str(np.average(piArray)))
	f.close()