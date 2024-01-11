#include "polishNotation.h"

#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkingOperator(char symbol){
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%');
}

int checkingFunction(char symbol){
    return (symbol == 's' || symbol == 'S' || symbol == 'c' || symbol == 'C' || symbol == 't' || symbol == 'T' || symbol == 'q' || symbol == 'l' || symbol == 'L');
}

int getPriority(char symbol){
    int priority = 0;

    if(symbol == '+' || symbol == '-' || symbol == '~' || symbol == '#'){
        priority = 1;
    } else if(symbol == '*' || symbol == '/' || symbol == '%'){
        priority = 2;
    } else if(symbol == '^'){
        priority = 3;
    } else if(symbol == 's' || symbol == 'S' || symbol == 'c' || symbol == 'C' || symbol == 't' || symbol == 'T' || symbol == 'q' || symbol == 'l' || symbol == 'L'){
        priority = 4;
    }

    return priority;
}

int infixToPostfix(const char *expression, char *postfix_expression) {
    int error = 0;
    int i = 0;
    int j = 0;
    Stack stack;
    createStack(&stack);
    
    int binary_allowed = 0;
    int unary_allowed = 1;
    int bracket_required = 0;

    while (expression[i] != '\0' && !error) {
        if (((isdigit(expression[i]) &&
              (i == (int)strlen(expression) - 1 || isdigit(expression[i + 1]) ||
               expression[i + 1] == '.')) ||
             (expression[i] == '.' && i > 0 && isdigit(expression[i - 1]))) &&
            !bracket_required) {
            postfix_expression[j++] = expression[i];

            binary_allowed = 0;
            unary_allowed = 0;
        }

        else if ((isdigit(expression[i]) || expression[i] == 'x') &&
                 !bracket_required) {
            postfix_expression[j++] = expression[i];
            postfix_expression[j++] = ' ';

            binary_allowed = 1;
            unary_allowed = 0;
        }

        else if (isalpha(expression[i]) && !bracket_required) {
            char function[100] = {'\0'};
            int k = 0;  // index for function

            while (isalpha(expression[i])) {
                function[k++] = expression[i++];
            }
            i--;

            if (strcmp(function, "sin") == 0) {
                pushChar(&stack, 's');
            } else if (strcmp(function, "cos") == 0) {
                pushChar(&stack, 'c');
            } else if (strcmp(function, "tan") == 0) {
                pushChar(&stack, 't');
            } else if (strcmp(function, "asin") == 0) {
                pushChar(&stack, 'S');
            } else if (strcmp(function, "acos") == 0) {
                pushChar(&stack, 'C');
            } else if (strcmp(function, "atan") == 0) {
                pushChar(&stack, 'T');
            } else if (strcmp(function, "sqrt") == 0) {
                pushChar(&stack, 'q');
            } else if (strcmp(function, "ln") == 0) {
                pushChar(&stack, 'l');
            } else if (strcmp(function, "log") == 0) {
                pushChar(&stack, 'L');
            } else {
                error = 1;  // unknown function
            }

            binary_allowed = 0;
            unary_allowed = 0;
            bracket_required = 1;
        }

        else if (expression[i] == '(') {
            pushChar(&stack, '(');

            binary_allowed = 0;
            unary_allowed = 1;

            if (bracket_required == 1) {
                bracket_required = 0;
            }
        }

        else if (expression[i] == ')' && !bracket_required) {
            char lexem = popChar(&stack);
            while (lexem != '(' && !error) {
                if (lexem == 0) {
                    error = 1;  // stack is empty before we get "("
                    continue;
                }
                postfix_expression[j++] = lexem;
                postfix_expression[j++] = ' ';
                lexem = popChar(&stack);
            }
            if (error) {
                continue;  // SYNTAX ERROR
            }
            if (checkingFunction(stack.data[stack.top])) {
                lexem = popChar(&stack);
                postfix_expression[j++] = lexem;
                postfix_expression[j++] = ' ';
            }

            unary_allowed = 0;
            binary_allowed = 1;
        }

        else if (checkingOperator(expression[i]) && !bracket_required &&
                 (binary_allowed || unary_allowed)) {
            while (
                    (checkingFunction(stack.data[stack.top]) ||
                     checkingOperator(stack.data[stack.top]) || stack.data[stack.top] == '(' ||
                     stack.data[stack.top] == '~' || stack.data[stack.top] == '#') &&
                    (getPriority(stack.data[stack.top]) > getPriority(expression[i]) ||
                     (getPriority(stack.data[stack.top]) ==
                      getPriority(expression[i]) &&
                      !(unary_allowed &&
                        (expression[i] == '-' || expression[i] == '+')) && expression[i] != '^'))) {
                char lexem = popChar(&stack);
                postfix_expression[j++] = lexem;
                postfix_expression[j++] = ' ';
            }

            if (unary_allowed && expression[i] == '-') {
                pushChar(&stack, '~');
            } else if (unary_allowed && expression[i] == '+') {
                pushChar(&stack, '#');
            } else {
                pushChar(&stack, expression[i]);
            }

            if (unary_allowed) {
                unary_allowed = 0;
            } else {
                unary_allowed = 1;
            }
            binary_allowed = 0;
        }

        i++;
    }

    char lexem = popChar(&stack);
    while (lexem != 0 && !error) {
        if (lexem == '(') {
            error = 1;
            continue;
        }
        postfix_expression[j++] = lexem;
        postfix_expression[j++] = ' ';
        lexem = popChar(&stack);
    }
    if (error) {
        postfix_expression[0] = '\0';
    } else {
        postfix_expression[j++] = '\0';
    }

    return error;
}

