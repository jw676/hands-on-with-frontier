#include <stdlib.h>
#include <stdio.h>

int main()
{
    // Number of elements in arrays
    const int N = 1e8;

    // Bytes in arrays
    size_t bytes_in_array = N*sizeof(double);

    // Allocate memory for arrays
    double *A = (double*)malloc(bytes_in_array);
    double *B = (double*)malloc(bytes_in_array);
    double *C = (double*)malloc(bytes_in_array);

    // Initialize vector values
    for(int i=0; i<N; i++){
        A[i] = 1.0;
        B[i] = 2.0;
    }

    // Perform element-wise addition of vectors
    for(int i=0; i<N; i++){
        C[i] = A[i] + B[i];

        // Free no longer necessary memory on last iteration
        if(i == N-1) {
            free(A);
            free(B);
        }
    }

    // Check for correctness
    for(int i=0; i<N; i++){
        if(C[i] != 3.0){
            printf("Error: Element C[%d] = %f instead of 3.0\n", i, C[i]);
            exit(1);
        }
    }

    printf("__SUCCESS__\n");

    free(C);

    return 0;
}