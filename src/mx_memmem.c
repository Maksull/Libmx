#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *dst_ptr = dst;
    const unsigned char *src_ptr = src;

    if (dst_ptr <= src_ptr || dst_ptr >= (src_ptr + len)) {
        for (size_t i = 0; i < len; i++) {
            dst_ptr[i] = src_ptr[i];
        }
    } else {
        for (size_t i = len; i > 0; i--) {
            dst_ptr[i - 1] = src_ptr[i - 1];
        }
    }

    return dst;
}
