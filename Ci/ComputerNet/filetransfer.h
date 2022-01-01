#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef FILETRANSFER
#define FILETRANSGER

typedef struct StandardDataStruct
{
    char flag; // 1 text 2 file 4 begin 8 finish 16 offset
    int offset; // offset of present framc33771ae9c4b76284b76d4691fbb7ee1e 
    unsigned long int number;
    char data[1024];
} STD;

typedef unsigned long int uint;

class filetransfer
{
private:
    std::fstream *input;
    int slice;
    uint num; // file sequence
    uint max;
    uint size = 0;
    uint len = 0;

public:
    char ERROR; //
    filetransfer(std::fstream);

};


#endif