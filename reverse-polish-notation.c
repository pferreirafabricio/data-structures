#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct no
{

    char signal;
    struct no *next;

}no;

// definindo as funções
void Pile (no **top, char sig);
char Unpile(no **top);


int main()
{

    no *top = NULL;

    char expression[40] = "";
    char npr[40] ="";

    int i,j;
    j=0;

    system("cls");
    printf("\n Please enter com a expression");
    scanf("%s",&expression);

    for(i=0; i<strlen(expression); i++)
    {

        switch(expression[i])
        {
        case '(':
            break;

        case ')':
            npr[j] = Unpile(&top);
            j++;
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            Pile(&top, expression[i]);
            break;

        default :
            npr[j] = expression[i];
            j++;
        }
    }
    while (j < strlen(expression))
    {
        npr[j]=Unpile(&top);
        j++;
    }

    printf("\n Expression in Reverse Polish Notation %s",npr);
    getch();
    return 0;
}

// Function Pile

void Pile (no **top,char sig)
{

    no *cur;

    cur =(no*)malloc(sizeof(no));
    if(cur == NULL)
    {

        printf("\n Error - Unable to Pile");
        getch();
        return;

    }

    cur->signal = sig;
    cur->next = NULL;
    cur->next = *top;
    *top = cur;
    return;

}

// Função para Desemplihar o sinal da Pilha

char Unpile(no **top)
{
    no *cur;
    char sig;

    if(*top != NULL)
    {

        cur = *top;
        sig = cur->signal;
        *top= cur->next;
        free(cur);
        return(sig);
    }

    return (' ');

}
