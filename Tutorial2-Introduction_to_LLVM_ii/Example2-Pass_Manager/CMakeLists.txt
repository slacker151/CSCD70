cmake_minimum_required(VERSION 3.12.0)
project(PassManager)

execute_process(COMMAND llvm-config --cxxflags
                OUTPUT_VARIABLE LLVM_CXXFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_FLAGS ${LLVM_CXXFLAGS})

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(lib)

include(CTest)
enable_testing()
add_subdirectory(test)
