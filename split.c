#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int world_rank;
    int world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    int group = world_rank / 2;  
    MPI_Comm new_comm;
    MPI_Comm_split(MPI_COMM_WORLD, group, world_rank, &new_comm);

    int new_rank;
    int new_size;
    MPI_Comm_rank(new_comm, &new_rank);
    MPI_Comm_size(new_comm, &new_size);
   
    printf("Original Rank: %d, Size:%d / Group:%d New Rank: %d, Size: %d\n", 
        world_rank, world_size, group, new_rank, new_size);

    MPI_Comm_free(&new_comm);
    MPI_Finalize();
    return 0;
}
