#include <server.h>

int runServer(const char* port) {
    printf("Server is running.\n");

    char buffer[BUFFER_SIZE];

    /* Create UDP socket */
    srv_data.udp_socket = socket(PF_INET, SOCK_DGRAM, 0);

    /* Configure settings in address struct */
    srv_data.server_address.sin_family = AF_INET;
    srv_data.server_address.sin_port = htons(7891);
    srv_data.server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(srv_data.server_address.sin_zero, '\0', sizeof srv_data.server_address.sin_zero);

    /* Bind socket with address struct */
    bind(srv_data.udp_socket, (struct sockaddr *) &srv_data.server_address, sizeof(srv_data.server_address));

    /* Initialize size variable to be used later on */
    srv_data.address_size = sizeof srv_data.server_storage;

    while(true) {
        /* Try to receive any incoming UDP datagram. Address and port of
           requesting client will be stored on srv_data.server_storage variable */
        int byte_amount = recvfrom(srv_data.udp_socket,buffer,BUFFER_SIZE,0,
                                   (struct sockaddr *)&srv_data.server_storage, &srv_data.address_size);

        printf("Received this string: %s\n", buffer);

        /* Send uppercase message back to client, using srv_data.server_storage as the address */
        sendto(srv_data.udp_socket,buffer,byte_amount,0,
               (struct sockaddr *)&srv_data.server_storage,srv_data.address_size);
        printf("Will this pass?\n");
    }

    return 0;
}
