#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스에서 보낼 데이터를 준비
    int send_data = world_rank + 1;  // 데이터: 프로세스 순위 + 1
    int recv_data;  // 결과를 받을 변수

    // MPI_Scan을 사용하여 누적 합을 계산
    MPI_Scan(&send_data, &recv_data, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    // 결과 출력
    printf("Process %d: Scan result = %d\n", world_rank, recv_data);

    MPI_Finalize();
    return 0;
}
