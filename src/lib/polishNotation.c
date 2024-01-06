#include "polishNotation.h"

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

int infixToPostfix(const char *expression, char *postfixExpression){
    int error = 0;
    int ii = 0;
    int jj = 0;

    Stack stack;

    int binary_allowed = 0;
    int unary_allowed = 1;
    int bracket_required = 0;

    while(expression[ii] != '\0' && !error){
        if (((isdigit(expression[ii]) && (ii == (int)strlen(expression) - 1 || isdigit(expression[ii + 1]) ||
        expression[ii + 1] == '.')) || (expression[ii] == '.' && ii > 0 && isdigit(expression[ii - 1]))) && !bracket_required) {

            postfixExpression[jj++] = expression[ii];
            binary_allowed = 0;
            unary_allowed = 0;

        } else if((isdigit(expression[ii]) || expression[ii] == 'x') && !bracket_required){

            postfixExpression[jj++] = expression[ii];
            postfixExpression[jj++] = ' ';
            binary_allowed = 0;
            unary_allowed = 0;

        } else if(isalpha(expression[ii]) && !bracket_required){
            char function[100] = {'\0'};
            int kk = 0;

            while(isalpha(expression[ii])){
                function[kk++] = expression[ii++];
            }
            ii--;

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
                error = 1;
            }

            binary_allowed = 0;
            unary_allowed = 0;
            bracket_required = 1;

        } else if(expression[ii] == '('){

            pushChar(&stack, '(');

            binary_allowed = 0;
            unary_allowed = 1;

            if (bracket_required == 1) {
                bracket_required = 0;
            }

        } else if(expression[ii] == ')' && !bracket_required){

            char lexem = popChar(&stack);

            while (lexem != '(' && !error) {

                if (lexem == 0) {
                    error = 1;
                    continue;
                }

                postfixExpression[jj++] = lexem;
                postfixExpression[jj++] = ' ';
                lexem = popChar(&stack);

            }

            if (error) {
                continue;
            }

            if (checkingFunction(stack.data[stack.top])) {
                lexem = popChar(&stack);
                postfixExpression[jj++] = lexem;
                postfixExpression[jj++] = ' ';
            }

            unary_allowed = 0;
            binary_allowed = 1;

        } else if(checkingOperator(expression[ii]) && !bracket_required && (binary_allowed || unary_allowed)){

            while ((checkingFunction(stack.data[stack.top]) || checkingOperator(stack.data[stack.top]) ||
            stack.data[stack.top] == '(' || stack.data[stack.top] == '~' || stack.data[stack.top] == '#') &&
            (getPriority(stack.data[stack.top]) > getPriority(expression[ii]) ||
            (getPriority(stack.data[stack.top]) == getPriority(expression[ii]) && !(unary_allowed && (expression[ii] == '-' || expression[ii] == '+'))))) {

                char lexem = popChar(&stack);
                postfixExpression[jj++] = lexem;
                postfixExpression[jj++] = ' ';

            }

            if (unary_allowed && expression[ii] == '-') {
                pushChar(&stack, '~');
            } else if (unary_allowed && expression[ii] == '+') {
                pushChar(&stack, '#');
            } else {
                pushChar(&stack, expression[ii]);
            }

            if (unary_allowed) {
                unary_allowed = 0;
            } else {
                unary_allowed = 1;
            }

            binary_allowed = 0;

        }

        ii++;
    }

    char lexem = popChar(&stack);

    while (lexem != 0 && !error) {

        if (lexem == '(') {
            error = 1;
            continue;
        }

        postfixExpression[jj++] = lexem;
        postfixExpression[jj++] = ' ';
        lexem = popChar(&stack);
    }

    if (error) {
        postfixExpression[0] = '\0';
    } else {
        postfixExpression[jj++] = '\0';
    }

    return error;
}

int processPostfix(char *expression, double x, double *result){
    Stack stack;
    createStack($stack);

    int ii = 0;
    int error = 0;

    while (expression[ii] != '\0' && !error) {

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