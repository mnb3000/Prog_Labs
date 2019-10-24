project(lab6)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} input_lib)