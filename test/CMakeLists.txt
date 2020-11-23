cmake_minimum_required(VERSION 3.8)

set(This MatrixTests)

set(Sources
    matrixtests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    matrix
)

add_test(
    NAME ${This}
    COMMAND ${This}
)