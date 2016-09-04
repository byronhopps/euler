enum monthT {
    JAN = 1, FEB = 2, MAR = 3, APR = 4, MAY = 5, JUN = 6,
    JUL = 7, AUG = 8, SEP = 9, OCT = 10, NOV = 11, DEC = 12,
};

enum weekdayT {
    MON = 0, TUE = 1, WED = 2, THU = 3, FRI = 4, SAT = 5, SUN = 6,
};

int sundayCount();

int isSunday(int day);

int isLeapYear(int year);

int getDaysInMonth(enum monthT month, int year);
