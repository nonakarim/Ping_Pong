cmake_minimum_required(VERSION 3.26)

project(Ping_Pong_Raylib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ping_Pong_Raylib
    src/main.cpp
    src/background.cpp
    src/Ball.cpp
    src/menu.cpp
    src/Paddles.cpp
    src/Use.cpp
)

target_include_directories(Ping_Pong_Raylib PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# ---------------- raylib ----------------
find_package(raylib CONFIG REQUIRED)

# ---------------- glfw3 ----------------
find_package(glfw3 CONFIG REQUIRED)

# ---------------- ImGui ----------------
add_library(imgui STATIC
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_demo.cpp
)

target_include_directories(imgui PUBLIC
    external/imgui
)

# ---------------- rlImGui ----------------
add_library(rlImGui STATIC
    external/rlImGui/rlImGui.cpp
)

target_include_directories(rlImGui PUBLIC
    external/imgui
    external/rlImGui
)

# 🔥 Cross-platform safe GLFW target detection
if(TARGET glfw)
    set(GLFW_TARGET glfw)
elseif(TARGET glfw3::glfw)
    set(GLFW_TARGET glfw3::glfw)
else()
    message(FATAL_ERROR "GLFW target not found")
endif()

target_link_libraries(rlImGui
    PUBLIC
    imgui
    raylib
    ${GLFW_TARGET}
)

# ---------------- Final Link ----------------
target_link_libraries(Ping_Pong_Raylib
    PRIVATE
    rlImGui
)

# ---------------- macOS ----------------
if(APPLE)
    target_link_libraries(Ping_Pong_Raylib
        PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework OpenGL"
    )
endif()

add_custom_command(TARGET Ping_Pong_Raylib POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Ping_Pong_Raylib>/assets
)