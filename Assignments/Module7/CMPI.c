#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#define xAndYSize 100
float randomFloat()
{
      float r = (float)rand() / (float)RAND_MAX;
      return r;
}
main(int argc, char** argv) 
{
    int ierr, size, node;
    MPI_Status status;
    float x[xAndYSize];
    float y[xAndYSize];
    ierr = MPI_Init(&argc, &argv);
    /* find out MY process ID, and how many processes were started */
    
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &node);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    // seed random generator
    srand(6188);
    // the size of my x and y arrays
    //int xAndYSize = 1000000;
    /*double x = randomDouble();
    printf("X is equal to %f", x);
    double y = randomDouble();
    printf("Y is equal to %f", y);
    */
    
    // master node
    if ( node == 0 )
    {
    
        printf("I'm a master node!\n");
        int i;
        for (i = 1; i < size; i++) {
            int j;
            for (j = 0; j < xAndYSize; j++) {
                x[j] = randomFloat();
                y[j] = randomFloat();
            }
            //int sizeOfX = sizeof(x) / sizeof(x[0]);
            //int sizeOfY = sizeof(y) / sizeof(y[0]);
            //printf("My x array contains %d elements\n", sizeOfX);
            //printf("My y array contains %d elements\n", sizeOfY);
            
            // Send x array
            MPI_Send(x, 1, MPI_FLOAT, i, 123, MPI_COMM_WORLD);
            // Send y array
            MPI_Send(y, 1, MPI_FLOAT, i, 987, MPI_COMM_WORLD);
        }
        
    }
    // slave node
    else
    {
        printf("I'm slave node %d!\n", node);
        //float x[xAndYSize];
        //float y[xAndYSize];
        MPI_Recv(&x, 1, MPI_FLOAT, 0, 123, MPI_COMM_WORLD, &status);
        MPI_Recv(&y, 1, MPI_FLOAT, 0, 987, MPI_COMM_WORLD, &status);
        int sizeOfX = sizeof(x) / sizeof(x[0]);
        int sizeOfY = sizeof(y) / sizeof(y[0]);
        printf("My x array contains %d elements\n", sizeOfX);
        printf("My y array contains %d elements\n", sizeOfY);
        
        // declare array to hold sums, needs to be at xAndYSize
        int pi[xAndYSize];
        int i;
        int piCount = 0;
        float sums = 0;
        for (i = 0; i < xAndYSize; i++) {
            float sum = (x[i] * x[i]) + (y[i] * y[i]); 
            //printf("Sum = %f", sum); 
            if (sum <= 1) {
                //piCount = piCount + 1;
                sums += 1;
                //printf("Pi count = %d", piCount);
                //float piEstimation = 4 * sum / xAndYSize;
                //printf("Pi estimation = %f", piEstimation);
                //pi[piCount] = (4 * sum) / xAndYSize;
                //printf("Pi at index %d now has the value
            }
            //piCount = piCount + 1;
        }
        //printf("Count of pi in node %d is %d\n", node, piCount);    
        
        printf("Sums in node %d equal %f\n", node, sums);
        //int j;
        //for (j = 0; j < 2; j++) {
        //  printf("Pi index %d has a value of %f\n", j, pi[j]);
        //}
        
    }
    ierr = MPI_Finalize();
}
/*
int MPI_Recv(void *received_data, int receive_count, MPI_Datatype receive_type, 
      int sender_ID, int tag, MPI_Comm comm, MPI_Status *status); 
received_data: variable of a C type that corresponds to the receive_type supplied below
receive_count: number of data elements expected (int)
receive_type: datatype of the data to be received (one of the MPI datatype handles)
sender_ID: process ID of the sending process (int)
tag: message tag (int)
comm: communicator (handle)
status: status struct (MPI_Status)
int MPI_Send(void *data_to_send, int send_count, MPI_Datatype send_type, 
      int destination_ID, int tag, MPI_Comm comm); 
data_to_send: variable of a C type that corresponds to the send_type supplied below
send_count: number of data elements to be sent (nonnegative int)
send_type: datatype of the data to be sent (one of the MPI datatype handles)
destination_ID: process ID of destination (int)
tag: message tag (int)
comm: communicator (handle)
*/