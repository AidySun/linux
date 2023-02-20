cmake_minimum_required (VERSION 3.16)

project(DBUSTEST LANGUAGES CXX)

# specify the C++ standard, CMAKE_CXX_STANDARD must be called above add_executable()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")

add_executable(DBUSTEST main.cpp)

#add_subdirectory(sdbus-cpp)

#target_link_libraries(DBUSTEST sdbus-c++)
target_link_libraries(DBUSTEST libdbus)


#target_link_libraries(LC LC_SOLUTION)

#install(TARGETS DBUSTEST DESTINATION bin)

