#include <stdio.h>

int print_polynimial(int x);

int main(void) {
    int x;

    printf("Enter the number: ");
    scanf("%d", &x);

    printf("Result: %d\n", print_polynimial(x));

    return 0;
}

int print_polynimial(int x) {
    int result = 0;

    result += 3 * x * x * x * x * x;
    result += 2 * x * x * x * x;
    result -= 5 * x * x * x;
    result -= 1 * x * x;
    result += 7 * x;
    result -= 6;

    return result;
}
