include_directories(ui)
include (ui/CMakeLists.txt)

include_directories(renderer)
include(renderer/CMakeLists.txt)

add_executable(level-designer
    ${UI_SRC}
    ${RENDERER_SRC}
    Main.cpp)

include_directories(
    ${CMAKE_SOURCE_DIR}/ext/glew/include
)

find_library(GLEW_LIBRARY 
    NAMES
    glew32 
    glew32s
    PATHS "${CMAKE_SOURCE_DIR}/ext/glew/lib"
    NO_DEFAULT_PATH
)

target_link_libraries(level-designer ${GLEW_LIBRARY})
