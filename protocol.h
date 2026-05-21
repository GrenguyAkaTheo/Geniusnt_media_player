#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <cstdint>

const char* const SOCKET_PATH = "/tmp/media_player.sock";

enum class CommandType : int32_t {
    ADD_TO_QUEUE     = 0, // High priority user queue
    ADD_TO_PLAYLIST  = 1, // Fallback background playlist queue
    PLAY             = 2,
    PAUSE            = 3,
    SKIP             = 4,
    SET_VOLUME       = 5,
    GET_STATUS       = 6,
    CLEAR_PLAYLIST   = 7
};

struct __attribute__((packed)) PlayerCommand {
    CommandType type;
    int32_t int_value;
    char path_value[512];
};

#endif // PROTOCOL_H
