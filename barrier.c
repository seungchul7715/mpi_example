#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    printf("Processor %d reaching the barrier.\n", world_rank);
    MPI_Barrier(MPI_COMM_WORLD);  // All processes must reach this point before they can continue

    printf("Processor %d passed the barrier.\n", world_rank);

    MPI_Finalize();
    return 0;
}
