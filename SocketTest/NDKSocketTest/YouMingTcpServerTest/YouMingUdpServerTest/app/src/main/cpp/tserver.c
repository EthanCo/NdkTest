#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <strings.h>
#include "base.h"

#define PORT 12669 //Unassigned port by IANA standards
#define MAX_LISTEN 5/*最大监听数*/
#define MAX_DATA 1024

int t_recv() {
    int server_fd; //socket句柄
    struct sockaddr_in address; //本方地址信息结构体
    char buf[MAX_DATA];//储存接收数据
    server_fd = socket(AF_INET, SOCK_STREAM, 0); //建立Socket
    LOGI("建立Socket server_fd:%d", server_fd);
    if (server_fd == -1) {
        LOGE("socket failed:%d", server_fd);
        return -1;
    }
    if (server_fd == 0) {
        LOGE("socket failed:%d", server_fd);
        return -1;
    }

    //初始化本方地址信息
    address.sin_family = AF_INET; /*该属性表示接收本机或其他机器传输*/
    address.sin_port = htons(PORT); //端口号
    address.sin_addr.s_addr = htonl(INADDR_ANY);;  /*IP，括号内容表示本机IP*/ //TODO 有区别

    //bzero(&(address.sin_zero),8);/*将其他属性置0*/
    int addrlen = sizeof(address);

    int bind_result = bind(server_fd, (struct sockaddr *) &address, sizeof(address));
    LOGI("bind_result:%d", bind_result);
    if (bind_result < 0) {
        LOGE("Bind failed");
        return -1;
    }
    int listen_result = listen(server_fd, MAX_LISTEN);
    LOGI("listen_result:%d", listen_result);
    if (listen_result < 0) {
        LOGE("Listen failed");
        return -1;
    }
    int accept_result = accept(server_fd, (struct sockaddr *) &address, (socklen_t *) &addrlen);
    LOGI("accept_result:%d", accept_result);
    if (accept_result < 0) {
        LOGE("Accept failure");
        return -1;
    }
    if (accept_result == -1) {
        LOGI("receive failed");
    } else {
        LOGI("receive success");
        char *send_message = "Hello 你好呀";
        for (int i = 0; i < MAX_DATA; ++i) {
            buf[i] = 0;
        }
        read(accept_result, buf, MAX_DATA);
        LOGI("Received:%s", buf);
        //send(accept_result, "Hello World!", 12, 0);//发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可）
        send(accept_result, send_message, strlen(send_message),
             0);//发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可）
    }
    close(server_fd);
    return 0;
}