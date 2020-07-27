
#include "header.hpp"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: <program name> [server IP address]\n");
        return -1;
    }

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    bool convert = true;

    // What we are sending/recieving to/from the server.
    uint8_t byte1 = 64;
    uint16_t byte2 = 40000;
    uint32_t byte4 = 1000000;
    unsigned char *bytes;

    printf("Client is running %s-endian architecture\n", is_bigendian() ? "big" : "little");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nSocket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address\n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection failed \n");
        return -1;
    }

    printf("Connected to server\n");

    // Send and recieve one byte.

    printf("\nSent one byte unconverted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));

    if (convert)
    {
        printf("\nSent one byte converted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));
    }

    send(sock, &byte1, sizeof(byte1), 0);

    valread = read(sock, buffer, BUFFER_SIZE);
    memcpy(&byte1, buffer, sizeof(buffer));

    printf("\nRecieved one byte unconverted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));

    if (convert)
    {
        printf("\nRecieved one byte converted\nDecimal %d\nBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));
    }

    return 0;
}
