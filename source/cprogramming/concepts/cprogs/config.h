#ifndef LEARNTOSOLVEIT_CONFIG_H
#define LEARNTOSOLVEIT_CONFIG_H

extern struct Config {
    int max_connections;
    char *server_name;
    int port;
} app_config;

extern void init_config(void);
#endif //LEARNTOSOLVEIT_CONFIG_H
