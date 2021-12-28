
#ifndef FILETRANSFER
#define FILETRANSGER

typedef struct StandardDataStruct
{
    unsigned long int number;
    char data[512];
} STD;

class filetransfer
{
private:
     
    char *start;
    int slice;
    unsigned long int num;
    unsigned long int max;
    
public:
    filetransfer(char *s, int sli)
    {
        start = s;
        num = 0;
        if(sli>32)
            slice = 32;
        
    }

    char *data()
    {

    }

};


#endif