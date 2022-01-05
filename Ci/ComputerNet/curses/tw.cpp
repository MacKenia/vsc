#include <bits/stdc++.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    initscr();
    WINDOW *tip = newwin(LINES/3, COLS/3, LINES/3, COLS/3);
    refresh();
    box(tip,'|','-');
    
    wmove(tip,0,2);
    wprintw(tip,"提示");

    wmove(tip,5,12);
    wprintw(tip,"%s","传输完成");
    wrefresh(tip);

    getchar();
    return 0;
}

int x()
{
    int piece;
    char ip[15];
    char file[80];
    int sl;
    WINDOW *info;
    info = newwin(20,60,LINES/4,COLS/4);
    refresh();
    box(info,'|','-');
    wrefresh(info);

    wmove(info,2,1);
    wprintw(info,"%s\n\nasdf\n%d","请输入文件名: ",sl);
    wrefresh(info);
    wgetstr(info,file);
    wprintw(info,"%s",file);

    wmove(info,3,1);
    wprintw(info,"%s","请输入IP地址(回车则使用localhost): ");
    wrefresh(info);
    wgetstr(info,ip);
    wprintw(info,"%s",ip);

    wmove(info,4,1);
    wprintw(info,"%s","输入线程数: ");
    wgetstr(info,ip);
    endwin();
    return 0;
}
