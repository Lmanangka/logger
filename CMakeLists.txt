cmake_minimum_required(VERSION 3.16.3)

project(
  simple_logger
  LANGUAGES C
  VERSION 1.0.0)

include(FindPkgConfig)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(LOG_TO_FILE "Enable logging to file" ON)

add_executable(${PROJECT_NAME} src/log_utils.c examples/log_example.c)

include_directories(include)

if(LOG_TO_FILE)
  target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_TO_FILE)
endif()
