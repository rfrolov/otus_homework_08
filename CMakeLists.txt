cmake_minimum_required(VERSION 3.6)

add_executable(task1196 1196.cpp)
add_executable(task1496 1496.cpp)
add_executable(task1545 1545.cpp)
add_executable(task1837 1837.cpp)

set_target_properties(
        task1196 task1496 task1545 task1837 PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

include(CPack)