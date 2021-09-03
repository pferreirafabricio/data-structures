#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkedList
{
    char nome[20];
    int idade;
    struct LinkedList *next, *back;
} LinkedList;

struct LinkedList *start, *current, *helper, *last;

void verify_if_list_is_empty()
{
    if (start != NULL)
        return;

    printf("Sem elementos na lista");
    system("pause");
}

void enterdata()
{
    printf("\nInforme o nome da pessoa: ");
    scanf("%s", &current->nome);
    printf("\nInforme a idade da pessoa: ");
    scanf("%d", &current->idade);
}

void insert()
{
    if (start == NULL)
    {
        current = (LinkedList *)malloc(sizeof(LinkedList));
        current->next = NULL;
        current->back = NULL;
        helper = current;
        start = current;
        last = current;
        enterdata();
    }
    else
    {

        current = (LinkedList *)malloc(sizeof(LinkedList));
        helper->next = current;
        current->back = helper;
        helper = current;
        last = current;
        enterdata();
    }
}

void list()
{
    verify_if_list_is_empty();

    helper = last;

    while (helper != NULL)
    {
        printf("\nNome: %s ==== Idade: %d \n", helper->nome, helper->idade);
        helper = helper->back;
    }
}

void search()
{
    char nameToSearch[20];

    verify_if_list_is_empty();

    helper = last;

    printf("\n Informe o nome para ser pesquisado: ");
    scanf("%s", &nameToSearch);

    while (helper != NULL)
    {
        if (strcmp(helper->nome, nameToSearch) != 0)
        {
            helper = helper->back;
            continue;
        }
        
        printf("\nAchei o %s com idade de %d\n", helper->nome, helper->idade);
        system("pause");
        break;
    }
}

void main()
{
    current = NULL;
    helper = NULL;
    start = NULL;
    last = NULL;

    int option;

    do
    {
        fflush(stdin);
        
        printf("\n --- Lista duplamente encadeada ---");
        printf("\n [1] - Inserir elemento na lista");
        printf("\n [2] - Exibir dados do fim/inicio");
        printf("\n [3] - Procurar por nome na lista");

        printf("\n Informe a opcao desejada: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            list();
            break;
        case 3:
            search();
            break;
        default:
            printf("\n Opcao invalida... Tente novamente!");
            system("pause");
        }

    } while (option != 4);
}
