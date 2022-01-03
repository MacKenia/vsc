#include "filetransfer.h"

int main()
{
    // setlocale(LC_ALL,"");
    // initscr();
    // char piece[3]; 
    // char ip[15];
    // char file[80];
    // WINDOW *info;
    // info = newwin(20,60,LINES/4,COLS/4);
    // refresh();
    // box(info,'|','-');
    // wrefresh(info);

    // wmove(info,2,2);
    // wprintw(info,"%s","请输入文件名: ");
    // wrefresh(info);
    // wgetstr(info,file);
    // // wprintw(info,"%s",file);

    // wmove(info,4,2);
    // wprintw(info,"%s","请输入IP地址(回车则使用localhost): ");
    // wrefresh(info);
    // wgetstr(info,ip);
    // // wprintw(info,"%s",ip);

    // wmove(info,6,2);
    // wprintw(info,"%s","输入线程数: ");
    // wgetstr(info,piece);
    // // wprintw(info,"%s",piece);

    // if(!ip[0]) strcpy(ip,"127.0.0.1");
    // wprintw(info,"%s","\n\n\n");
    // wprintw(info,"%s\n",ip);
    // wprintw(info,"%s\n",file);
    // wprintw(info,"%d\n",filetransfer::toint(piece));
    // // wrefresh(info);
    // // getchar();
    // endwin();
    
    // filetransfer video(ip,file,filetransfer::toint(piece));
    filetransfer video("127.0.0.1","input.mp4",2);
    video.send();
    // endwin();
    return 0;
}
