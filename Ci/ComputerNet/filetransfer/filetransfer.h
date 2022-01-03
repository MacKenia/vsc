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
#include <curses.h>

#ifndef FILETRANSFER_H
#define FILETRANSGER_H

typedef struct StandardDataStruct
{
    char flag; // 1 text 2 file 3 info 4 start 8 finish 16 
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
    static int yes;
    static int done[32];
    static const int start = 10000;
    struct sockaddr_in send_addr;
    struct sockaddr_in recv_addr;
    static char *ip;

    static char *filename;
    static int slice; // num of fragments
    static Uint size; // size of the file

public:
    char ERROR; // 1 local ip miss
    filetransfer(char*);
    filetransfer(char*,char*);
    filetransfer(char*,char *,int);
    void send(); // start send file
    void recv();
    void setip(char*);
    static int toint(char*);
    static char* tochar(int);
    static char* ipc();

protected:
    static void *send_fragment(void *);
    static void *recv_fragment(void *);
    void merge_fragment();
    void inits();
    void initr();
    void scan();
};


#endif