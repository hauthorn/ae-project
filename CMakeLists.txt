cmake_minimum_required(VERSION 3.6)
project(ae_project)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
set(PAPI_PREFIX "/usr/local/")
set(CMAKE_CXX_STANDARD 11)
find_package(PAPI REQUIRED)

set(SOURCE_FILES BasePred.cpp LinearScanPred.cpp BinarySearchRec.cpp BinaryTreePred.cpp RedBlackTree.cpp)
set(SOURCE_FILES_RANK rank/RankSelectSpace.cpp)
set(SOURCE_FILES_HEAP heap/unfolded/Binaryheap.cpp heap/KaryHeap.cpp heap/BaseHeap.cpp
        heap/QueueHeap.cpp heap/unfolded/TernaryHeap.cpp heap/unfolded/QuadHeap.cpp heap/unfolded/SevenHeap.cpp
        heap/unfolded/EightHeap.cpp heap/unfolded/NineHeap.cpp heap/unfolded/TenHeap.cpp heap/unfolded/ElevenHeap.cpp
    )

add_executable(ae_project ${SOURCE_FILES} main.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(verify ${SOURCE_FILES} verify.cpp)
add_executable(rankSelect ${SOURCE_FILES_RANK} rank/main.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(rankSelectVerify ${SOURCE_FILES_RANK} rank/verify.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(min_heap ${SOURCE_FILES_HEAP} heap/main.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(verify_heap ${SOURCE_FILES_HEAP} heap/verify.cpp)
add_executable(matrixMultiply matrix/main.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(verify_matrix_multiply matrix/verify.cpp)

target_link_libraries(${PROJECT_NAME} ${PAPI_LIBRARIES} ${DOLFIN_LIBRARIES})
target_link_libraries(matrixMultiply ${PAPI_LIBRARIES} ${DOLFIN_LIBRARIES})
target_link_libraries(min_heap ${PAPI_LIBRARIES} ${DOLFIN_LIBRARIES})