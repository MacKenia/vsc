#include "filetransfer.h"

filetransfer::filetransfer()
{
    printf("等待接收数据...\n");
}

filetransfer::filetransfer(char *input)
{
    printf("欢迎使用\n");
    slice = 1;
    filename = input;
}

filetransfer::filetransfer(char *input, int n)
{
    // if(slice > 32) slice = 32;
}

void filetransfer::inits()
{
    printf("初始化...\n");
    send_addr.sin_family = AF_INET;
    send_addr.sin_port = htons(11451);
    send_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void filetransfer::initr()
{
    printf("初始化...\n");
    recv_addr.sin_family = AF_INET;
    recv_addr.sin_port = htons(11451);
    recv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
}

void filetransfer::send(void)
{
    inits();
    printf("初始化成功\n");

    send_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (send_socket == -1)
    {
        perror("socket init failed");
    }
    printf("套接字创建成功\n");

    yes = 1;
    if (setsockopt(send_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
        perror("setsockopt failed\n");
    }
    printf("端口复用配置成功\n");


    bind(send_socket, (struct sockaddr *)&send_addr, sizeof(send_addr));
    printf("套接字绑定成功\n");


    STD tmp;
    tmp.offset = 0;
    tmp.number = 0;
    memset(tmp.data, 0, sizeof(tmp.data));
    tmp.flag = 3; // 0000 0011
    tmp.offset += strlen(filename);
    strcpy(tmp.data, filename);

    input = fopen(filename, "rb");
    fseek(input, 0, SEEK_END);
    size = ftell(input);
    len = size%1024 ? size/1024 + 1: size/1024;
    fseek(input,0,SEEK_SET);

    strcpy(&tmp.data[tmp.offset + 1], tochar(size));
    for (int i = size; i > 0; i /= 10)
        tmp.offset++;

    tmp.number = slice;

    printf("文件名: %s\t文件大小: %d\t分片数: %d\t线程数: %d\n",filename,size,len,slice);

    listen(send_socket, 20);
    printf("开始监听, 准备传输\n");

    socklen_t client_addr_size = sizeof(recv_addr);
    recv_socket = accept(send_socket, (struct sockaddr *)&recv_addr, &client_addr_size);

    write(recv_socket, (char *)&tmp, sizeof(tmp));

    usleep(100);

    if (slice == 1)
    {
        printf("开始传输\n");
        for (int i = 0; i < len;i++)
        {
            tmp.flag &= 0;
            tmp.flag |= 2;
            tmp.number = i;
            if (i == len - 1)
            {
                tmp.flag |= 8;
                if(size % 1024) tmp.offset = size%1024;
            }
            else
                tmp.offset = 1024;
            memset(tmp.data, 0, sizeof(tmp.data));
            std::cout << "\n"<< i <<  '\t';
            std::cout << fread(&tmp.data, tmp.offset, 1, input) << "\t";
            std::cout << write(recv_socket,(char*)&tmp, sizeof(tmp)) << "\t";
            printf("%.2f%%", ftell(input)*1.0 / size*100);
            if(!(i%10)) usleep(1);
        }
        printf("发送完成\n");
    }
    else
    {
    }
}

void filetransfer::recv()
{
    initr();
    printf("初始化成功\n");

    recv_socket = socket(AF_INET,SOCK_STREAM,0);
    printf("套接字创建成功\n");

    connect(recv_socket,(struct sockaddr*)&recv_addr,sizeof(recv_addr));
    printf("等待连接\n");

    STD tmp;
    memset(tmp.data,0,sizeof(tmp.data));

    tmp.flag = 0;
    while(tmp.flag != 3)
        read(recv_socket,(char*)&tmp,sizeof(tmp));

    filename = new char(strlen(tmp.data));
    
    strcpy(filename,tmp.data);
    size = toint(&tmp.data[strlen(tmp.data)+1]);

    slice = tmp.number;

    len = size%1024 ? size/1024 + 1: size/1024;

    printf("文件名: %s\t文件大小: %d\t分片数: %d\t线程数: %d\n",filename,size,len,slice);

    output = fopen(filename,"wb+");
    
    if (slice == 1)
    {
        while(tmp.flag&2)
        {
            tmp.flag = 0;
            if(tmp.offset < 0) continue;
            memset(tmp.data, 0, sizeof(tmp.data));
            // std::cout << "\r";
            std::cout << read(recv_socket,(char*)&tmp,sizeof(tmp)) << "\t";
            std::cout << fwrite(&tmp.data,tmp.offset,1,output) << "\t";
            printf("%d\t%d\t%d\t",tmp.offset,tmp.flag,tmp.number);
            printf("%.2f%%\n", ftell(output)*1.0 / size*100);
            if(tmp.flag&8 || ftell(output)>size) break;
        }
        printf("接收完成");
        // getchar();
    }
    else
    {
    }
}

void filetransfer::exit()
{
    if(input)
    {
        fclose(input);
        close(recv_socket);
        close(send_socket);
    }
    if(output)
    {
        fclose(output);
        close(recv_socket);
    }
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
        tmp += pow(10,i)*(s[strlen(s)-i-1] - '0');
    }
    return tmp;
}

void filetransfer::scan()
{

}