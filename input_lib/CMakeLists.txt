project(input_lib)

add_library(${PROJECT_NAME} src/input_lib.c)
target_link_libraries(${PROJECT_NAME} m)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)