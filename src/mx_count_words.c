#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return 0;
    }

    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            inWord = false;
        } else {
            if (!inWord) {
                count++;
                inWord = true;
            }
        }
    }

    return count;
}
