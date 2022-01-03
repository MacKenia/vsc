#include "filetransfer.h"

using namespace std;

int main()
{
    char ip[] = "127.0.0.1";
    filetransfer video(ip);
    video.recv();
    return 0;
}
