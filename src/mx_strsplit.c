#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int len = mx_strlen(s);
    int word_count = 0;
    int start = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == c || s[i] == '\0') {
            if (i > start) {
                word_count++;
            }
            start = i + 1;
        }
    }

    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    int result_index = 0;
    start = 0;

    for (int i = 0; i <= len; i++) {
        if (s[i] == c || s[i] == '\0') {
            if (i > start) {
                int word_len = i - start;

                result[result_index] = (char *)malloc((word_len + 1) * sizeof(char));
                if (result[result_index] == NULL) {
                    for (int j = 0; j < result_index; j++) {
                        free(result[j]);
                    }
                    free(result);
                    return NULL;
                }

                mx_strncpy(result[result_index], s + start, word_len);
                result[result_index][word_len] = '\0';
                result_index++;
            }
            start = i + 1;
        }
    }

    result[word_count] = NULL;

    return result;
}
