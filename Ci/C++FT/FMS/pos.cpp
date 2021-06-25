#include "pos.h"

using namespace std;

pos::pos()
{
    while(true)
    {
        GetCursorPos(&pt);
        ScreenToClient(hwnd,&pt);
        pt.y=pt.y/16,pt.x=pt.x/8;
        cout << "\r(" << pt.x << "," << pt.y << ")";
    }
}

