cmake_minimum_required(VERSION 3.10)
project(MediaPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- DEPENDENCIES ---
# Find FFmpeg using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(FFMPEG REQUIRED libavformat libavcodec libavutil libswresample)

# --- DAEMON TARGET ---
add_executable(Geniusnt Main.cpp) 
target_link_libraries(Geniusnt PRIVATE ${FFMPEG_LIBRARIES} m pthread dl)
target_include_directories(Geniusnt PRIVATE ${FFMPEG_INCLUDE_DIRS})

# --- CONTROLLER CLIENT TARGET ---
add_executable(Geniusnt-ctl player_ctl.cpp) 
target_link_libraries(Geniusnt-ctl PRIVATE pthread)
