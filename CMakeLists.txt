cmake_minimum_required (VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
project ("GameEngineProj")

set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/deps/)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw/
        GIT_TAG origin/master
)

FetchContent_Declare(
        glew
        GIT_REPOSITORY https://github.com/Perlmint/glew-cmake.git
        GIT_TAG origin/master
)

FetchContent_MakeAvailable(glfw glew)

set(SOURCE_FILES "src/GameEngineProj.cpp" "src/GameEngineProj.h")
include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-src/include/GLFW/)

add_executable (GameEngineProj ${SOURCE_FILES})
add_compile_definitions(GLEW_STATIC)

# macOS
if (APPLE)
    target_link_libraries(
            GameEngineProj
            libglew_static
            glfw
            "-framework CoreFoundation"
            "-framework CoreGraphics"
            "-framework IOKit"
            "-framework AppKit"
            "-framework OpenGL"
    )

# Linux / Other Unix
elseif (UNIX AND NOT APPLE)
    target_link_libraries(
            GameEngineProj
            libglew_static
            glfw
    )

# Windows
else ()
    target_link_libraries(
            GameEngineProj
            libglew_static
            glfw
    )
endif ()

# TODO: Add tests and install targets if needed.