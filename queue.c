#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    char desc[20];
    int mix;
    struct no *next;

} no;

struct no *inicio,*auxiliar,*fim;
int c,achou,k;
int xmix;

void enterdata()
{

    printf("\n Informe a descrição do processo");
    scanf("%s",&auxiliar->desc);
    printf("\n Informe o Mix do processo");
    scanf("%d",&auxiliar->mix);
}


void Dequeue()
{

    if(inicio == NULL)
    {
        printf("\n Queue is Empty");
        system("pause");

    }else {

     auxiliar = inicio;
     inicio = inicio->next;
     printf("\n Processo %s foi atendido com sucesso",auxiliar->desc);
     free(auxiliar);
     system("pause");
     c--;

    }
}


void Seaqueue()
{
    if(inicio == NULL)
    {
        printf("\n Queue is Empty");
        system("pause");
    }else {

       printf("\n Informe o Mix");
       scanf("%d",&xmix);
       achou =0;
       k=0;
       auxiliar = inicio;

       while(auxiliar != NULL)
       {
           k++;
           if(xmix == auxiliar->mix)
           {
             printf("\n Processo encontrado na Fila na seguinte posição %d",k);
             system("pause");
             achou =1;
             break;
           }else {

           auxiliar = auxiliar->next;

           }
       }

    if(achou == 0)
    {
        printf("\n Processo não consta na Queue");
        system("pause");
    }

    }
}





void Enqueue()
{
    if(inicio == NULL)
    {
        auxiliar = (no*)malloc(sizeof(no));
        inicio = auxiliar;
        fim = auxiliar;
        auxiliar->next = NULL;
        enterdata();
        c++;
    }else {

        if(c >= 5)
        {
            printf("\n Queue is Overflow");
            system("pause");
        }else {

        auxiliar=(no*)malloc(sizeof(no));
        fim->next = auxiliar;
        auxiliar->next = NULL;
        fim = auxiliar;
        enterdata();
        c++;
        }

    }
}


int main()
{

    inicio = NULL;
    fim = NULL;
    auxiliar = NULL;
    c=0;
    k=0;
    int op;
    do
    {
        system("cls");

        printf("\n [1] - Enqueue  Insere Elemento na Fila");
        printf("\n [2] - Dequeue  Remove Elemento na Fila");
        printf("\n [3] - Seaqueue Pesquisa Elemento na Fila");

        printf("\n Escolha a OPção Desejada");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Seaqueue();
            break;

        }

    }
    while (op !=4);
  return 0;
}
