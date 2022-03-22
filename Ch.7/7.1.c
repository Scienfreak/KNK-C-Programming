#include <stdio.h>

int main(void) {
    typedef long side;
    side i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter umber of entries in table: ");
    scanf("%ld", &n);

    for (i = 1; i <= n; i++) {
        if ((i * i) < 0 ) break;
    }
    printf("%20ld%20ld\n", i, i * i);

    return 0;
}

// int breaks at 46341
// short breaks at 182
// long breaks at 3037000500
