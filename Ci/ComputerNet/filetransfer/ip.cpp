#include <stdio.h>
#include <cmath>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <cstring>
#define ERRORIP "cannot find host ip"

typedef struct StandardDataStruct
{
    char flag; // 1 text 2 file 3 info 4 begin 8 finish 16 offset
    int offset; // offset of present frame(length of data)
    unsigned long int number;
    char data[1024];
    // info : name0size
} STD;

char *ip_search(void)
{
    int sfd, intr;
    struct ifreq buf[16];
    struct ifconf ifc;
    sfd = socket (AF_INET, SOCK_DGRAM, 0); 
    if (sfd < 0)
        return ERRORIP;
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = (caddr_t)buf;
    if (ioctl(sfd, SIOCGIFCONF, (char *)&ifc))
        return ERRORIP;
    intr = ifc.ifc_len / sizeof(struct ifreq);
    while (intr-- > 0 && ioctl(sfd, SIOCGIFADDR, (char *)&buf[intr]));
    // close(sfd);
    return inet_ntoa(((struct sockaddr_in*)(&buf[intr].ifr_addr))-> sin_addr);
}

char* tochar(int a)
{
    int len = 1;
    for(int i = a; i > 0; i/=10) len++;
    char *tmp = new char(len);
    memset(tmp, 0, len);
    for (int i = 0; i < len; i++,a/=10)
    {
        tmp[len-i-2] = '0' + a%10;
    }
    printf("%d\n",len);
    return tmp;
}

int toint(char *s)
{
    int tmp = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        tmp += pow(10,i)*(s[strlen(s)-i-1] - '0');
    }
    return tmp;
}



int main(void)
{
    printf("%s\n", tochar(9999));
    printf("%d\n", toint(tochar(9999)));

    char filename[] = "nimabi";
    char *file;
    int size = 123456;
    int si = 0;
    STD tmp;
    tmp.offset = 0;

    tmp.offset += strlen(filename);
    strcpy(tmp.data, filename);

    strcpy(&tmp.data[tmp.offset + 1], tochar(size));
    for (int i = size; i > 0; i /= 10)
        tmp.offset++;

    printf("%d",tmp.offset);

    for (int i = 0; i <= tmp.offset; i++)
    {
        // printf("%d\t",i);
        printf("%c",tmp.data[i]);
    }
    printf("\n\n\n");

    file = new char(strlen(tmp.data));
    printf("%d\n",strlen(tmp.data));
    printf("%d\n",strlen(&tmp.data[strlen(tmp.data)+1]));
    // for (int i = 0; i < 2; i++)
    // {
    //     if(!tmp.data[i]) file[i] = tmp.data[i];
    //     else 
    //     {
    //         si = toint(&tmp.data[i]);
    //         break;
    //     }
    //     // if(!tmp.data[i]) j++;
    // }
    strcpy(file,tmp.data);
    si = toint(&tmp.data[strlen(tmp.data)+1]);
    printf("name: %s, size: %d\n",file,si);

    char a;
    a |= 1;
    a |= 2;

    printf("%d",a);

    printf("%d",a&8);
    return 0;
}