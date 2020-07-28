
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

    // Whether you want to see endian conversions.
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

    printf("\nSent one byte\nUnconverted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));

    if (convert)
    {
        printf("Converted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));
    }

    write(sock, &byte1, sizeof(uint8_t));
    read(sock, &byte1, sizeof(uint8_t));

    printf("\nRecieved one byte\nUnconverted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));

    if (convert)
    {
        printf("Converted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT8 "\n", byte1, PRINTF_BYTE_TO_BINARY_INT8(byte1));
    }

    // Send and recieve two bytes.

    printf("\nSent two bytes\nUnconverted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT16 "\n", byte2, PRINTF_BYTE_TO_BINARY_INT16(byte2));

    if (convert)
    {
        byte2 = htons(byte2);
        printf("Converted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT16 "\n", byte2, PRINTF_BYTE_TO_BINARY_INT16(byte2));
    }

    write(sock, &byte2, sizeof(uint16_t));
    read(sock, &byte2, sizeof(uint16_t));

    printf("\nRecieved two bytes\nUnconverted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT16 "\n", byte2, PRINTF_BYTE_TO_BINARY_INT16(byte2));

    if (convert)
    {
        byte2 = ntohs(byte2);
        printf("Converted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT16 "\n", byte2, PRINTF_BYTE_TO_BINARY_INT16(byte2));
    }

    // Send and recieve four bytes.

    printf("\nSent four bytes\nUnconverted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT32 "\n", byte4, PRINTF_BYTE_TO_BINARY_INT32(byte4));

    if (convert)
    {
        byte4 = htonl(byte4);
        printf("Converted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT32 "\n", byte4, PRINTF_BYTE_TO_BINARY_INT32(byte4));
    }

    write(sock, &byte4, sizeof(uint32_t));
    read(sock, &byte4, sizeof(uint32_t));

    printf("\nRecieved four bytes\nUnconverted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT32 "\n", byte4, PRINTF_BYTE_TO_BINARY_INT32(byte4));

    if (convert)
    {
        byte4 = ntohl(byte4);
        printf("Converted:\tDecimal %d\tBinary " PRINTF_BINARY_PATTERN_INT32 "\n", byte4, PRINTF_BYTE_TO_BINARY_INT32(byte4));
    }

    close(sock);

    return 0;
}
