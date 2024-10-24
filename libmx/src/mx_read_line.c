#include "../inc/libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || buf_size == 0) {
        return -2; 
    }
    
    size_t buffer_size = buf_size;
    char *buffer = (char *)malloc(buf_size);
    buf_size = 1;

    if (!buffer) {
        return -1;
    }

    size_t len = 0; 
    char temp;    
    int bytes_read; 

    while ((bytes_read = read(fd, &temp, buf_size)) > 0) {
        if (temp == delim) {
            break;
        }

        if (len >= buffer_size) {
            buffer_size *= 2; 
            char *new_buffer = mx_realloc(buffer, buffer_size);

            if (!new_buffer) {
                free(buffer);
                return -1;
            }

            buffer = new_buffer; 
        }

        buffer[len++] = temp; 
    }

    if (len == 0 && bytes_read == 0) {
        free(buffer);
        *lineptr = NULL;
        return -1; 
    }
    
    buffer[len] = '\0'; 
    *lineptr = buffer;  

    return len; 
}





