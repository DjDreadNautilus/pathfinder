#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if(size == 0) {
        free(ptr);

        return NULL;
    }

    void* memblock = NULL;

    if(!ptr) {
        memblock = malloc(size);
        if (!memblock) {

            return NULL;
        }
        
    }
    else {
        if(malloc_usable_size(ptr) < size) {
            memblock = malloc(size);

            if (!memblock) {
                return NULL;
            }   

            mx_memcpy(memblock, ptr, malloc_usable_size(ptr));
            free(ptr);
        }
        else {
            memblock = ptr;
        }
    }

    return memblock;
}





