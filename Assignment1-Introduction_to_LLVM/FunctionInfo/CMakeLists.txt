cmake_minimum_required(VERSION 3.12.0)
project(FunctionInfo)

# Obtain the build flags from `llvm-config --cxxflags` and forward them to
# variable CMAKE_CXX_FLAGS.
execute_process(COMMAND llvm-config --cxxflags
                OUTPUT_VARIABLE LLVM_CXXFLAGS
                OUTPUT_STRIP_TRAILING_WHITESPACE)
set(CMAKE_CXX_FLAGS ${LLVM_CXXFLAGS})

set(CMAKE_CXX_CLANG_TIDY clang-tidy)

add_subdirectory(lib)  # Build the shared library libFunctionInfo.so.

include(CTest)
enable_testing()
add_subdirectory(test)
