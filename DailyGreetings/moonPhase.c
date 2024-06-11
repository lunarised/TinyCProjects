#include <string.h>
#include <stdio.h>
void getMoonPhase(char *phaseString, int year, int month, int day)
{
    int d, g, e, p;
    d = day;
    if (month == 2)
    {
        day += 31;
    }
    else if (month > 2)
    {
        d += 59 + (month - 3) * 30.6 + 0.5;
    }
    g = (year - 1900) % 19;
    e = (11 * g + 29) % 30;
    if (e == 25 || e == 24)
    {
        ++e;
    }
    p = ((((e + d) * 6 + 5) % 177) / 22 & 7);

    char *phase[8] = {
        "waxing cresent",
        "at first quarter",
        "waxing gibbous",
        "full",
        "waning gibbous",
        "at last quarter",
        "waning cresent",
        "new"};
    strcpy(phaseString, phase[p]);
}