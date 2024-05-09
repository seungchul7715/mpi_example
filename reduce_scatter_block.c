#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // 각 프로세스의 데이터 초기화
    int* send_data = malloc(world_size * sizeof(int));
    for (int i = 0; i < world_size; i++) {
        send_data[i] = i + world_rank;
    }
	int recv_data = 0;  // 각 프로세스가 결과를 받을 변수

    // 모든 프로세스의 데이터를 수집, 합산하고 균등하게 분배
    MPI_Reduce_scatter_block(send_data, &recv_data, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    // 결과 출력
    printf("Process %d received %d\n", world_rank, recv_data);

	free(send_data);
    MPI_Finalize();
    return 0;
}

