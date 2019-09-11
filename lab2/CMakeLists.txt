project(lab2)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} m input_lib)