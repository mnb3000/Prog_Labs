project(lab4)

add_executable(${PROJECT_NAME}_1 main1.c)
target_link_libraries(${PROJECT_NAME}_1 m input_lib)