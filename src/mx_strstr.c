#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    size_t haystack_len = mx_strlen(haystack);
    size_t needle_len = mx_strlen(needle);

    if (needle_len == 0) {
        return (char *)haystack;
    }

    for (size_t i = 0; i <= haystack_len - needle_len; i++) {
        if (mx_strncmp(haystack + i, needle, needle_len) == 0) {
            return (char *)(haystack + i);
        }
    }

    return NULL;
}
