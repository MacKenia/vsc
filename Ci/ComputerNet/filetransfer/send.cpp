#include "filetransfer.h"

int main()
{
    char file[] = "input.mp4";
    filetransfer video(file);
    video.send();
    video.exit();
    return 0;
}
