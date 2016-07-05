#include <server.h>

int runServer(const char* port) {
    printf("Server is running.\n");
    server_initData();
    server_waitForHandshake();
    server_gossip();
    return 0;
}

void server_initData() {
    // Create UDP socket
    srv_data.udp_socket = socket(PF_INET, SOCK_DGRAM, 0);

    // Configure settings in address struct
    srv_data.server_address.sin_family = AF_INET;
    srv_data.server_address.sin_port = htons(7891);
    srv_data.server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(srv_data.server_address.sin_zero, '\0', sizeof srv_data.server_address.sin_zero);

    // Bind socket with address struct
    bind(srv_data.udp_socket, (struct sockaddr *) &srv_data.server_address, sizeof(srv_data.server_address));

    // Initialize size variable to be used later on
    srv_data.address_size = sizeof srv_data.server_storage;
}

void server_waitForHandshake() {
    char buffer[BUFFER_SIZE];
    printf("Server is waiting for handshake from client.\n");
    while (strcmp(buffer, "HELLO SRV") != 0) {
        // Receives hello message from host
        recvfrom(srv_data.udp_socket, buffer, BUFFER_SIZE, 0,
                 (struct sockaddr *)&srv_data.server_storage, &srv_data.address_size);
    }
    // Sends hello message to host
    sendto(srv_data.udp_socket, "HELLO CLT", 10, 0,
           (struct sockaddr*)&srv_data.server_storage, srv_data.address_size);
}

void server_gossip() {
    printf("Server-host communication started.\n");
    char buffer[BUFFER_SIZE];
    do {
        server_sendAndReceiveMessage(buffer, BUFFER_SIZE);
    } while(strcmp(buffer, "BYE SRV") != 0);
}

void server_sendAndReceiveMessage(char* buffer, int size) {
    printf("Type a message to send to host: ");
    readLine(buffer, size);

    // Sends message to host
    sendto(srv_data.udp_socket, buffer, strlen(buffer)+1, 0,
           (struct sockaddr *)&srv_data.server_storage, srv_data.address_size);

    // Receives message from host
    recvfrom(srv_data.udp_socket, buffer, size, 0,
             (struct sockaddr *)&srv_data.server_storage, &srv_data.address_size);

    printf("Received message from host: %s\n", buffer);
}
