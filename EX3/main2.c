#include <stdio.h>

int main() {
    int i = 8;
    if (i>0 && (i & (i-1)) ==0) {
        printf("true");
    }
    else {
        printf("false");
    
    }

    return 0;
}
