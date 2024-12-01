#include "config.h"

struct Config app_config = {
        .max_connections = 100,
        .server_name = "localhost",
        .port = 8080
};

void init_config(void) {
    // Initialize configuration
}