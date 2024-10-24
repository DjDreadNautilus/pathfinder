#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }

    int count_words = mx_count_words(s, c);
    char **split = (char**)malloc(sizeof(char*) * (count_words + 1));

    if (!split) {
        return NULL;
    }

    split[count_words] = NULL;

    for (int i = 0, j = 0; i < count_words; i++) {
        while (s[j] == c) {
            j++;
        }

        int start = j;

        while (s[j] != c && s[j] != '\0') {
            j++;
        }

        int word_len = j - start;
        split[i] = mx_strnew(word_len);

        if (!split[i]) {
            for (int k = 0; k < i; k++) {
                mx_strdel(&split[k]);
            }

            free(split);
            
            return NULL;
        }
        
        mx_strncpy(split[i], s + start, word_len);
    }

    return split;
}




