#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop();
bool is_match(char);

int main(void) {
    char ch;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case '(': case '{':
                push(ch);
                break;
            case ')': case '}':
                if (!is_match(ch)) {
                    /* not match */
                    printf("Not match\n");
                    return 0;
                }
                break;
            default:
                /* not match */
                printf("Not match\n");
                return 0;
        }
    }

    if (!is_empty()) {
        printf("Not match\n");
        return 0;
    }

    printf("Parentheses/braces are nested properly\n");
    return 0;
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void stack_overflow(void) {
    printf("\nStack overflow\n");
    exit(EXIT_SUCCESS) ;
}

void stack_underflow(void) {
    printf("\nStack underflow\n");
    exit(EXIT_SUCCESS) ;
}

void push(char ch) {
    if (is_full())
        stack_overflow();
    else
        stack[top++] = ch;
}

char pop() {
    if (is_empty())
        stack_underflow();
    else
        return stack[--top];
}

bool is_match(char ch) {
    switch (ch) {
        case ')':   return (pop() == '(') ? true : false;
        case '}':   return (pop() == '{') ? true : false;
        default:    return false;
    }
}