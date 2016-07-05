#ifndef HOST_H
#define HOST_H

#include <include_all_std.h>
#include <utils.h>

struct HostData {
    int udp_socket;
    struct sockaddr_in server_address;
    struct sockaddr_storage server_storage;
    socklen_t address_size;
} hst_data;

int runHost(const char* port);

#endif /* HOST_H */
