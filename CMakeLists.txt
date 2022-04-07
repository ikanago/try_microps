cmake_minimum_required(VERSION 3.0)
project("try_microps")
add_compile_options(-Wall -Wextra -pedantic)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
add_subdirectory(thirdparty)

add_custom_target(test DEPENDS microps COMMAND test_microps)

file(GLOB_RECURSE ALL_SOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/app/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h
)

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    add_custom_target(
        format
        COMMAND ${CLANG_FORMAT}
        -style=file
        -i
        ${ALL_SOURCE_FILES}
    )
endif()

find_program(CPP_CHECK "cppcheck")
find_program(CPP_LINT "cpplint")
if(CPP_CHECK AND CPP_LINT)
    add_custom_target(
        lint
        COMMAND ${CPP_CHECK}
        --enable=warning
        --std=c++17
        ${ALL_SOURCE_FILES}
        COMMAND ${CPP_LINT}
        --recursive
        ${ALL_SOURCE_FILES}
    )
endif()
