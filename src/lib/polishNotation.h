#ifdef __cplusplus
extern "C" {
#endif

    #include "stack.h"

    #ifndef POLISHNOTATION_H
    #define POLISHNOTATION_H

    /**
    * Проверка на наличие арифмитических функций
    *
    * @param char *symbol
    *
    * @return int
    */
    int checkingOperator(char symbol);

    /**
    * Проверка на наличие трегонометрических функций
    *
    * @param char *symbol
    *
    * @return int
    */
    int checkingFunction(char symbol);

    /**
    * Получаем приоритет, для польской (префиксной) нотации
    *
    * @param char *symbol
    *
    * @return int
    */
    int getPriority(char symbol);

    /**
    * Перевод с (инфиксной) в (префиксной) нотацию
    *
    * @param const char *expression
    * @param char *postfixExpression
    *
    * @return int
    */
    int infixToPostfix(const char *expression, char *postfixExpression);

    /**
    * решаем (префиксную) нотацию и  передаем результат вычисления
    *
    * @param char *expression
    * @param double x
    * @param double *result
    *
    * @return int
    */
    int processPostfix(char *expression, double x, double *result);

    #endif // POLISHNOTATION_H

#ifdef __cplusplus
}
#endif
