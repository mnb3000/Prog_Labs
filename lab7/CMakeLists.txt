project(lab7)

add_executable(${PROJECT_NAME} main.c)
add_executable(${PROJECT_NAME}_1 base.c)
target_link_libraries(${PROJECT_NAME} input_lib m)