int processPostfix(char *expression, double x, double *result){
    Stack stack;
    createStack(&stack);

    int ii = 0;
    int error = 0;

    while (expression[ii] != '\0' && !error) {
        if (isdigit(expression[ii])) {

            char number[255] = {'\0'};
            int kk = 0;

            while(isdigit(expression[ii]) || expression[ii] == '.'){
                number[kk++] = expression[ii++];
            }
            pushDouble(&stack, atof(number));
            ii--;

        } else if(expression[ii] == 'x' && !isnan(x)){
            pushDouble(&stack, x);
        } else if(checkingOperator(expression[ii])){
            double secondNumber;

            if(isEmpty(&stack)){
                error = 1;
            } else {
                switch (expression[ii]) {
                    case '+':
                        secondNumber = popDouble(&stack);
                        if (!isEmpty(&stack)) {
                            pushDouble(&stack, (popDouble(&stack) + secondNumber));
                        } else {
                            error = 1;
                        }
                        break;
                    case '-':
                        secondNumber = popDouble(&stack);
                        if (!isEmpty(&stack)) {
                            pushDouble(&stack, (popDouble(&stack) - secondNumber));
                        } else {
                            error = 1;
                        }
                        break;
                    case '*':
                        secondNumber = popDouble(&stack);
                        if (!isEmpty(&stack)) {
                            pushDouble(&stack, (popDouble(&stack) * secondNumber));
                        } else {
                            error = 1;
                        }
                        break;
                    case '/':
                        secondNumber = popDouble(&stack);
                        double epsilon = 0.0000001;

                        if (!isEmpty(&stack) && !(fabs(secondNumber) < epsilon)) {
                            pushDouble(&stack, (popDouble(&stack) / secondNumber));
                        } else {
                            error = 1;
                        }
                        break;
                    case '^':
                        secondNumber = popDouble(&stack);
                        if (!isEmpty(&stack)) {
                            pushDouble(&stack, pow(popDouble(&stack), secondNumber));
                        } else {
                            error = 1;
                        }
                        break;
                    case '%':
                        secondNumber = popDouble(&stack);
                        if (!isEmpty(&stack)) {
                            pushDouble(&stack, fmod(popDouble(&stack), secondNumber));
                        } else {
                            error = 1;
                        }
                        break;
                }
            }

        } else if(checkingFunction(expression[ii])){
            if(isEmpty(&stack)){
                error = 1;
            } else{
                switch (expression[ii]) {
                    case 's':
                        pushDouble(&stack, sin(popDouble(&stack)));
                        break;
                    case 'c':
                        pushDouble(&stack, cos(popDouble(&stack)));
                        break;
                    case 't':
                        pushDouble(&stack, tan(popDouble(&stack)));
                        break;
                    case 'S':
                        pushDouble(&stack, asin(popDouble(&stack)));
                        break;
                    case 'C':
                        pushDouble(&stack, acos(popDouble(&stack)));
                        break;
                    case 'T':
                        pushDouble(&stack, atan(popDouble(&stack)));
                        break;
                    case 'q':
                        pushDouble(&stack, sqrt(popDouble(&stack)));
                        break;
                    case 'l':
                        pushDouble(&stack, log(popDouble(&stack)));
                        break;
                    case 'L':
                        pushDouble(&stack, log10(popDouble(&stack)));
                    default:
                        break;
                }
            }
        } else if(expression[ii] == '~'){
            if(!isEmpty(&stack)){
                pushDouble(&stack, 0 - popDouble(&stack));
            } else {
                error = 1;
            }
        } else if(expression[ii] == '#'){
            if(!isEmpty(&stack)){
                pushDouble(&stack, popDouble(&stack));
            } else {
                error = 1;
            }
        }

        ii++;

    }

    if (!error) {
        *result = popDouble(&stack);
    }

    if (!isEmpty(&stack)) {
        error = 1;
        *result = 0;
    }

    return error;
}
