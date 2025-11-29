#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


char opStack[MAX];
int opTop = -1;

void pushOp(char c) { opStack[++opTop] = c; }
char popOp() { return opStack[opTop--]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}


void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;
    opTop = -1; 

    for (int i = 0; infix[i] != '\0'; i++) {
        char sym = infix[i];

        if (isalnum(sym)) {
            postfix[j++] = sym;
        }
        else if (sym == '(') {
            pushOp(sym);
        }
        else if (sym == ')') {
            while (opTop != -1 && opStack[opTop] != '(') {
                postfix[j++] = popOp();
            }
            popOp(); // remove '('
        }
        else { 
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(sym)) {
                postfix[j++] = popOp();
            }
            pushOp(sym);
        }
    }

    while (opTop != -1) {
        postfix[j++] = popOp();
    }

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}


char strStack[MAX][MAX];
int strTop = -1;

void pushString(char* s) { strcpy(strStack[++strTop], s); }
char* popString() { return strStack[strTop--]; }


void postfixToInfix(char postfix[]) {
    strTop = -1;  // reset string stack

    for (int i = 0; postfix[i] != '\0'; i++) {
        char sym = postfix[i];

        if (isalnum(sym)) {
            char temp[2] = {sym, '\0'};
            pushString(temp);
        }
        else { 
            char right[MAX], left[MAX], expr[MAX];

            strcpy(right, popString());
            strcpy(left, popString());

            sprintf(expr, "(%s%c%s)", left, sym, right);

            pushString(expr);
        }
    }

    printf("Infix: %s\n", popString());
}


int main() {
    int choice;
    char expression[MAX];

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Infix → Postfix\n");
        printf("2. Postfix → Infix\n");
        printf("3. Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting...\n");
            break;
        }

        printf("Enter expression: ");
        scanf("%s", expression);

        switch (choice) {
            case 1:
                infixToPostfix(expression);
                break;

            case 2:
                postfixToInfix(expression);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
