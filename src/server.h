#ifndef SERVER_H
#define SERVER_H

#include <include_all_std.h>
#include <utils.h>

struct ServerData {
    int udp_socket;
    struct sockaddr_in server_address;
    struct sockaddr_storage server_storage;
    socklen_t address_size;
} srv_data;

int RunServer(const char* port);

#endif /* SERVER_H */
