#ifdef __cplusplus
extern "C" {
#endif

    #ifndef STACK_H
    #define STACK_H

    #define MAX_SIZE 255

    typedef struct {
        double data[MAX_SIZE];
        int top;
    } Stack;

    void createStack(Stack *stack);

    int isFull(Stack *stack);

    int isEmpty(Stack *stack);

    void pushChar(Stack *stack, char symbol);

    void pushDouble(Stack *stack, double number);

    char popChar(Stack *stack);

    double popDouble(Stack *stack);

    #endif // STACK_H

#ifdef __cplusplus
}
#endif
