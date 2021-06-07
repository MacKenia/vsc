#include <stdio.h>

int main()
{
    int x, y, z;
    for (x = 0; x <= 20; x++)
    {
        for (y = 0; y <= 33; y++)
        {
            z = 100 - x - y;
            if (5 * x + 3 * y + (float)z / 3 == 100)
            {
                printf("x=%d, y=%d, z=%d\n", x, y, z);
            }
        }
    }
    return 0;
}
