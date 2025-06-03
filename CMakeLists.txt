cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(custom_ops)

find_package(Torch REQUIRED)

add_executable(Forensics transfer.cpp)
target_link_libraries(Forensics "${TORCH_LIBRARIES}")
set_property(TARGET Forensics PROPERTY CXX_STANDARD 17)