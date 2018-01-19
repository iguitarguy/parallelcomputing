# Hello World, Version 0
from mpi4py import MPI

def main():
	"Hello World, Version 0"
	
	comm = MPI.COMM_WORLD
	rank = comm.Get_rank()
	size = comm.Get_size()
	processor = MPI.Get_processor_name()
	print("Hello World from process ",rank)
	print(size, " is the number of processes on processor ", processor, ".")
	
if __name__ == "__main__":
	print(main.__doc__)
	main()
