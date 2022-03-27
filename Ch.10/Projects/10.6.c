#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

/* external variables */
int stack[STACK_SIZE];
int top = 0;

/* function declarations */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
void calculator(void);

/***************************************************************
 * main: Call the calculator function and do RPN operation.    *
 ***************************************************************/
int main(void) {
    for(;;) {
        calculator();
    }
}

/*****************************
 * Stack function collection *
 *****************************/

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;    
}

bool is_full(void){
    return top == STACK_SIZE;    
}

void push(int i) {
    if(is_full())
        stack_overflow();
    else
        stack[top++] = i;
}

int pop(void) {
    if(is_empty())
        stack_underflow();
    else
        return stack[--top];
}

void stack_overflow(void) {
    printf("\nExpression is too complex\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void) {
    printf("\nNot enough operations in expression\n");
    exit(EXIT_FAILURE);
}

/***************************************************************
 * calculator: read user input of single-digit integers        *
 *                  and operand +, - *, /, =; The = operator   *
 *                  causes the top stack item to be displayed. *
 ***************************************************************/
void calculator(void) {
    char ch;

    printf("Enter an RPN expression: ");

    for (;;) {
        scanf(" %c", &ch);
        if ('0' <= ch && ch <= '9')
            push(ch - '0');
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand2 = pop();
            int operand1 = pop();

            switch (ch) {
                case '+':   push(operand1 + operand2); break;
                case '-':   push(operand1 - operand2); break;
                case '*':   push(operand1 * operand2); break;
                case '/':   if (operand2 != 0) push(operand1 / operand2);
                            else {  /* division zero error */
                                printf("\nDivision by zero error!\n");
                                exit(EXIT_FAILURE);
                            } break;
                default:    break;
            }
        }
        else if (ch == '=') {
            printf("Value of expression: %d\n", stack[0]);
            make_empty();
            break;
        }
        else
            exit(EXIT_FAILURE);
    }
}