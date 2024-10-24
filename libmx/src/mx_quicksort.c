#include "../inc/libmx.h"

void swap(char**a, char**b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char **arr, int left, int right, int* swap_count) {
    int mid = left + (right - left) / 2;
    int pivot_length = mx_strlen(arr[mid]);

    while (left <= right) {
        while (mx_strlen(arr[left]) < pivot_length) {
            left++;
        }

        while (mx_strlen(arr[right]) > pivot_length) {
            right--;
        }

        if (left <= right) {
            if (left < right && mx_strlen(arr[left]) != mx_strlen(arr[right])) {
                swap(&arr[left], &arr[right]);
                (*swap_count)++;
            }

            left++;
            right--;
        }
    }
    
    return left;
}

int mx_quicksort(char **arr, int left, int right) {
    if(!arr || !*arr) {
        return -1;
    }

    int swap_count = 0;

    if (left < right) {
        int pivot = partition(arr, left, right, &swap_count);
        swap_count += mx_quicksort(arr, left, pivot - 1);
        swap_count += mx_quicksort(arr, pivot, right);
    }

    return swap_count;
}




