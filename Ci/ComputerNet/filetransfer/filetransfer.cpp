#include "filetransfer.h"

Uint filetransfer::size = 0;
char *filetransfer::ip;
char *filetransfer::filename;
int filetransfer::slice; // num of fragments
int filetransfer::yes;
int filetransfer::done[32];

filetransfer::filetransfer(char *add)
{
    setlocale(LC_ALL, "");
    initscr();
    ip = add;
}

filetransfer::filetransfer(char *add, char *input)
{
    setlocale(LC_ALL, "");
    initscr();
    // printf("欢迎使用");
    slice = 1;
    filename = input;
    ip = add;
}

filetransfer::filetransfer(char *add, char *input, int n)
{
    setlocale(LC_ALL, "");
    initscr();
    // printf("欢迎使用");
    filename = input;
    slice = n;
    ip = add;
    if (slice > 32)
        slice = 32;
}

void filetransfer::inits()
{
    // printf("初始化...");
    send_addr.sin_family = AF_INET;
    send_addr.sin_port = htons(11451);
    send_addr.sin_addr.s_addr = inet_addr(ip);
}

void filetransfer::initr()
{
    // printf("初始化...");
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(11451);
    recv_addr.sin_addr.s_addr = inet_addr(ip);
}

void filetransfer::send()
{
    // int cols = COLS;
    char rate[COLS - 1];
    memset(rate, '-', sizeof(rate));
    rate[0] = '[';
    rate[COLS - 2] = '\0';
    rate[COLS - 3] = ']';
    // for (int i = 0; i < COLS-2; i++)
    // {
    //     if(i==0) rate[i] = '[';
    //     else if(i==COLS-3) rate[i] = ']';
    //     else rate[i] = '-';
    //     // printf("%c",rate[i]);
    // }

    refresh();
    WINDOW *info = newwin(8, COLS, 0, 0);
    box(info, '|', '-');
    wrefresh(info);

    scrollok(info, true);

    inits();
    wprintw(info, "%s", "  初始化成功\n");
    box(info, '|', '-');
    wrefresh(info);

    // getchar();
    // return ;

    send_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (send_socket == -1)
    {
        perror("socket init failed");
    }
    wprintw(info, "%s", "  套接字创建成功\n");
    box(info, '|', '-');
    wrefresh(info);

    yes = 1;
    if (setsockopt(send_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        perror("setsockopt failed\n");
    }
    wprintw(info, "%s", "  端口复用配置成功\n");
    box(info, '|', '-');
    wrefresh(info);
    // printf("端口复用配置成功\n");

    bind(send_socket, (struct sockaddr *)&send_addr, sizeof(send_addr));
    wprintw(info, "%s", "  套接字绑定成功\n");
    box(info, '|', '-');
    wrefresh(info);
    // printf("套接字绑定成功\n");

    Uint num;     // file sequence
    Uint len = 0; // K size of the file

    STD tmp;
    tmp.offset = 0;
    tmp.number = 0;
    memset(tmp.data, 0, sizeof(tmp.data));
    tmp.flag = 3; // 0000 0011
    tmp.offset += strlen(filename);
    strcpy(tmp.data, filename);

    FILE *input = fopen(filename, "rb");
    fseek(input, 0, SEEK_END);
    size = ftell(input);
    len = size % 1024 ? size / 1024 + 1 : size / 1024;
    fseek(input, 0, SEEK_SET);

    strcpy(&tmp.data[tmp.offset + 1], tochar(size));
    for (int i = size; i > 0; i /= 10)
        tmp.offset++;

    tmp.number = slice;

    wprintw(info, "%s%s\n", "  文件名: ", filename);
    wprintw(info, "%s%dB\n", "  分片数: ", size);
    wprintw(info, "%s%d\n", "  分片数: ", len);
    wprintw(info, "%s%d\n", "  线程数: ", slice);
    box(info, '|', '-');
    wrefresh(info);
    // printf("文件名: %s\t文件大小: %d\t分片数: %d\t线程数: %d\n",filename,size,len,slice);

    listen(send_socket, 20);
    wprintw(info, "%s\n", "  开始监听, 准备传输");
    box(info, '|', '-');
    wrefresh(info);
    // printf("开始监听, 准备传输\n");

    socklen_t client_addr_size = sizeof(recv_addr);
    recv_socket = accept(send_socket, (struct sockaddr *)&recv_addr, &client_addr_size);

    wprintw(info, "%s\n", "  连接成功");
    box(info, '|', '-');
    wrefresh(info);

    // getchar();
    // printf("连接接成功,%d\n",recv_socket);

    write(recv_socket, (char *)&tmp, sizeof(tmp));

    if (slice == 1)
    {
        WINDOW *single = newwin(3, COLS, 9, 0);
        box(single, '|', '-');
        wmove(single, 0, 2);
        wprintw(single, "%s", "发送");
        wrefresh(single);

        wmove(single, 1, 1);
        wprintw(single, "%s", rate);
        wrefresh(single);

        usleep(100);

        // printf("开始传输\n");
        for (int i = 0; i < len; i++)
        {
            tmp.flag &= 0;
            tmp.flag |= 2;
            tmp.number = i;
            if (i == len - 1)
            {
                tmp.flag |= 8;
                if (size % 1024)
                    tmp.offset = size % 1024;
            }
            else
                tmp.offset = 1024;
            memset(tmp.data, 0, sizeof(tmp.data));
            // std::cout << "\r"<< i <<  '\t';
            fread(&tmp.data, tmp.offset, 1, input);
            write(recv_socket, (char *)&tmp, sizeof(tmp));
            // printf("%.2f%%", ftell(input)*1.0 / size*100);
            // rate[(int)(i*1.0/len*(COLS-4))+1] = '#';
            for (int k = (i - 1) * 1.0 / len * (COLS - 4); k < (i)*1.0 / len * (COLS - 4); k++)
                rate[k] = '#';
            wmove(single, 1, 1);
            wprintw(single, "%s", rate);
            wmove(single, 2, 2);
            wprintw(single, "%d%%", (int)(i * 100.0 / len));
            if(!(i%1024)) wrefresh(single);
            // if(!(i%100)) usleep(3);
            usleep(sqrt(len/1024)*slice);
            // printf("%d,",i);
        }

        memset(rate, '#', sizeof(rate));
        rate[0] = '[';
        rate[COLS - 2] = '\0';
        rate[COLS - 3] = ']';
        wmove(single, 1, 1);
        wprintw(single, "%s", rate);

        wmove(single, 2, 2);
        wprintw(single, "%s%%", "100");
        wrefresh(single);

        // return;
        // printf("发送完成\n");
        // fclose(input);
        endwin();
    }
    else
    {
        pthread_t *threads = new pthread_t(slice);
        int *index = new int(slice);
        for (int i = 0; i < slice; i++)
        {
            index[i] = i;
            if (
                pthread_create(&threads[i], nullptr, send_fragment, (void *)&(index[i])))
            {
                // printf("%d: 创建线程失败\n", i);
            }
            usleep(1);
        }
        for (int i = 0; i < slice; i++)
            if (!done[i])
                i -= 1;
        // pthread_exit(nullptr);
    }
    endwin();
    WINDOW *tip = newwin(LINES/3, COLS/3, LINES/3+3, COLS/3);
    refresh();
    box(tip,'|','-');
    
    wmove(tip,0,2);
    wprintw(tip,"提示");

    wmove(tip,5,12);
    wprintw(tip,"%s","传输完成");
    wrefresh(tip);

    getchar();
    endwin();
}

void filetransfer::recv()
{
    char rate[COLS - 1];
    memset(rate, '-', sizeof(rate));
    rate[0] = '[';
    rate[COLS - 2] = '\0';
    rate[COLS - 3] = ']';

    refresh();
    WINDOW *info = newwin(8, COLS, 0, 0);
    box(info, '|', '-');
    wrefresh(info);

    scrollok(info, true);

    initr();
    wprintw(info, "%s", "  初始化成功\n");
    box(info, '|', '-');
    wrefresh(info);

    // initr();
    // printf("初始化成功\n");

    recv_socket = socket(AF_INET, SOCK_STREAM, 0);
    // printf("套接字创建成功\n");
    wprintw(info, "%s", "  套接字创建成功\n");
    box(info, '|', '-');
    wrefresh(info);

    connect(recv_socket, (struct sockaddr *)&recv_addr, sizeof(recv_addr));
    // printf("等待连接\n");
    wprintw(info, "%s", "  等待连接\n");
    box(info, '|', '-');
    wrefresh(info);

    Uint num;     // file sequence
    Uint len = 0; // K size of the file

    STD tmp;
    memset(tmp.data, 0, sizeof(tmp.data));

    tmp.flag = 0;
    while (tmp.flag != 3)
        read(recv_socket, (char *)&tmp, sizeof(tmp));

    filename = new char(strlen(tmp.data));

    strcpy(filename, tmp.data);
    size = toint(&tmp.data[strlen(tmp.data) + 1]);

    slice = tmp.number;

    len = size % 1024 ? size / 1024 + 1 : size / 1024;

    wprintw(info, "%s%s\n", "  文件名: ", filename);
    wprintw(info, "%s%dB\n", "  分片数: ", size);
    wprintw(info, "%s%d\n", "  分片数: ", len);
    wprintw(info, "%s%d\n", "  线程数: ", slice);
    box(info, '|', '-');
    wrefresh(info);
    // printf("文件名: %s\t文件大小: %d\t分片数: %d\t线程数: %d\n",filename,size,len,slice);

    FILE *output = fopen(filename, "wb+");

    if (slice == 1)
    {
        WINDOW *single = newwin(3, COLS, 9, 0);
        box(single, '|', '-');
        wmove(single, 0, 2);
        wprintw(single, "%s", "接收");
        wrefresh(single);

        wmove(single, 1, 1);
        wprintw(single, "%s", rate);
        wrefresh(single);

        int l = 0;
        while (tmp.flag & 2)
        {
            memset(tmp.data, 0, sizeof(tmp.data));
            read(recv_socket, (char *)&tmp, sizeof(tmp));
            if (tmp.offset < 0)
                continue;
            // std::cout << "\r";
            // std::cout << read(recv_socket,(char*)&tmp,sizeof(tmp)) << "\t";
            // std::cout << fwrite(&tmp.data,tmp.offset,1,output) << "\t";
            fwrite(&tmp.data, tmp.offset, 1, output);
            // printf("%d\t%d\t%d\t",tmp.offset,tmp.flag,tmp.number);
            // printf("%.2f%%\n", ftell(output)*1.0 / size*100);

            // rate[(int)(ftell(output)*1.0/size*(COLS-4))+1] = '#';
            for (int k = l; k < ftell(output)*1.0 / size * (COLS - 4) + 1; k++)
                rate[k] = '#';
            l = ftell(output)*1.0 / size * (COLS - 4) + 1;
            wmove(single, 1, 1);
            wprintw(single, "%s", rate);
            wmove(single, 2, 2);
            wprintw(single, "%d%%", (int)(ftell(output) * 100.0 / size));
            if(!(ftell(output)%10240)) wrefresh(single);
            if (tmp.flag & 8)
                break;
            // tmp.flag = 0;
        }
        memset(rate, '#', sizeof(rate));
        rate[0] = '[';
        rate[COLS - 2] = '\0';
        rate[COLS - 3] = ']';

        wmove(single, 2, 2);
        wprintw(single, "%s%%", "100");
        wmove(single,1,1);
        wprintw(single,"%s",rate);
        wrefresh(single);
        usleep(10);
        // printf("接收完成\n");
        // getchar();
        fclose(output);
        endwin();
    }
    else
    {
        pthread_t *threads = new pthread_t(slice);
        int *index = new int(slice);
        for (int i = 0; i < slice; i++)
        {

            index[i] = i;
            if (
                pthread_create(&threads[i], nullptr, recv_fragment, (void *)&(index[i])))
            {
                // printf("%d: 创建线程失败\n", i);
            }
            usleep(2);
        }

        for (int i = 0; i < slice; i++)
            if (!done[i])
                i -= 1;
        // pthread_exit(nullptr);
        merge_fragment();
    }
    endwin();
    WINDOW *tip = newwin(LINES/3, COLS/3, LINES/3+3, COLS/3);
    refresh();
    box(tip,'|','-');
    
    wmove(tip,0,2);
    wprintw(tip,"提示");

    wmove(tip,5,12);
    wprintw(tip,"%s","传输完成");
    wrefresh(tip);

    getchar();
    endwin();
}

char *filetransfer::ipc()
{
    int sfd, intr;
    struct ifreq buf[16];
    struct ifconf ifc;
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sfd < 0)
        return 0;
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;
    if (ioctl(sfd, SIOCGIFCONF, (char *)&ifc))
        return 0;
    intr = ifc.ifc_len / sizeof(struct ifreq);
    while (intr-- > 0 && ioctl(sfd, SIOCGIFADDR, (char *)&buf[intr]))
        ;
    close(sfd);
    return inet_ntoa(((struct sockaddr_in *)(&buf[intr].ifr_addr))->sin_addr);
}

