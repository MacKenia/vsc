// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    int Socket;

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(13080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    Socket = socket(AF_INET,SOCK_STREAM,0);

    if(Socket == -1)
    {   // 创建套接字
        perror("socket");
    }

    int yes = 1;
    if(setsockopt(Socket,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1)
    {   //
        perror("setsockopt");
    }
    bind(Socket,(struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(Socket,20);

    struct sockaddr_in clientaddr;
    socklen_t client_addr_size = sizeof(clientaddr);
    int client_socket = accept(Socket, (struct sockaddr *)&clientaddr,&client_addr_size);

    char mess[] = "Hello";
    write(client_socket,mess,sizeof(mess));

    close(client_socket);
    close(Socket);

    return 0;
}
