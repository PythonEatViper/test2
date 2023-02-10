cmake_minimum_required(VERSION 3.5)
project(boost_serializtion)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS serialization)
find_package(Eigen3 REQUIRED)

# Default to C++14
set(CMAKE_CXX_STANDARD 17)

set(test ${OpenCV_INCLUDE_DIR})
message(WARN "${test}")

include_directories(
    ${OpenCV_INCLUDE_DIR}
    include
)

add_executable(main
    src/writter.cpp
    src/reader.cpp
    src/main.cpp
)

target_link_libraries(main
    Boost::serialization
    ${OpenCV_LIBS}
)
