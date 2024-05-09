#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스에서 보낼 데이터를 준비
    int send_data = world_rank;  // 프로세스 순위를 보낼 데이터로 사용

    // 루트 프로세스에서 모든 데이터를 수집할 배열을 준비
    int *recv_data = NULL;
    if (world_rank == 0) {
        recv_data = malloc(world_size * sizeof(int));
    }

    // 모든 프로세스의 데이터를 루트 프로세스에서 수집
    MPI_Gather(&send_data, 1, MPI_INT, recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // 루트 프로세스에서 수집된 데이터를 출력
    if (world_rank == 0) {
        printf("Gathered data in root process: ");
        for (int i = 0; i < world_size; i++) {
            printf("%d ", recv_data[i]);
        }
        printf("\n");
        free(recv_data);  // 메모리 해제
    }

    MPI_Finalize();
    return 0;
}

