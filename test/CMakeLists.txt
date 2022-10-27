cmake_minimum_required(VERSION 3.2)

set(This ip_filter_test)

set(Sources
    ip_filter_test.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    ip_filter
)
add_test(
    NAME ${This}
    COMMAND ${This}
)