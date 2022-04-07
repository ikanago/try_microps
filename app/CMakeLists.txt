cmake_minimum_required(VERSION 3.0)

add_executable(udps udps.cc)
target_compile_features(udps PUBLIC cxx_std_17)
target_link_libraries(udps microps)
target_include_directories(udps PRIVATE ${PROJECT_SOURCE_DIR}/src)

