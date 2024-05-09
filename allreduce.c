#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스에서 보낼 데이터를 준비
    int send_data = world_rank * world_rank; // 프로세스 순위의 제곱
    int recv_data = 0; // 결과를 받을 변수

    // 모든 프로세스의 send_data 값을 합산하여 모든 프로세스에 결과를 배포
    MPI_Allreduce(&send_data, &recv_data, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    // 각 프로세스에서 결과 출력
    printf("Process %d: Sum of squares up to %d is %d\n", world_rank, world_size - 1, recv_data);

    MPI_Finalize();
    return 0;
}

