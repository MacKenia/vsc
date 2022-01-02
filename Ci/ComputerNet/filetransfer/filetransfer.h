#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>

#ifndef FILETRANSFER_H
#define FILETRANSGER_H

typedef struct StandardDataStruct
{
    char flag; // 1 text 2 file 3 info 8 finish 16 
    int offset; // offset of present frame(length of data)
    unsigned long int number; // number of present fragmane when flag == 3 present slice
    char data[1024];
    // info : name0size
} STD;

typedef unsigned long int Uint;

class filetransfer
{
private:
    int send_socket = 0;
    int recv_socket = 0;
    int yes;
    struct sockaddr_in send_addr;
    struct sockaddr_in recv_addr;
    char *ip;

    FILE *input = nullptr, *output = nullptr;
    char *filename;
    int slice; // num of fragments
    Uint num; // file sequence
    Uint size = 0; // size of the file
    Uint len = 0; // K size of the file

public:
    char ERROR; // 1 local ip miss
    filetransfer();
    filetransfer(char*);
    filetransfer(char *,int);
    void send(void); // start send file
    void recv();
    void exit();

protected:
    void inits();
    void initr();
    void scan();
    char* ipc();
    char* tochar(int);
    int toint(char*);
};


#endif