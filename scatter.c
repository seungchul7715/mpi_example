#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 루트 프로세스에서 사용할 배열을 준비합니다.
    int *send_data = NULL;
    if (world_rank == 0) {
        send_data = malloc(world_size * sizeof(int));
        for (int i = 0; i < world_size; i++) {
            send_data[i] = i + 1;  // 데이터를 초기화합니다.
        }
    }

    // 각 프로세스가 받을 데이터
    int recv_data;

    // 데이터 분산
    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // 각 프로세스가 받은 데이터를 출력
    printf("Process %d received data %d\n", world_rank, recv_data);

    // 루트 프로세스에서 메모리 해제
    if (world_rank == 0) {
        free(send_data);
    }

    MPI_Finalize();
    return 0;
}

