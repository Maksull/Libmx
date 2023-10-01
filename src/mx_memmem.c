#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (big_len < little_len) {
        return NULL;
    }

    if (little_len == 0) {
        return (void *)big;
    }

    const char *big_ptr = (const char *)big;
    const char *little_ptr = (const char *)little;
    const char *end = big_ptr + (big_len - little_len + 1);

    while (big_ptr < end) {
        if (*big_ptr == *little_ptr && mx_memcmp(big_ptr, little_ptr, little_len) == 0) {
            return (void *)big_ptr;
        }
        big_ptr++;
    }

    return NULL;
}
