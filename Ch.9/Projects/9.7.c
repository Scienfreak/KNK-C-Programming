#include <stdio.h>

int polynimial(int x);
int power(int x, int n); /* return x^n */

int main(void) {
    int x;

    printf("Enter the number: ");
    scanf("%d", &x);

    printf("Result: %d\n", polynimial(x));

    return 0;
}

int polynimial(int x) {
    int result = 0;

    result += 3 * power(x, 5);
    result += 2 * power(x, 4);
    result -= 5 * power(x, 3);
    result -= 1 * power(x, 2);
    result += 7 * power(x, 1);
    result -= 6;

    return result;
}

int power(int x, int n) {
    if (n == 0)
        return 1;
    
    if (n % 2 == 0) {
        int root = power(x, n / 2);
        return root * root;
    } else {
        return x * power(x, n - 1);
    }
}