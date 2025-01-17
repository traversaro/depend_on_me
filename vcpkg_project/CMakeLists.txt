cmake_minimum_required(VERSION 3.19.2)

include(FetchContent)
FetchContent_Declare(
        vcpkg
        GIT_REPOSITORY https://github.com/microsoft/vcpkg
        GIT_TAG 5568f110b509a9fd90711978a7cb76bae75bb092 # 2021.05.12
)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    FetchContent_GetProperties(vcpkg
            POPULATED vcpkg_POPULATED
            SOURCE_DIR vcpkg_SOURCE_DIR)
    if (NOT vcpkg_POPULATED)
        FetchContent_Populate(vcpkg)
    endif ()

    set(CMAKE_TOOLCHAIN_FILE
            "${vcpkg_SOURCE_DIR}/scripts/buildsystems/vcpkg.cmake")
    set(VCPKG_CHAINLOAD_TOOLCHAIN_FILE
            "${CMAKE_CURRENT_LIST_DIR}/../common/cmake/toolchain.cmake")
endif ()

project(depend_on_me_vcpkg
        VERSION "0.1.1"
        DESCRIPTION "Some description"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "CMAKE_MODULE_PATH  is ${CMAKE_MODULE_PATH}")

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
