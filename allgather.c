#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스의 순위 데이터
    int send_data = world_rank;

    // 모든 프로세스의 데이터를 수집할 배열 준비
    int* recv_data = (int*)malloc(world_size * sizeof(int));

    // 각 프로세스에서 send_data를 사용하여 모든 데이터를 수집
    MPI_Allgather(&send_data, 1, MPI_INT, recv_data, 1, MPI_INT, MPI_COMM_WORLD);

    // 수집된 데이터를 출력
    printf("Process %d received data: ", world_rank);
    for (int i = 0; i < world_size; i++) {
        printf("%d ", recv_data[i]);
    }
    printf("\n");

    // 메모리 해제
    free(recv_data);

    MPI_Finalize();
    return 0;
}

