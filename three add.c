#include <stdio.h>
#include <ctype.h>
#include <string.h>

char expr[100];
int tempCount = 1;

// Operator stack
char opStack[100];
int opTop = -1;

// Operand stack (strings)
char valStack[100][20];
int valTop = -1;

int precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void generate(char op) {
    char right[20], left[20], res[20];

    strcpy(right, valStack[valTop--]);
    strcpy(left, valStack[valTop--]);

    sprintf(res, "t%d", tempCount++);
    printf("%s = %s %c %s\n", res, left, op, right);

    strcpy(valStack[++valTop], res);
}

int main() {
    printf("Enter expression: ");
    scanf("%s", expr);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        if (isalnum(ch)) {
            char temp[20];
            sprintf(temp, "%c", ch);
            strcpy(valStack[++valTop], temp);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (opTop != -1 &&
                   precedence(opStack[opTop]) >= precedence(ch)) {
                generate(opStack[opTop--]);
            }
            opStack[++opTop] = ch;
        }
    }

    while (opTop != -1) {
        generate(opStack[opTop--]);
    }

    printf("\nFinal result stored in: %s\n", valStack[valTop]);
    return 0;
}
