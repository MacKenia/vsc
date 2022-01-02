#include <stdio.h>
#include <bits/stdc++.h>

int main()
{
    FILE *input, *output;
    char data[1024];
    int offset;
    int slice;
    input = fopen("input.txt","rb");
    output = fopen("output.txt","wb+");
    fseek(input, 0, SEEK_END);
    unsigned long int size = ftell(input);
    fseek(input, 0, SEEK_SET);
    printf("%d\n",size);
    for (int i = size; i > 0;)
    {
        if(i < 1024)
            offset = i;
        else
            offset = 1024;
        memset(data, 0, sizeof(data));
        std::cout << "\r";
        std::cout << fread(&data,offset,1,input) << "\t";
        std::cout << fwrite(&data,offset,1,output) << "\t";
        i -= offset;
        printf("%.2f",(size-i*1.0)*100/size);
    }
    fclose(input);
    fclose(output);
    return 0;
}
