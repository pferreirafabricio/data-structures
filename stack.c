#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    char name[20];
    struct Stack *previous, *next;
} Stack;

Stack *top, *helper;

void verify_if_stack_is_empty()
{
    if (top != NULL)
        return;

    printf("\nNo elements in stack\n");
    system("pause");
}

void enter_data()
{
    printf("\nInsert the name of this element: ");
    scanf("%s", &top->name);
}

void pop()
{
    verify_if_stack_is_empty();

    helper = top;
    top = top->previous;
    top->next = NULL;

    free(helper);
    printf("\nElement removed from the stack");
}

void push()
{
    if (top == NULL)
    {
        top = malloc(sizeof(Stack));
        top->previous = NULL;
        top->next = NULL;

        helper = top;
        enter_data();
        return;
    }

    top = malloc(sizeof(Stack));
    helper->next = top;
    top->previous = helper;
    top->next = NULL;
    helper = top;
    enter_data();
}

void list()
{
    verify_if_stack_is_empty();

    helper = top;

    while (helper != NULL) {
        printf("\nI'm in the %s element", helper->name);
        helper = helper->previous;
    }

    helper = NULL;
}

int main()
{
    int option;

    do
    {
        fflush(stdin);

        printf("\n --- Stack ---");
        printf("\n [1] - Insert element in the stack");
        printf("\n [2] - Remove element from the stack");
        printf("\n [3] - Consult element in the stack");
        printf("\n [4] - List all the elements in the stack (for DEBUG)");

        printf("\n Choose the option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 4:
            list();
            break;
        default:
            printf("\n Invalid option... Try again");
            system("pause");
        }

    } while (option != 5);
}