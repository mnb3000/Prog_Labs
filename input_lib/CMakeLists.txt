project(input_lib)

add_library(${PROJECT_NAME} src/input_lib.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)