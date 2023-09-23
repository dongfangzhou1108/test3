cmake_minimum_required(VERSION 3.6)

project(test_evpp)

# @author dongfangzhou: for windows libevent [.dll] cmake (from libevent cmake line-163)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(3rdparty)