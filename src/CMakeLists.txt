include_directories(ui)
include (ui/CMakeLists.txt)

add_executable(level-designer
    ${UI_SRC}
    Main.cpp)



