#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList {
    int Sequence;
    struct LinkedList *Previous;
    struct LinkedList *Next;
} LinkedList;

int main()
{
    LinkedList *list[5];

    for (int index = 0; index < 5; index++)
    {
        list[index] = (LinkedList*)malloc(sizeof(LinkedList));

        // printf("Tamanho do indice %d: %d", index, sizeof(list[index]));

        int previousIndex = index - 1;

        list[index]->Sequence = index + 1;
        
        if (index == 0)
            list[index]->Previous = NULL;
        else if (index == 4)
        {
            list[index]->Previous = list[previousIndex];
            list[index]->Next = NULL;
        }
        else
        {
            list[index]->Previous = list[previousIndex];
            list[previousIndex]->Next = list[index];
        }   
    }

    for (int index = 0; index < 5; index++)
    {
        if (list[index]->Previous == NULL)
            printf("\nEstou no primeiro");
        else if (list[index]->Next == NULL)
            printf("\nEstou no ultimo");
        else
            printf(
                "\nEu sou %d, o numero antes de mim e %d e apos e %d.",
                list[index]->Sequence,
                list[index]->Previous->Sequence,
                list[index]->Next->Sequence
            );
    }

    return 0;
}