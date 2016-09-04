#include <stdlib.h>
#include "p19.h"

int sundayCount()
{

    int curYear = 1900;
    int curDay = 2;
    int numSundays = 0;
    enum monthT curMonth;

    for (curYear = 1901; curYear <= 2000; curYear++) {
        for (curMonth = JAN; curMonth <= DEC; curMonth++) {

            if (isSunday(curDay))
                numSundays++;

            curDay += getDaysInMonth(curMonth, curYear);
        }
    }

    return numSundays;
}

int isSunday(int day)
{
    // Day 0 is a Sunday
    return (day % 7 == 0) ? 1 : 0;
}

int isLeapYear(int year)
{
    if (year % 400 == 0) {
        return 1;

    } else if (year % 100 == 0) {
        return 0;

    } else if (year % 4 == 0) {
        return 1;

    } else {
        return 0;
    }
}

int getDaysInMonth(enum monthT month, int year)
{
    switch(month) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            return 31;
            break;

        case APR:
        case JUN:
        case SEP:
        case NOV:
            return 30;
            break;

        case FEB:
            return isLeapYear(year) ? 29 : 28;
    }

    exit(-1);
    return 0;
}
