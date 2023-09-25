#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL) {
        return NULL;
    }

    size_t length = mx_strlen(s1);

    if (n >= length) {
        n = length;
    }

    char *duplicate = (char *)malloc(n + 1);
    if (duplicate == NULL) {
        return NULL;
    }

    mx_strncpy(duplicate, s1, n);
    duplicate[n] = '\0';

    return duplicate;
}
