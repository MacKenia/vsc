#include "filetransfer.h"

int mrecv()
{
    setlocale(LC_ALL,"");
    initscr();
    char ip[15];
    WINDOW *info;
    info = newwin(LINES/2,COLS/2,LINES/4,COLS/4);
    refresh();
    box(info,'|','-');
    wrefresh(info);

    wmove(info,4,2);
    wprintw(info,"%s","请输入IP地址(回车则使用localhost): ");
    wrefresh(info);
    wgetstr(info,ip);
    // wprintw(info,"%s",ip);
    if(!ip[0]) strcpy(ip,"127.0.0.1");
    filetransfer video(ip);
    video.recv();
    return 0;
}

int msend()
{
    setlocale(LC_ALL,"");
    initscr();
    char piece[3]; 
    char ip[15];
    char file[80];
    WINDOW *info;
    info = newwin(LINES/2,COLS/2,LINES/4,COLS/4);
    refresh();
    box(info,'|','-');
    wrefresh(info);

    wmove(info,2,2);
    wprintw(info,"%s","请输入文件名: ");
    wrefresh(info);
    wgetstr(info,file);
    // wprintw(info,"%s",file);

    wmove(info,4,2);
    wprintw(info,"%s","请输入IP地址(回车则使用localhost): ");
    wrefresh(info);
    wgetstr(info,ip);
    // wprintw(info,"%s",ip);

    wmove(info,6,2);
    wprintw(info,"%s","输入线程数: ");
    wgetstr(info,piece);
    // wprintw(info,"%s",piece);

    if(!ip[0]) strcpy(ip,"127.0.0.1");
    wprintw(info,"%s","\n\n\n");
    wprintw(info,"%s\n",ip);
    wprintw(info,"%s\n",file);
    wprintw(info,"%d\n",filetransfer::toint(piece));
    // wrefresh(info);
    // getchar();
    // endwin();
    
    filetransfer video(ip,file,filetransfer::toint(piece));
    video.send();
    endwin();
    return 0;
}

int main()
{
    int i;
    printf("请选择操作: \n1. 发送文件\n2. 接收文件\n3. 退出> ");
    scanf("%d",&i);
    getchar();
    if(i==1)
        msend();
    if(i ==2) mrecv();
    if(i==3) exit(0);
    return 0;
}