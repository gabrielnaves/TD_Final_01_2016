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

int runServer(const char* port);
void server_initData();
void server_waitForHandshake();
void server_gossip();
void server_sendAndReceiveMessage(char* buffer, int size);

#endif /* SERVER_H */
