#include "libmx.h"

int compare(const void* a, const void* b) {
    const char* str1 = *(const char**)a;
    const char* str2 = *(const char**)b;

    int len1 = mx_strlen(str1);
    int len2 = mx_strlen(str2);

    if (len1 < len2)
        return -1;
    else if (len1 > len2)
        return 1;
    else
        return mx_strcmp(str1, str2);
}

int mx_quicksort(char** arr, int left, int right) {
    if (!arr)
        return -1;

    qsort(arr + left, right - left + 1, sizeof(char*), compare);

    return 0;
}
