#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    char Name[20];
    int Age;
} Person;

int main()
{
    Person *person;
    person = NULL;

    for (int index = 0; index < 5; index++)
    {
        if (person != NULL)
        {
            printf("\n Pointer with trash!");
            system("pause");
            return 0;
        }

        printf("\n Person %d data:", index);
        person = (Person*)malloc(sizeof(Person));

        printf("\n Name: ");
        scanf("%s", &person->Name);
        
        printf("\n Age: ");
        scanf("%d", &person->Age);
    }
}