void *filetransfer::send_fragment(void *fid)
{
    initscr();
    int id = *((int *)fid);

    WINDOW *sing = newwin(3, COLS, 9 + id * 4, 0);
    // box(sing, '|', '-');
    wmove(sing, 0, 2);
    usleep(rand() % 10);
    wprintw(sing, "%s%d", "线程", id);
    wrefresh(sing);
    usleep(rand() % 10);

    int send_s = 0;
    int recv_s = 0;
    struct sockaddr_in send_a;
    struct sockaddr_in recv_a;
    // printf("%d: 开始初始化线程",id);

    send_a.sin_family = AF_INET;
    send_a.sin_port = htons(start + id);
    send_a.sin_addr.s_addr = inet_addr(ip);

    send_s = socket(AF_INET, SOCK_STREAM, 0);

    wmove(sing, 0, 8);
    usleep(rand() % 100);
    wprintw(sing, "线程套接字:{%s:%d}", ip, start + id);
    wrefresh(sing);
    // printf("%d: 分配套接字{%s:%d}\n",id,ip,start+id);

    if (send_s == -1)
    {
        perror("创建套接字失败");
        // printf("%d: 创建失败\n",id);
    }
    // printf("%d: 套接字创建成功\n",id);

    yes = 1;
    if (setsockopt(send_s, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        perror("setsockopt failed\n");
    }
    // printf("%d: 端口复用配置成功\n",id);

    bind(send_s, (struct sockaddr *)&send_a, sizeof(send_a));
    // printf("%d: 套接字绑定成功\n",id);

    FILE *input = fopen(filename, "rb");
    Uint Ksize, Lsize, Fsize, loopctl;

    Ksize = size / 1024;
    Fsize = Ksize / slice * slice / slice;
    Lsize = size - Fsize * 1024 * (slice - 1);

    STD tmp;
    tmp.flag = 2;
    tmp.offset = 1024;
    tmp.number = 0;

    loopctl = Fsize;

    if (id == slice - 1)
    {
        if (Lsize % 1024 == 0)
            loopctl = Lsize / 1024;
        else
        {
            loopctl = Lsize / 1024 + 1;
            // printf("%d: 片大小: %d\n",id,Lsize);
        }
    }
    // else
    // printf("%d: 片大小: %d\n",id,Fsize*1024);

    fseek(input, id * Fsize * 1024, SEEK_SET);

    listen(send_s, 20);
    // printf("%d: 开始监听, 准备传输\n",id);

    // printf("\n\n%d: 当前分片数: %d\n\n",id,loopctl);

    socklen_t recv_size = sizeof(recv_a);
    recv_s = accept(send_s, (struct sockaddr *)&recv_a, &recv_size);

    // printf("%d: 连接接成功,%d\n",id,recv_s);

    usleep(rand() % (slice + 1));

    // 发送开始信息
    tmp.flag = 4;
    tmp.flag |= 3;
    tmp.number = loopctl;
    // strcpy(tmp.data, "淦");

    write(recv_s, (char *)&tmp, sizeof(tmp));

    // printf("%d: 开始传输\n",id);

    for (int i = 0; i < loopctl; i++)
    {
        tmp.flag &= 0;
        tmp.flag |= 2;
        tmp.number = i;
        memset(tmp.data, 0, sizeof(tmp.data));
        if (i == loopctl - 1)
        {
            tmp.flag |= 8;
            if (id == slice - 1 && size % 1024)
                tmp.offset = size % 1024;
        }
        // std::cout << "\n" << i << "\n";
        // std::cout << fread(&tmp.data, tmp.offset, 1, input) << "\t";
        fread(&tmp.data, tmp.offset, 1, input);
        // if(id) printf("%s\t",tmp.data);
        // std::cout << write(recv_s,(char*)&tmp, sizeof(tmp)) << "\t";
        write(recv_s, (char *)&tmp, sizeof(tmp));
        // if(!id) printf("\r");
        // printf("%d: %.2f%%\t",id, i*1024*1.0 / size*100);
        wmove(sing, 2, 2);
        usleep(rand() % 100);
        if (!(i % 100))
            wprintw(sing, "%d%%", (int)(i * 100.0 / loopctl));
        wrefresh(sing);
        refresh();
        usleep(sqrt(loopctl/1024)*slice);
    }
    // printf("%d: 发送完成\n",id);

    usleep(rand() % 10);
    wmove(sing, 2, 2);
    usleep(rand() % 100);
    wprintw(sing, "%s%%", "100");
    wrefresh(sing);

    fclose(input);
    close(send_s);
    close(recv_s);

    done[id] = 1;
    // getchar();
    endwin();
    pthread_exit(nullptr);
}

void *filetransfer::recv_fragment(void *fid)
{
    initscr();
    int id = *((int *)fid);

    WINDOW *sing = newwin(3, COLS, 9 + id * 4, 0);
    wmove(sing, 0, 2);
    usleep(rand() % 100);
    wprintw(sing, "%s%d", "线程", id);
    wrefresh(sing);
    usleep(rand() % 10);

    int recv_s = 0;
    struct sockaddr_in recv_a;

    // printf("%d: 开始初始化线程",id);
    char tmpname[] = "t0";
    tmpname[1] += id;
    FILE *output = fopen(tmpname, "wb+");

    recv_a.sin_family = AF_INET;
    recv_a.sin_port = htons(start + id);
    recv_a.sin_addr.s_addr = inet_addr(ip);

    Uint Ksize, Lsize, Fsize, loopctl;

    Ksize = size / 1024;
    Fsize = Ksize / slice * slice / slice;
    Lsize = size - Fsize * 1024 * (slice - 1);

    usleep(rand() % 10);
    wmove(sing, 0, 8);
    usleep(rand() % 100);
    wprintw(sing, "线程套接字:{%s:%d}", ip, start + id);
    wrefresh(sing);
    // printf("%d: 分配套接字{%s:%d}\n",id,ip,start+id);

    recv_s = socket(AF_INET, SOCK_STREAM, 0);
    // printf("%d: 创建套接字成功\n",id);

    // printf("%d: 等待连接\n",id);
    connect(recv_s, (struct sockaddr *)&recv_a, sizeof(recv_a));
    // printf("%d: 连接成功",id);

    STD tmp;
    tmp.flag &= 0;
    while (!(tmp.flag & 4))
    {
        read(recv_s, (char *)&tmp, sizeof(tmp));
        // printf("\r%d: 等待开始",id);
    }

    // if (tmp.flag & 3)
    // printf("\n\n%s\n\n", tmp.data);
    // printf("\n%d: 开始传输",id);

    int l = tmp.number;
    int i = 0;
    while (tmp.flag & 2)
    {
        // if (!id)
        // printf("\r");
        memset(tmp.data, 0, sizeof(tmp.data));
        // std::cout << read(recv_s,(char*)&tmp,sizeof(tmp)) << "\t";
        read(recv_s, (char *)&tmp, sizeof(tmp));
        // std::cout << fwrite(&tmp.data,tmp.offset,1,output) << "\t";
        fwrite(&tmp.data, tmp.offset, 1, output);
        // printf("%d\t%d\t%d\t",tmp.offset,tmp.flag,tmp.number);
        // printf("%.2f%%", ftell(output)*1.0 / size*100);
        wmove(sing, 2, 2);
        usleep(rand() % 100);
        wprintw(sing, "%d%%", (int)(ftell(output) * 1.0 / l));
        if(!(ftell(output)%10240)) wrefresh(sing);
        if (tmp.flag & 8)
            break;
    }

    wmove(sing, 2, 2);
    usleep(rand() % 100);
    wprintw(sing, "%s%%", "100");
    refresh();
    wrefresh(sing);
    // printf("%d: 接收完成\n",id);

    fclose(output);
    close(recv_s);

    done[id] = 1;
    // getchar();
    endwin();
    pthread_exit(nullptr);
}

void filetransfer::merge_fragment()
{
    initscr();
    WINDOW *tip = newwin(5, COLS, LINES / 4, 0);
    refresh();
    box(tip, '|', '-');
    wrefresh(tip);

    char rate[COLS - 1];
    memset(rate, '-', sizeof(rate));
    rate[0] = '[';
    rate[COLS - 2] = '\0';
    rate[COLS - 3] = ']';

    wmove(tip, 0, 2);
    wprintw(tip, "%s", "合并分片");

    wmove(tip, 2, 2);
    wprintw(tip, "%s", rate);
    wrefresh(tip);
    // printf("\n开始合并分片\n");

    FILE *input;
    char tmpname[] = "t0";
    char buf[1024];
    FILE *output = fopen(filename, "wb+");
    Uint total = 0;

    wmove(tip, 1, 2);
    wprintw(tip, "文件名: %s, 分片数: %d, 文件总大小: %d\n", filename, slice, size);
    wrefresh(tip);

    // printf("文件名: %s, 分片数: %d, 文件总大小: %d\n", filename, slice, size);
    for (int i = 0; i < slice; i++)
    {
        int tsize = 0, Ksize = 0, Rsize = 0;

        input = fopen(tmpname, "rb");
        tmpname[1]++;
        fseek(input, 0, SEEK_END);
        tsize = ftell(input);
        fseek(input, 0, SEEK_SET);
        total += tsize;

        // std::cout << tmpname << ":" << tsize << std::endl;
        Ksize = tsize % 1024 ? tsize / 1024 + 1 : tsize / 1024;
        Rsize = 1024;
        for (int j = 0; j < Ksize; j++)
        {
            usleep(1);
            if (i == slice - 1 && j == Ksize - 1 && tsize % 1024)
                Rsize = tsize % 1024;
            memset(buf, 0, sizeof(buf));

            fread(&buf, Rsize, 1, input);
            fwrite(&buf, Rsize, 1, output);

            for (int k = 0; k < (ftell(output) * 1.0 / size) * (COLS - 4); k++)
                rate[k] = '#';

            wmove(tip, 2, 1);
            wprintw(tip, "%s", rate);
            wrefresh(tip);
        }
        fclose(input);
    }
    fclose(output);

    wmove(tip, 3, 2);
    wprintw(tip, "文件差值: %d - %d = %d\n", total, size, total - size);
    wmove(tip, 4, COLS / 2 - 1);
    wprintw(tip, "OK");
    wrefresh(tip);
    // printf("文件差值: %d - %d = %d\n", total, size, total - size);
}

char *filetransfer::tochar(int a)
{
    int len = 1;
    for (int i = a; i > 0; i /= 10)
        len++;
    char *tmp = new char(len + 1);
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < len; i++, a /= 10)
    {
        tmp[len - i - 2] = '0' + a % 10;
    }
    return tmp;
}

int filetransfer::toint(char *s)
{
    int tmp = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        tmp += pow(10, i) * (s[strlen(s) - i - 1] - '0');
    }
    return tmp;
}

void filetransfer::scan()
{
}

void filetransfer::setip(char *s)
{
    ip = s;
}
