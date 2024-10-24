int mx_sqrt(int x) {
    int start = 1; 
    int end = x;
    int res = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if(mid * mid == x) {
            res = mid;
            break;
        }
        else if(mid * mid < x) {
            start = mid + 1;
            res = mid;
        }
        else {
            end = mid - 1;
        }

    }

    if (res * res == x) {
        return res;
    } 
    else {
        return 0;
    }

    return res;
}





