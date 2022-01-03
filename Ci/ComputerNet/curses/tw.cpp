#include <bits/stdc++.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>

using namespace std;

int main()
{
    WINDOW *tip = newwin(LINES/4, COLS/4, LINES, COLS);
    wrefresh(tip);

    getchar();
    return 0;
}

int x()
{
    setlocale(LC_ALL,"");
    initscr();
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
}
