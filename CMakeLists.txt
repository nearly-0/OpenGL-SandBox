cmake_minimum_required(VERSION 3.0.0)
project(sandbox VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(sandbox main.cpp)

if (WIN32)
    target_include_directories(sandbox PRIVATE include)
    target_link_libraries(sandbox libglfw3.a libglfw3dll.a)
else()
    find_package(glfw3 CONFIG REQUIRED)
    target_link_libraries(sandbox PRIVATE glfw)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
