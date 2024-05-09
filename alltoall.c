#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스에서 전송할 데이터 배열 준비
    int* send_data = malloc(world_size * sizeof(int));
    for (int i = 0; i < world_size; i++) {
        send_data[i] = world_rank + i;
    }

    // 각 프로세스에서 받을 데이터 배열
    int* recv_data = malloc(world_size * sizeof(int));

    // 모든 프로세스로부터 데이터 교환
    MPI_Alltoall(send_data, 1, MPI_INT, recv_data, 1, MPI_INT, MPI_COMM_WORLD);

    // 교환된 데이터 출력
    printf("Process %d received data:", world_rank);
    for (int i = 0; i < world_size; i++) {
        printf(" %d", recv_data[i]);
    }
    printf("\n");

    free(send_data);
    free(recv_data);

    MPI_Finalize();
    return 0;
}

