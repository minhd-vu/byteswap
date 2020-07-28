
#include "header.hpp"

int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    bool convert = true;

    // What we are sending/recieving to/from the client.
    uint8_t byte1;
    uint16_t byte2;
    uint32_t byte4;
    unsigned char *bytes;

    printf("Server is running %s-endian architecture\n", is_bigendian() ? "big" : "little");

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }


    printf("1");

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    printf("2");

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("3");

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Recieve and send one byte.

    read(new_socket, &byte1, sizeof(uint8_t));

    printf("\nRecieved one byte unconverted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));

    if (convert)
    {
        printf("\nRecieved one byte converted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));
    }

    printf("\nSent one byte unconverted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));

    if (convert)
    {
        printf("\nSent one byte converted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));
    }

    write(new_socket, &byte1, sizeof(uint8_t));

    close(server_fd);

    return 0;
}
