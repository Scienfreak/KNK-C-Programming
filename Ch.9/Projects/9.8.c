#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);


int main(void) {
    int win, lose;

    win = 0;
    lose = 0;

    srand((unsigned) time(NULL));

    for (;;) {
        /* play game */
        if (play_game()) {
            printf("You win!\n");
            win++;
        }
        else {
            printf("You lose!\n");
            lose++;
        }

        /* ask again */
        printf("\nPlay again? ");
        char c = getchar();
        getchar();

        if (toupper(c) == 'Y')
            printf("\n");
        else {
            printf("\nWins: %d  Loses: %d\n", win, lose);
            return 0;
        }
    }
}

int roll_dice(void) {
    int dice1, dice2, sum;

    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;

    return dice1 + dice2;
}

bool play_game(void) {
    int sum, point;

    /* first roll */
    sum = roll_dice();
    printf("You rolled: %d\n", sum);

    /* win: 7, 11 */
    if (sum == 7 || sum == 11)
        return true;
    /* lose: 2, 3, 12 */
    else if (sum == 2 || sum == 3 || sum == 12) 
        return false;
    /* point: 4, 5, 6, 8, 9, 10 */
    /* if point: roll again */
    else {
        point = sum;
        printf("Your point is %d\n", point);
        for (;;) {
            sum = roll_dice();
            printf("You rolled: %d\n", sum);
            /* win: point */
            if (sum == point)
                return true;
            /* lose: 7 */
            else if (sum == 7)
                return false;
            /* ignore: roll again */
            else
                ;
        }
    }  
  
}