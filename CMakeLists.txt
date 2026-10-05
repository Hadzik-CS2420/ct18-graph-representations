cmake_minimum_required(VERSION 3.14)
project(ct17-graph-representations LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)


# Write build/compile_commands.json so C++ IntelliSense knows the real
# include paths and flags instead of guessing at them. The devcontainer
# points C_Cpp.default.compileCommands straight at this file.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/Graph.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# --- Google Test ---
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests
    tests/ct17_test.cpp
    src/Graph.cpp
)
target_include_directories(run_tests PRIVATE include)
target_link_libraries(run_tests gtest_main)
