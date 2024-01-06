#include "stack.h"

void createStack(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

void pushChar(Stack *stack, char symbol) {
    if (!isFull(stack)) {
        stack->top += 1;
        stack->data[stack->top] = symbol;
    }
}

void pushDouble(Stack *stack, double number) {
    if (!isFull(stack)) {
        stack->top += 1;
        stack->data[stack->top] = number;
    }
}
char popChar(Stack *stack) {
    char symbol = 0;
    if (!isEmpty(stack)) {
        symbol = stack->data[stack->top];
        stack->top -= 1;
    }
    return symbol;
}

double popDouble(Stack *stack) {
    double number = 0;
    if (!isEmpty(stack)) {
        number = stack->data[stack->top];
        stack->top -= 1;
    }
    return number;
}