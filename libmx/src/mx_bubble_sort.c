#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int swap_count = 0;
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            if (!arr[j] || !arr[j + 1]) {
                return -1;
            }

            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap_count++;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    return swap_count;
}




