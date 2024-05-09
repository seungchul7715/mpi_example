# MPI Sample Project
This project is a collection of sample programs that demonstrate various MPI (Message Passing Interface) collective communication operations.

## Prerequisites

Before running this project, an MPI library must be installed on your system.

### Installing MPI

General instructions for installing MPI are as follows:

#### Ubuntu

```bash
sudo apt update
sudo apt install openmpi-bin openmpi-common libopenmpi-dev
```

## Building the Project
```
mkdir build
cd build
cmake ..
make
```

### Build one example
```
mpicc source.c -o output
ex> mpicc gather.c -o gather 
```

## Running the Programs
```
cd build
mpirun -np 4 ./scatter 
mpirun -np 4 ./gather
...
```

## Message Passing Interface Collective Communication
[MPI Collective Communiation](docs/MPICC.md)
