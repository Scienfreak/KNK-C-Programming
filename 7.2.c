#include <stdio.h>

int main(void) {
    typedef int side;
    side i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter umber of entries in table: ");
    scanf("%d", &n);
    getchar(); // ungets '\n' from buffer

    for (i = 1; i <= n; i++) {
        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n')
                ;
        }
    }

    return 0;
}
