#include "sc.h"
#include "control.h"

using namespace std;

keyboard::keyboard()
{
    ch = getch();
}


if(ch==0x48)
        {
            if(coord.Y!=0)coord.Y--;
        }
 
        //下
        else if(ch==0x50)
        {
            coord.Y++;
        }
 
        //左
        else if(ch==0x4b)
        {
            if(coord.X!=0){coord.X--;}
        }
 
        //右
        else if(ch==0x4d)
        {
            if(coord.X!=79)coord.X++;
            else
            {
                coord.X=0;
                coord.Y++;
            }
        }