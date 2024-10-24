#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file) {
    	return NULL;
    }

    int fd = open(file, O_RDONLY);

    if (fd < 0) {
    	return NULL;
    }
    
    int len = 0;
    char temp;

	while (read(fd, &temp, 1) > 0) {
		len++;
	}

    if (close(fd) < 0) {
        return NULL;
    }

    int fd2 = open(file, O_RDONLY);

    if (fd2 < 0) {
        return NULL;
    }

    char *str = mx_strnew(len);

    for(int i = 0; i < len; i++) {
        read(fd2, &temp, 1);
        str[i] = temp;
    }

    if (close(fd2) < 0) {
        return NULL;
    }

    return str;
}




