cmake_minimum_required(VERSION 3.10.0)
project(metalang99 LANGUAGES C)

# Fix the warnings about `DOWNLOAD_EXTRACT_TIMESTAMP` in newer CMake versions.
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

option(METALANG99_NO_SHORT_NAMES "Disable short macro aliases (e.g., v) for compatibility" OFF)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(METALANG99_NO_SHORT_NAMES)
    target_compile_definitions(${PROJECT_NAME} INTERFACE ML99_NO_SHORT_NAMES)
endif()
