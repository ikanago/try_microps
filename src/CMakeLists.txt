cmake_minimum_required(VERSION 3.0)

set(LIB_SRC
    ip.cc
    util.cc
)

add_library(microps STATIC ${LIB_SRC})
target_compile_features(microps PUBLIC cxx_std_17)
target_include_directories(microps PRIVATE ${PROJECT_SOURCE_DIR}/src)
