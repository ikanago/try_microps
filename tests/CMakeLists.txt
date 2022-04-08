cmake_minimum_required(VERSION 3.0)

add_executable(
    test_microps
    EXCLUDE_FROM_ALL
    test_ip.cc
    test_socket.cc
    test_util.cc
)
target_compile_features(test_microps PUBLIC cxx_std_17)

target_link_libraries(
    test_microps
    microps
    gtest
    gmock
    gtest_main
)

target_include_directories(test_microps PUBLIC ${PROJECT_SOURCE_DIR}/src)
