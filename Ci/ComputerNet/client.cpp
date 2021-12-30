// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
// #include <netinet/in.h>
#include <sys/socket.h>

using namespace std;



int main()
{
    int Client;
    char buffer[5];
    struct sockaddr_in client_addr;

    Client = socket(AF_INET,SOCK_STREAM,0);

    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    client_addr.sin_port = htons(13080);

    connect(Client,(struct sockaddr*)&client_addr, sizeof(client_addr));

    read(Client, buffer, sizeof(buffer));

    cout << buffer << endl;

    close(Client);

    return 0;
}
