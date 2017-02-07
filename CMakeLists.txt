cmake_minimum_required(VERSION 3.6)
project(ae_project)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")
set(PAPI_PREFIX "/usr/local/")

set(CMAKE_CXX_STANDARD 11)
find_package(PAPI REQUIRED)
set(SOURCE_FILES main.cpp Pred.cpp)
add_executable(ae_project ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${PAPI_LIBRARIES} ${DOLFIN_LIBRARIES})