//socket udp 客户端
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include <string.h>
#include <jni.h>
#include "base.h"
#include <time.h>

#define MAX_DATA 1024//接收到的数据最大程度

/**
 *
 * @param message
 * @param ip
 * @param port
 * @param recv_listener  回调，详见 http://www.runoob.com/cprogramming/c-fun-pointer-callback.html
 * @return
 */
//int main_udp_send(const char *message, const char *ip, int port, void (*recv_listener)(const char *),JNIEnv *env, jobject jobject) {
int udp_send(const char *message, const char *ip, int port,
                  void (*recv_listener)(const char *, JNIEnv *env, jobject instance), JNIEnv *env,
                  jobject instance) {
    LOGI(" udp send 1");
    char buf[MAX_DATA];//储存接收数据
    //创建socket对象
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    //创建网络通信对象
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    //https://blog.csdn.net/lovekun1989/article/details/41048303
    /* 设置通讯方式对广播，即本程序发送的一个消息，网络上所有主机均可以收到 */
    int yes = 1;
    int broadcast = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(yes));
    LOGI("set broadcast:%d", broadcast);
    struct timeval tv = {10, 0};
    //设置超时，超时后 recvfrom会返回负数
    int timeout = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&tv, sizeof(tv));
    LOGI("set timeout:%d", timeout);


    //strcpy(buf, "hello from client 你好");
    strcpy(buf, message);
    sendto(sockfd, &buf,
           sizeof(buf), 0, (struct sockaddr *) &addr, sizeof(addr));
    LOGI(" udp send 2");

    for (int i = 0; i < MAX_DATA; ++i) {
        buf[i] = 0x00;
    }
    socklen_t len = sizeof(addr);

    /*
    C语言获取时间戳 >> 两个时间比较
    time_t t_start, t_end;
    t_start = time(NULL) ;
    sleep(3);
    t_end = time(NULL) ;
    LOGI("time t_start: %ld s\n",t_start);
    LOGI("time t_end: %ld s\n",t_end);
    LOGI("time: %.0f s\n", difftime(t_end,t_start));*/

    while (1) {
        LOGI("while>>");
        ssize_t n = recvfrom(sockfd, &buf, sizeof(buf), 0, (struct sockaddr *) &addr, &len);
        LOGI(" udp revc: %s", buf);
        LOGI("ssize_t n:%zd",n);
        if(n>=0){
            recv_listener(buf, env, instance);
        }else{
            break;
        }
    }
    LOGI("close sockfd");
    close(sockfd);
    return 0;
}