cmake_minimum_required(VERSION 3.20.0)
project(testGUI VERSION 0.1.0)

set(wxWidgets_ROOT_DIR "C:/wxWidgets")
set(wxWidgets_LIB_DIR "C:/wxWidgets/lib/gcc1220_x64_dll")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_GLOB
    src/app/*
    src/main_frame/*
    src/resource/*
    src/create_matrix_frame/*
)

add_executable(testGUI ${project_GLOB} main.manifest)

target_link_libraries(testGUI ${wxWidgets_LIBRARIES})
target_include_directories(testGUI PRIVATE ${wxWidgets_INCLUDE_DIRS})