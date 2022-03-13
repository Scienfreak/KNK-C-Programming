#include <stdio.h>
#include <ctype.h>

int main(void) {
    int word, total_length;
    char c;

    word = 1;
    total_length = 0;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n') {
        if (c == ' ')
            word++;
        else
            total_length++;
    }

    printf("Average word length: %.1f\n", (float) total_length / word);

    return 0;
}
