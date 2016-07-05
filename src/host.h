#ifndef HOST_H
#define HOST_H

#include <include_all_std.h>
#include <utils.h>

struct HostData {
    int clientSocket;
    socklen_t addr_size;
    struct sockaddr_in serverAddr;
} hst_data;

int runHost(const char* port);
void host_initData();
void host_handshake();
void host_gossip();
void host_sendAndReceiveMessage(char* buffer, int size);

#endif /* HOST_H */
