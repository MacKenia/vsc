#include "filetransfer.h"

int main()
{
    int piece;
    char ip[] = "127.0.0.1";
    char file[] = "input.mp4";
    printf("输入线程数: ");
    scanf("%d",&piece);
    filetransfer video(ip,file,piece);
    video.send();
    return 0;
}
