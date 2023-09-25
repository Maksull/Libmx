#include "libmx.h"

char *mx_itoa(int number) {
    if (number == 0) {
        char *str = (char *)malloc(2);
        if (str == NULL) {
            return NULL;
        }
        str[0] = '0';
        str[1] = '\0';
        return str;
    }

    int tmp = number;
    bool isNegative = false;
    int count = 0;

    if (number < 0) {
        isNegative = true;
        tmp = -tmp;
        count++;
    }

    int tmp2 = tmp;
    while (tmp) {
        tmp /= 10;
        count++;
    }

    char *str = (char *)malloc(count + 1);
    if (str == NULL) {
        return NULL;
    }

    str[count] = '\0';

    while (count--) {
        str[count] = (tmp2 % 10) + '0';
        tmp2 /= 10;
    }

    if (isNegative) {
        str[0] = '-';
    }

    return str;
}
