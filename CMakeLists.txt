cmake_minimum_required(VERSION 3.10)
project(MPI_Examples)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

file(GLOB MPI_SOURCES "*.c")

foreach(SOURCE_FILE ${MPI_SOURCES})
    get_filename_component(PROGRAM_NAME ${SOURCE_FILE} NAME_WE)
	add_executable(${PROGRAM_NAME} ${SOURCE_FILE})
    target_link_libraries(${PROGRAM_NAME} ${MPI_LIBRARIES})
    target_compile_options(${PROGRAM_NAME} PRIVATE ${MPI_COMPILE_FLAGS})
    target_link_options(${PROGRAM_NAME} PRIVATE ${MPI_LINK_FLAGS})
endforeach()

if(MPI_COMPILE_FLAGS)
    foreach(SOURCE_FILE ${MPI_SOURCES})
        get_filename_component(PROGRAM_NAME ${SOURCE_FILE} NAME_WE)
        set_target_properties(${PROGRAM_NAME} PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
    endforeach()
endif()

if(MPI_LINK_FLAGS)
    foreach(SOURCE_FILE ${MPI_SOURCES})
        get_filename_component(PROGRAM_NAME ${SOURCE_FILE} NAME_WE)
        set_target_properties(${PROGRAM_NAME} PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
    endforeach()
endif()
