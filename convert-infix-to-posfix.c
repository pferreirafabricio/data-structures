#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPRESSION_SIZE 50

typedef struct Stack
{
    char arithmetic_operator;
    struct Stack *next, *previous;
} Stack;

Stack *top, *helper;

int verify_if_stack_is_empty()
{
    if (top != NULL)
        return 1;

    printf("\nNo elements in stack\n");
    system("pause");
    return 0;
}

void pop()
{
    if (verify_if_stack_is_empty() == 0)
        return;

    if (top->previous == NULL) {
        free(top);
        top = NULL;
        return;
    }

    helper = top;
    top = top->previous;
    top->next = NULL;

    free(helper);
}

void push(char operator)
{
    if (top == NULL)
    {
        top = (Stack *)malloc(sizeof(Stack));
        top->previous = NULL;
        top->next = NULL;
        top->arithmetic_operator = operator;

        helper = top;
        return;
    }

    top = (Stack *)malloc(sizeof(Stack));
    helper->next = top;
    top->previous = helper;
    top->next = NULL;
    top->arithmetic_operator = operator;
    helper = top;
}

int is_arithmetic_operator(char character)
{
    if (
        character != '+' && character != '-' && character != '/' && character != '*')
        return 0;

    return 1;
}

void convert_infix_to_posfix(char expression[EXPRESSION_SIZE])
{
    printf("Expressão chegando %s: ", expression);
    int expression_length = strlen(expression);
    char posfix_expression[EXPRESSION_SIZE];

    for (int index = 0; index < expression_length; index++)
    {
        const char currentCharacter = expression[index];

        if (currentCharacter == '\0')
            break;

        if (currentCharacter == '(')
            continue;

        if (currentCharacter == ')' && top != NULL)
        {
            strcat(*posfix_expression, top->arithmetic_operator);
            pop();
            continue;
        }

        if (is_arithmetic_operator(currentCharacter) == 1)
        {
            push(currentCharacter);
            printf("\nArithmetic operator found: %c", currentCharacter);
            continue;
        }

        strcat(*posfix_expression, currentCharacter);
    }

    printf("The posfix expression is: %s", posfix_expression);
}

void enter_mathematic_expression()
{
    char expression[EXPRESSION_SIZE];

    printf("\nEnter the expression: ");
    scanf("%s", &expression);

    convert_infix_to_posfix(&expression);
}

int main()
{
    enter_mathematic_expression();
}