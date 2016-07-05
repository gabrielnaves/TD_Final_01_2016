#include <host.h>

int runHost(const char* port) {
    printf("Host is running.\n");
    host_initData();
    host_handshake();
    host_gossip();
    return 0;
}

void host_initData() {
    /*Create UDP socket*/
    hst_data.clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

    /*Configure settings in address struct*/
    hst_data.serverAddr.sin_family = AF_INET;
    hst_data.serverAddr.sin_port = htons(7891);
    hst_data.serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(hst_data.serverAddr.sin_zero, '\0', sizeof hst_data.serverAddr.sin_zero);

    /*Initialize size variable to be used later on*/
    hst_data.addr_size = sizeof hst_data.serverAddr;
}

void host_handshake() {
    char buffer[BUFFER_SIZE];
    do {
        // Sends hello message to server
        sendto(hst_data.clientSocket, "HELLO SRV", 10, 0,
               (struct sockaddr *)&hst_data.serverAddr, hst_data.addr_size);

        // Receives hello message from server
        recvfrom(hst_data.clientSocket, buffer, BUFFER_SIZE, 0, NULL, NULL);
    } while (strcmp(buffer, "HELLO CLT") != 0);
}

void host_gossip() {
    printf("Host-server communication started.\n");
    char buffer[BUFFER_SIZE];
    do {
        host_sendAndReceiveMessage(buffer, BUFFER_SIZE);
    } while (strcmp(buffer, "BYE CLT") != 0);
    sendto(hst_data.clientSocket, "BYE SRV", 8, 0,
           (struct sockaddr *)&hst_data.serverAddr, hst_data.addr_size);
}

void host_sendAndReceiveMessage(char* buffer, int size) {
    printf("Type a message to send to server: ");
    readLine(buffer, size);

    // Sends message to server
    sendto(hst_data.clientSocket, buffer, strlen(buffer)+1, 0,
           (struct sockaddr *)&hst_data.serverAddr, hst_data.addr_size);

    // Receives message from server
    recvfrom(hst_data.clientSocket, buffer, size, 0, NULL, NULL);
    printf("Received message from server: %s\n", buffer);
}
