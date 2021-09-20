#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    char name[20];
    struct Stack *previous, *next;
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

void enter_data()
{
    printf("\nInsert the name of this element: ");
    scanf("%s", &top->name);
}

void consult()
{
    if (verify_if_stack_is_empty() == 0)
        return;

    printf("Item on top of the stack: %s", top->name);
}

void pop()
{
    if (verify_if_stack_is_empty() == 0)
        return;

    if (top->previous == NULL) {
        free(top);
        top = NULL;
        printf("End item of stack removed");
        return;
    }

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
    if (verify_if_stack_is_empty() == 0)
        return;

    helper = top;

    while (helper != NULL) {
        printf("\nI'm in the %s element", helper->name);
        helper = helper->previous;
    }

    printf("\n");
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
        printf("\n [5] - Clear screen");

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
        case 3:
            consult();
            break;
        case 4:
            list();
            break;
        case 5:
            system("cls");
            main();
            break;
        default:
            printf("\n Invalid option... Try again");
            system("pause");
        }

    } while (option != 5);
}