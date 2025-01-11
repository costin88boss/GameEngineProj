cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
project ("GameEngineProj")

set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/deps/)

include(FetchContent)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw/
)

FetchContent_MakeAvailable(glfw)

set(SOURCE_FILES "src/GameEngineProj.cpp")
include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-src/include/GLFW/)

add_executable (GameEngineProj ${SOURCE_FILES})
target_link_libraries(GameEngineProj glfw)

# TODO: Add tests and install targets if needed.