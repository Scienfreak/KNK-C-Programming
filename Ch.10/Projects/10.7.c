#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITS 10

const int segments[10][7] = {   {1, 1, 1, 1, 1, 1, 0},  //0
                                {0, 1, 1, 0, 0, 0, 0},  //1
                                {1, 1, 0, 1, 1, 0, 1},  //2
                                {1, 1, 1, 1, 0, 0, 1},  //3
                                {0, 1, 1, 0, 0, 1, 1},  //4
                                {1, 0, 1, 1, 0, 1, 1},  //5
                                {1, 0, 1, 1, 1, 1, 1},  //6
                                {1, 1, 1, 0, 0, 0, 0},  //7
                                {1, 1, 1, 1, 1, 1, 1},  //8
                                {1, 1, 1, 1, 0, 1, 1}}; //9

char digits[4][MAX_DIGITS * 4];

const int segment_grid[7][2] = {{0, 1},
                                {1, 2},
                                {2, 2},
                                {2, 1},
                                {2, 0},
                                {1, 0},
                                {1, 1}};

void clear_digits_array(void);
void process_digit (int digit, int position);
void print_digits_array(void);

int main(void) {
    int position = 0;
    char ch;

    clear_digits_array();

    printf("Enter a number: ");

    while (position < MAX_DIGITS * 4 && (ch = getchar()) != '\n') {
        if ('0' <= ch && ch <= '9') {
            process_digit(ch - '0', position);
            position += 4;
        }
        else
            ;
    }

    print_digits_array();

    return 0;
}

/*******************************************************
 * clear_digits_array: store blank characters into all *
 *                     elements of the digitis array.  *
 *******************************************************/
void clear_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
    }
}

/******************************************************************
 * process_digit: store the seven-segment representation of digit *
 *                into a secified position in the digits array.   *
 ******************************************************************/
void process_digit (int digit, int position) {
    int row, col;

    for (int i = 0; i < 7; i++) {
        if (segments[digit][i]) {
            row = segment_grid[i][0];
            col = segment_grid[i][1] + position;
            digits[row][col] = (i % 3 == 0) ? '_' : '|';
        }
    }
}

/***************************************************************
 * print_digits_array: display the rows of the digits array,   *
 *                     each on a single line, producing output *
 ***************************************************************/
void print_digits_array(void) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }
}