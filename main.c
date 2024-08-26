#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "tcp.h"
#include "udp.h"

    int main(int argc, char *argv[]){
        // ./ssport <ip> <tcp/udp> <4/6> <log.txt>
        // 0 = tcp; 1 = udp
        if(argc != 5){
        char *ip = argv[1];
        char *proto = argv[2];
        int ipv = atoi(argv[3]);
        if(strcmp(proto, "tcp")==0){
            tcpScan(ip, ipv);
        }
        else if(strcmp(proto, "udp")==0){
            udpScan(ip, ipv);
        }




        }
        return 0;
    }