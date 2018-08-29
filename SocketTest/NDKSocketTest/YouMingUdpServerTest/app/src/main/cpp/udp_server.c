//socket udp 服务端
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <string.h>
#include "base.h"

#define MAX_STRING_LENGTH 1024

int main_udp_recv(const char *ip, int port) {
    LOGI("udp recv 1");
    //创建socket对象
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    char buf[1024] = {0};
    //创建网络通信对象
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    LOGI("udp recv 2");
    //绑定socket对象与通信链接
    int ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    LOGI("udp recv ret %d", ret);
    if (0 > ret) {
        LOGI("bind faild\n");
        return -1;
    }

    struct sockaddr_in cli;
    socklen_t len = sizeof(cli);

    //rcv_num = recvfrom(sockfd, rcv_buff, sizeof(rcv_buff), 0, (struct sockaddr*)&client_addr, &client_len);
    LOGI("udp recv 3");
    recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &cli, &len);
    LOGI("recv>> %s\n", buf);
    for (int i = 0; i < MAX_STRING_LENGTH; ++i) {
        buf[MAX_STRING_LENGTH] = 0x00;
    }
    strcpy(buf, "this is 来自 server 的消息");
    sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &cli, len);

    /*while (1) {
        char buf = 0;
        LOGI("udp recv 3");
        recvfrom(sockfd, &buf, sizeof(buf), 0, (struct sockaddr *) &cli, &len);
        LOGI("recv>> %s\n", buf);

        sendto(sockfd, &buf, sizeof(buf), 0, (struct sockaddr *) &cli, len);
    }*/
    close(sockfd);

}