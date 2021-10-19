#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    char name[20];
    struct Stack *previous, *next;
} Stack;

typedef struct Queue
{
    char name[20];
	int mix;
    struct Queue *next;
} Queue;

Stack *top, *helper_stack;
Queue *helper_queue, *start, *end;

int max_queue_elements;

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

void convert_to_queue()
{
	if (verify_if_stack_is_empty() == 0)
        return;
	
	helper_stack = top;
	
	while (helper_stack != NULL) {
		free(helper_stack->next);
		
		if (start == NULL)
		{
			helper_queue = (Queue*)malloc(sizeof(Queue));
			start = helper_queue;
			end = helper_queue;
			helper_queue->next = NULL;
			
			strcpy(helper_queue->name, helper_stack->name);
			printf("\nProcess identifier for %s: ", helper_queue->name);
			scanf("%d", &helper_queue->mix);
			
			max_queue_elements++;
			helper_stack = helper_stack->previous;
			continue;
		}

		if (max_queue_elements >= 5)
		{
			printf("\nQueue is Overflow");
			system("pause");
			break;
		}

		helper_queue = (Queue*)malloc(sizeof(Queue));
		end->next = helper_queue;
		helper_queue->next = NULL;
		end = helper_queue;
		
		strcpy(helper_queue->name, helper_stack->name);
		printf("\nProcess identifier for %s: ", helper_queue->name);
		scanf("%d", &helper_queue->mix);
		
		max_queue_elements++;
		
		helper_stack = helper_stack->previous;
    }
	
	free(top);
	free(helper_stack);
	top = NULL;
	helper_stack = NULL;
}

void list_queue()
{
	if (start == NULL)
	{
		printf("\nNo elements in the queue\n");
		system("pause");
		return;
	}

    helper_queue = start;

    while (helper_queue != NULL) {
        printf("\nI'm in the %s element, with mix identifier: %d", helper_queue->name, helper_queue->mix);
        helper_queue = helper_queue->next;
    }

    printf("\n");
    helper_queue = NULL;
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

    helper_stack = top;
    top = top->previous;
    top->next = NULL;

    free(helper_stack);
    printf("\nElement removed from the stack");
}

void push()
{
    if (top == NULL)
    {
        top = (Stack*)malloc(sizeof(Stack));
        top->previous = NULL;
        top->next = NULL;

        helper_stack = top;
        enter_data();
        return;
    }

    top = (Stack*)malloc(sizeof(Stack));
    helper_stack->next = top;
    top->previous = helper_stack;
    top->next = NULL;
    helper_stack = top;
    enter_data();
}

int main()
{
    int option;

    do
    {
        fflush(stdin);

        printf("\n --- Stack to queue converter ---");
        printf("\n [1] - Insert element in the stack");
        printf("\n [2] - Remove element from the stack");
        printf("\n [3] - Convert stack to queue");
        printf("\n [4] - List all the elements in the queue");
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
            convert_to_queue();
            break;
        case 4:
            list_queue();
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


