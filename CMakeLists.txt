cmake_minimum_required(VERSION 3.6)
project(ae_project)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
set(PAPI_PREFIX "/usr/local/")
set(CMAKE_CXX_STANDARD 11)
find_package(PAPI REQUIRED)

set(SOURCE_FILES BasePred.cpp LinearScanPred.cpp BinarySearchRec.cpp BinaryTreePred.cpp RedBlackTree.cpp)
set(SOURCE_FILES_RANK rank/RankSelectSpace.cpp)
set(SOURCE_FILES_HEAP heap/heap.cpp heap/KaryHeap.cpp)

add_executable(ae_project ${SOURCE_FILES} main.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(verify ${SOURCE_FILES} verify.cpp)
add_executable(rankSelect ${SOURCE_FILES_RANK} rank/main.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(rankSelectVerify ${SOURCE_FILES_RANK} rank/verify.cpp fileutils/FileUtils.cpp fileutils/FileUtils.h)
add_executable(verify_heap  ${SOURCE_FILES_HEAP} heap/verify.cpp)

target_link_libraries(${PROJECT_NAME} ${PAPI_LIBRARIES} ${DOLFIN_LIBRARIES})

# this is needed in order to make papi work
target_link_libraries(rankSelect ${PAPI_LIBRARIES} ${DOLFIN_LIBRARIES})