#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    if (!arr || size <= 0 || !s || !count) {
        return -1; 
    }

    int start = 0;
    int end = size - 1;
    *count = 0;

    while (start <= end) {
        (*count)++;
        int mid = (start + end) / 2;

        if (mx_strcmp(arr[mid], s) == 0) {
            return mid;
        }
        else if (mx_strcmp(arr[mid], s) < 0) { 
            start = mid + 1;         
        }
        else {
            end = mid - 1;
        }
    }
 
    *count = 0;
    
    return -1;
}




