#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    int str_len = mx_strlen(str);
    int start = 0;
    int end = str_len - 1;

    while (str[start] != '\0' && mx_isspace((unsigned char)str[start])) {
        start++;
    }

    while (end >= 0 && mx_isspace((unsigned char)str[end])) {
        end--;
    }

    if (start > end) {
        return mx_strdup("");
    }

    int trimmed_len = end - start + 1;

    char *trimmed_str = (char *)malloc(trimmed_len + 1);
    if (trimmed_str == NULL) {
        return NULL;
    }

    mx_strncpy(trimmed_str, str + start, trimmed_len);
    trimmed_str[trimmed_len] = '\0';

    return trimmed_str;
}
