cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME "rock-paper-scissors")

project(
  ${PROJECT_NAME}
  VERSION 1.0
  LANGUAGES C
)

add_executable(${CMAKE_PROJECT_NAME} main.c)

add_library(Game game.c)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC Game)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})
