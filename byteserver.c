
#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
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
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    char buff[MAX]; 
    int num;
    unsigned char bytes[] = {0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t bytess[] = {0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t buf[11];
    unsigned char buffer[11];
    unsigned char * p;
    uint8_t i8 = 128;
    uint16_t i16 = 32768; 
    uint32_t i32 = 2147483648U;
    uint64_t i64 = 9223372036854775808UL;
    char hex[17];

    // 1 Byte code
    printf("1 Byte...\n");
    read(sockfd, &i8, sizeof(uint8_t));
    p = (unsigned char *)&i8;
    printf("From client: %d\nHere are the memory representations...\n", i8);
    printf("address %p holds %x\n", (void*)&p[0], p[0]); 
    printf("Binary Representation: ");
    sprintf(hex ,"%02X", p[0]);   
    hextobin(hex);
    printf("\n\n");
    i8 = 128;
    p = (unsigned char *)&i8;
    printf("Sending %d to client...\nHere are the memory representations...\n", i8);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("Binary Representation: ");
    sprintf(hex ,"%02X", p[0]);   
    hextobin(hex);
    printf("\n\n\n"); 
    write(sockfd, &i8, sizeof(uint8_t)); 

    // 2 Byte code
    printf("2 Bytes...\n");
    read(sockfd, &i16, sizeof(uint16_t));
    p = (unsigned char *)&i16;
    printf("From client: %d\nHere are the memory representations...\n", i16);
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
    i16 = 32768;
    p = (unsigned char *)&i16;
    printf("Sending %d to client...\nHere are the memory representations...\n", i16);
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
    write(sockfd, &i16, sizeof(uint16_t)); 

    // 4 Byte code
    printf("4 Bytes...\n");
    read(sockfd, &i32, sizeof(uint32_t));
    p = (unsigned char *)&i32;
    printf("From client: %u\nHere are the memory representations...\n", i32);
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
    i32 = 2147483648U;
    p = (unsigned char *)&i32;
    printf("Sending %u to client...\nHere are the memory representations...\n", i32);
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
    write(sockfd, &i32, sizeof(uint32_t)); 

    // 8 Byte code
    printf("8 Bytes...\n");
    read(sockfd, &i64, sizeof(uint64_t));
    p = (unsigned char *)&i64;
    printf("From client: %lu\nHere are the memory representations...\n", i64);
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
    i64 = 9223372036854775808UL;
    p = (unsigned char *)&i64;
    printf("Sending %lu to client...\nHere are the memory representations...\n", i64);
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
    write(sockfd, &i64, sizeof(uint64_t)); 

    // 2 + 8 byte combo code
    /*printf("2 + 8 bytes...\n");
    read(sockfd, &buffer, sizeof(char) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
    i16 = (buffer[0] << 8 | buffer[1]);
    p = (unsigned char *) &i16;
    printf("From client: %u\nHere are the memory representations...\n", i16);;
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    i64 = ((uint64_t)buffer[2] << 56 | (uint64_t)buffer[3] << 48 | (uint64_t)buffer[4] << 40 | (uint64_t)buffer[5] << 32 | buffer[6] << 24 | buffer[7] << 16 | buffer[8] << 8 | buffer[9]);
    p = (unsigned char *) &i64;
    printf("From client: %lu\nHere are the memory representations...\n", i64);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    printf("address %p holds %x\n", (void*)&p[4], p[4]);
    printf("address %p holds %x\n", (void*)&p[5], p[5]);
    printf("address %p holds %x\n", (void*)&p[6], p[6]);
    printf("address %p holds %x\n", (void*)&p[7], p[7]);

    printf("\n");
    write(sockfd, &buffer, sizeof(char) * 10);*/
    printf("2 + 8 bytes...\n");
    read(sockfd, &buf, sizeof(uint8_t) * 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");
    i16 = (buf[0] << 8 | buf[1]);
    p = (unsigned char *) &i16;
    printf("From client: %u\nHere are the memory representations...\n", i16);;
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    i64 = ((uint64_t)buf[2] << 56 | (uint64_t)buf[3] << 48 | (uint64_t)buf[4] << 40 | (uint64_t)buf[5] << 32 | buf[6] << 24 | buf[7] << 16 | buf[8] << 8 | buf[9]);
    p = (unsigned char *) &i64;
    printf("From client: %lu\nHere are the memory representations...\n", i64);
    printf("address %p holds %x\n", (void*)&p[0], p[0]);
    printf("address %p holds %x\n", (void*)&p[1], p[1]);
    printf("address %p holds %x\n", (void*)&p[2], p[2]);
    printf("address %p holds %x\n", (void*)&p[3], p[3]);
    printf("address %p holds %x\n", (void*)&p[4], p[4]);
    printf("address %p holds %x\n", (void*)&p[5], p[5]);
    printf("address %p holds %x\n", (void*)&p[6], p[6]);
    printf("address %p holds %x\n", (void*)&p[7], p[7]);

    printf("\n");
    write(sockfd, &bytess, sizeof(uint8_t) * 10);

} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd;
    socklen_t len; 
    struct sockaddr_in servaddr, cli; 
    if (is_bigendian()) {
        printf("big endian\n");
    } else {
        printf("little endian\n");
    }
    // socket create and verification 
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n\n\n"); 
  
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 
