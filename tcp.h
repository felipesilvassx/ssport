#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "ipv4.h"
#include "ipv6.h"

    void tcpScan(char *target, int recvIpv){
        // 0 = tcp; 1 = udp
        int proto = 0;
        if(recvIpv == 4){
            ipv4Scan(target, proto);
        }
        else if(recvIpv == 6){
            int proto = 0;
            ipv6Scan(target, proto);
        }

        else{
            printf("=== SSPort v1.0 by levi_jr ===\n");
            printf("uso: ./ssport <ip> <tcp/udp> <ipv4/ipv6> <log.txt>\n");
            printf("exemplo: ./ssport 127.0.0.1 tcp 4 log.txt\n");
            printf("ou: ./ssport 127.0.0.1 udp 4 log.txt\n");
            printf("use 4 para ipv4 ou 6 para ipv6\n");
        }
    }