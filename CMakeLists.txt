cmake_minimum_required(VERSION 3.20)
project(MediaPlayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the absolute root of your pristine, local static installation
set(FFMPEG_LOCAL_DIR "$ENV{HOME}/ffmpeg_local_build")

# --- DAEMON TARGET ---
add_executable(Geniusnt Main.cpp)

# Explicitly index your local headers for compilation compilation
target_include_directories(Geniusnt PRIVATE "${FFMPEG_LOCAL_DIR}/include")

# Explicitly link the exact static archives (.a) by their direct path.
# This completely prevents CMake or the linker from guessing or checking system locations.
target_link_libraries(Geniusnt PRIVATE
    "${FFMPEG_LOCAL_DIR}/lib/libavformat.a"
    "${FFMPEG_LOCAL_DIR}/lib/libavcodec.a"
    "${FFMPEG_LOCAL_DIR}/lib/libswresample.a"
    "${FFMPEG_LOCAL_DIR}/lib/libavutil.a"
    m         # Math library (required by FFmpeg internal calculations)
    pthread   # Posix threading subsystem
    dl        # Dynamic linking loader interface
)

# --- CONTROLLER CLIENT TARGET ---
add_executable(Geniusnt-ctl player_ctl.cpp)
target_link_libraries(Geniusnt-ctl PRIVATE pthread)
