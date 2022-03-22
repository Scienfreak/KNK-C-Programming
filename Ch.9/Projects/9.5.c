#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]);
void print_magic_square(int n, int magic_square[n][n]);

int main(void) {
    int n;

    printf("Enter the number: ");
    scanf("%d", &n); /* 0 < n < 100 */
    int magic_square[n][n];
    create_magic_square(n, magic_square); 

    print_magic_square(n, magic_square);
    
    return 0;
}

void create_magic_square(int n, int magic_square[n][n]) {
    int x = 0, y = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    int i = 1;
    while (i <= n * n) {
        
        if (magic_square[x][y] != 0) {
            if (x == n - 1)
                x = 0;
            else
                x++;
        } magic_square[x][y] = i++;

        /* move x */
        if (x > 0)
            x--;
        else
            x = n - 1;
        /* move y */
        if (y + 1 < n)
            y++;
        else
            y = 0;
    } return ;
}

void print_magic_square(int n, int magic_square[n][n]) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", magic_square[i][j]);
        }
        printf("\n");
    } return ;
}
