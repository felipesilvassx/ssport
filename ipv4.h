#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#ifndef ipv4s
#define ipv4s

// 65535 portas

    void ipv4Scan(char *ip, int proto){
        struct sockaddr_in addr;
        char buff[256];
        int cnx = 0, sock = 0, rc = 0;
        for(int loop=0; loop<= 65535; loop++){
            addr.sin_family = AF_INET;
            addr.sin_addr.s_addr = inet_addr(ip);
            addr.sin_port = htons(loop);
            //tcp
            if(proto == 0){
                sock = socket(AF_INET, SOCK_STREAM, 0);
                if(sock < 0){
                    perror("socket error");
                    exit(EXIT_FAILURE);
                }
                cnx = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
                if(cnx == 0){
                    printf("*Porta => %d [tcp] aberta...\n", loop);
                }
            }//udp
            else if(proto == 1){
                char *msg = "HTTP/1.0";
                sock = socket(AF_INET, SOCK_DGRAM, 0);
                if(sock < 0){
                    perror("socket error");
                    exit(EXIT_FAILURE);
                }
                cnx = sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&addr, sizeof(addr));
                if(cnx > 0){
                    printf("*Porta => %d [udp] aberta...\n", loop);
                }
            }
            else{
                printf("=== SSPort v1.0 by levi_jr ===\n");
                printf("uso: ./ssport <ip> <tcp/udp> <ipv4/ipv6> <log.txt>\n");
                printf("exemplo: ./ssport 127.0.0.1 tcp 4 log.txt\n");
                printf("ou: ./ssport 127.0.0.1 udp 4 log.txt\n");
                printf("use 4 para ipv4 ou 6 para ipv6\n");
            }
            close(sock);
            

        }

    }
#endif