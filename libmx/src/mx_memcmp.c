#include "../inc/libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *cmp1 = (const unsigned char *)s1;
    const unsigned char *cmp2 = (const unsigned char *)s2;

    for(size_t i = 0; i < n; i++) {
        if(cmp1[i] != cmp2[i]) {    
            return cmp1[i] - cmp2[i];
        }
    }

    return 0;

}




