#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스에서 보낼 데이터를 준비
    int send_data = world_rank * world_rank;
    int recv_data = 0; // 루트 프로세스에서만 사용될 수신 데이터

    // 모든 프로세스의 send_data 값을 합산하여 루트 프로세스에 저장
    MPI_Reduce(&send_data, &recv_data, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // 루트 프로세스에서 결과 출력
    if (world_rank == 0) {
        printf("The sum of squares up to %d is %d\n", world_size - 1, recv_data);
    }

    MPI_Finalize();
    return 0;
}

