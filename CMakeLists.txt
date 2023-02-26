cmake_minimum_required(VERSION 3.22.1)

project(Celestial)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)
find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(${PROJECT_NAME} src/Main.cpp
src/Application.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)