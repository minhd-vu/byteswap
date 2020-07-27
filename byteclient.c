
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 
#define INT(x) ((int)(unsigned char)(x))
const int i = 1;
#define is_bigendian() ( (*(char*)&i) == 0 )
void hextobin(char hex[])  
{  
   int i=0;   
   while(hex[i])  
   {
       if (i >= 2 && i % 2 == 0) {
           printf(" ");
       }  
       switch(hex[i])  
       {  
           case '0':  
           printf("0000");  
           break;  
           case '1':  
           printf("0001");  
           break;  
           case '2':  
           printf("0010");  
           break;  
           case '3':  
           printf("0011");  
           break;  
           case '4':  
           printf("0100");  
           break;  
           case '5':  
           printf("0101");  
           break;  
           case '6':  
           printf("0110");  
           break;  
           case '7':  
           printf("0111");  
           break;  
           case '8':  
           printf("1000");  
           break;  
           case '9':  
           printf("1000");  
           break;  
           case 'A':  
           printf("1010");  
           break;  
           case 'a':  
           printf("1010");  
           break;  
           case 'B':  
           printf("1011");  
           break;  
           case 'b':  
           printf("1011");  
           break;  
           case 'C':  
           printf("1100");  
           break;  
           case 'c':  
           printf("1100");  
           break;  
           case 'D':  
           printf("1101");  
           break;  
           case 'd':  
           printf("1101");  
           break;  
           case 'E':  
           printf("1110");  
           break;  
           case 'e':  
           printf("1110");  
           break;  
           case 'F':  
           printf("1111");  
           break;  
           case 'f':  
           printf("1111");  
           break;  
       }  
       i++;  
   }
}  
void func(int sockfd) 
{ 
    char buff[MAX]; 
    unsigned char bytes[] = {0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t bytess[] = {0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t buf[11];
    unsigned char * p;
    unsigned char buffer[11];
    int n;
    int num;
    uint8_t i8 = 128;
    uint16_t i16 = 32768; 
    uint32_t i32 = 2147483648U; // 2147483648 8388608 32768
    uint64_t i64 = 9223372036854775808UL;
    char hex[17];

    // 1 Byte code
    p = (unsigned char *)&i8;
    printf("1 Byte...\n");
    printf("Sending %d to server\nHere are the memory representations...\n", i8);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("Binary Representation: ");
    sprintf(hex ,"%02X", p[0]);   
    hextobin(hex);
    printf("\n\n");
    write(sockfd, &i8, sizeof(uint8_t)); 
    bzero(buffer, sizeof(buffer)); 
    read(sockfd, &i8, sizeof(uint8_t));
    p = (unsigned char *)&i8;
    printf("From server: %d\nHere are the memory representations...\n", i8);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("Binary Representation: ");
    sprintf(hex ,"%02X", p[0]);   
    hextobin(hex);
    printf("\n\n\n");
    
    // 2 Byte code
    p = (unsigned char *)&i16;
    printf("2 Bytes...\n");
    printf("Sending %d to server\nHere are the memory representations...\n", i16);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    if (is_bigendian()) {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X", p[0], p[1]);   
    } else {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X", p[1], p[0]);
    }
    hextobin(hex);
    printf("\n\n");
    write(sockfd, &i16, sizeof(uint16_t));
    read(sockfd, &i16, sizeof(uint16_t));
    p = (unsigned char *)&i16;
    printf("From server: %d\nHere are the memory representations...\n", i16);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    if (is_bigendian()) {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X", p[0], p[1]);   
    } else {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X", p[1], p[0]);
    }
    hextobin(hex);
    printf("\n\n\n"); 

    // 4 Byte code
    p = (unsigned char *)&i32;
    printf("4 Bytes...\n");
    printf("Sending %u to server\nHere are the memory representations...\n", i32);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    if (is_bigendian()) {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X", p[0], p[1], p[2], p[3]);   
    } else {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X", p[3], p[2], p[1], p[0]);
    }
    hextobin(hex);
    printf("\n\n");
    write(sockfd, &i32, sizeof(uint32_t));
    read(sockfd, &i32, sizeof(uint32_t));
    p = (unsigned char *)&i32;
    printf("From server: %u\nHere are the memory representations...\n", i32);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    if (is_bigendian()) {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X", p[0], p[1], p[2], p[3]);   
    } else {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X", p[3], p[2], p[1], p[0]);
    }
    hextobin(hex);
    printf("\n\n\n"); 

    // 8 Byte code
    p = (unsigned char *)&i64;
    printf("8 Bytes...\n");
    printf("Sending %lu to server\nHere are the memory representations...\n", i64);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    printf("address %p holds %x\n", (void*)&p[4], p[4]);
    printf("address %p holds %x\n", (void*)&p[5], p[5]);
    printf("address %p holds %x\n", (void*)&p[6], p[6]);
    printf("address %p holds %x\n", (void*)&p[7], p[7]);
    if (is_bigendian()) {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X%02X%02X%02X%02X", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);   
    } else {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X%02X%02X%02X%02X", p[7], p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
    }
    hextobin(hex);
    printf("\n\n");
    write(sockfd, &i64, sizeof(uint64_t));
    read(sockfd, &i64, sizeof(uint64_t));
    p = (unsigned char *)&i64;
    printf("From server: %lu\nHere are the memory representations...\n", i64);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    printf("address %p holds %x\n", (void*)&p[4], p[4]);
    printf("address %p holds %x\n", (void*)&p[5], p[5]);
    printf("address %p holds %x\n", (void*)&p[6], p[6]);
    printf("address %p holds %x\n", (void*)&p[7], p[7]);
    if (is_bigendian()) {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X%02X%02X%02X%02X", p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);   
    } else {
        printf("Binary Representation: ");
        sprintf(hex ,"%02X%02X%02X%02X%02X%02X%02X%02X", p[7], p[6], p[5], p[4], p[3], p[2], p[1], p[0]);
    }
    hextobin(hex);
    printf("\n\n\n");

    // 2 + 8 byte combo code
    /*printf("2 + 8 bytes...\n");
    write(sockfd, &bytes, sizeof(char) * 10);
    read(sockfd, &buffer, sizeof(char) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    i16 = (buffer[0] << 8 | buffer[1]);
    p = (unsigned char *) &i16;
    printf("From server: %u\nHere are the memory representations...\n", i16);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    i64 = ((uint64_t)buffer[2] << 56 | (uint64_t)buffer[3] << 48 | (uint64_t)buffer[4] << 40 | (uint64_t)buffer[5] << 32 | buffer[6] << 24 | buffer[7] << 16 | buffer[8] << 8 | buffer[9]);
    p = (unsigned char *) &i64;
    printf("From server: %lu\nHere are the memory representations...\n", i64);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    printf("address %p holds %x\n", (void*)&p[4], p[4]);
    printf("address %p holds %x\n", (void*)&p[5], p[5]);
    printf("address %p holds %x\n", (void*)&p[6], p[6]);
    printf("address %p holds %x\n", (void*)&p[7], p[7]);
    printf("\n");*/

    printf("2 + 8 bytes...\n");
    write(sockfd, &bytess, sizeof(uint8_t) * 10);
    read(sockfd, &buf, sizeof(uint8_t) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");
    i16 = (buf[0] << 8 | buf[1]);
    p = (unsigned char *) &i16;
    printf("From server: %u\nHere are the memory representations...\n", i16);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    i64 = ((uint64_t)buf[2] << 56 | (uint64_t)buf[3] << 48 | (uint64_t)buf[4] << 40 | (uint64_t)buf[5] << 32 | buf[6] << 24 | buf[7] << 16 | buf[8] << 8 | buf[9]);
    p = (unsigned char *) &i64;
    printf("From server: %lu\nHere are the memory representations...\n", i64);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    printf("address %p holds %x\n", (void*)&p[4], p[4]);
    printf("address %p holds %x\n", (void*)&p[5], p[5]);
    printf("address %p holds %x\n", (void*)&p[6], p[6]);
    printf("address %p holds %x\n", (void*)&p[7], p[7]);
    printf("\n");
} 
  
int main(int argc, char *argv[]) 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;
    if (argc != 2) {
        printf("Provide an IP address please!\n");
        exit(-1);
    } 
    if (is_bigendian()) {
        printf("big endian\n");
    } else {
        printf("little endian\n");
    }
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(argv[1]); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n\n\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 
