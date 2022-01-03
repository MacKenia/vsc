#include "filetransfer.h"

int main()
{
    char ip[] = "127.0.0.1";
    char file[] = "input.txt";
    filetransfer video(ip,file,2);
    video.send();
    return 0;
}
