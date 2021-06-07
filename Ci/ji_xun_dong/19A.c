#include "stdio.h"
#include "string.h"

struct date
{
    int day;
    char month[8];
    int year;
};

int main()
{
    int cToTzolkin(struct date *pbaab, struct date *ptzolkin, char *p, char *q);
    int n;
    struct date baab, tzolkin;
    char baabm[19][8] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"},tzolkinm[20][8] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    scanf("%d", &n);
    printf("%d", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d. %s %d", &baab.day, baab.month, &baab.year);
        cToTzolkin(&baab, &tzolkin, baabm[0], tzolkinm[0]);
        printf("%d %s %d", tzolkin.day, tzolkin.month, tzolkin.year);
    }
    return 0;
}

int cToTzolkin(struct date *pbaab, struct date *ptzolkin, char *p, char *q)
{
    int i, days = 0;
    for(i = 0; i < 20; i++) if(strcmp(p+i*8, (*pbaab).month) == 0) break;
    days = (*pbaab).year*365 + i*20 + (*pbaab).day + 1;
    if(days%260==0)
    {
        (*ptzolkin).year = days/260-1;
        (*ptzolkin).day = 13;
        *(*ptzolkin).month = *(q + 19);
    }
    else{
       (*ptzolkin).year = days/260;
        days %= 260;
        (*ptzolkin).day = days%13;
        strcpy((*ptzolkin).month, q+8*(days%20 - 1));
    }
}


