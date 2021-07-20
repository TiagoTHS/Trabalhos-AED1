/*
TAD Deque de n�meros inteiros usando aloca��o est�tica/sequencial (com desperd�cio de posi��o)
com no m�ximo 15 elementos. O TAD deve contemplar as opera��es: cria_deque, deque_vazio,
deque_cheio, insere_inicio, insere_final, remove_inicio, remove_final e apagar_deque (que libera
a mem�ria alocada para o deque). Al�m disso, deve-se implementar um programa aplicativo que
permita o usu�rio realizar repetidamente as seguintes a��es: criar um deque, inserir e
remover elementos, imprimir o conte�do do deque e liber�-lo. A op��o de cria��o s� pode ser
executada se o deque n�o existe (in�cio do programa ou ap�s usa libera��o).
As demais op��es s� podem ser executadas ap�s a cria��o de um deque. O programa tamb�m deve
ter uma op��o para encerrar a execu��o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"

//Prot�tipos:
//--------------------------
void remover_elem(Deque f);
void inserir_elem(Deque f);
void imprimir(Deque f);
int cria_deque_teste(Deque d);

int main()
{
    setlocale(LC_ALL,"Portuguese");


    Deque d = NULL;
    int option = 0;

    while(option != 6){
        printf(" -------------MENU------------- \n");
        printf("|                              |\n");
        printf("| [1]  Criar um deque          |\n");
        printf("| [2]  Inserir elemento        |\n");
        printf("| [3]  Remover elemento        |\n");
        printf("| [4]  Imprimir deque          |\n");
        printf("| [5]  Apagar deque            |\n");
        printf("| [6]  Sair                    |\n");
        printf(" ------------------------------ \n");

        printf("\nDigite a op��o desejada: ");
        scanf("%d", &option);

        switch(option){
            case 1:

                if(cria_deque_teste(d) == 0){
                    d = cria_deque();

                    if(d != NULL)
                        printf("Deque criado com sucesso!\n");
                } else{
                    printf("Deque j� criado. Para prosseguir com esta opera��o, primeiramente use a opera��o [5]\n");
                }

                break;

            case 2:

                if(cria_deque_teste(d) == 1)
                    inserir_elem(d);
                else
                    printf("Deque ainda n�o foi criado!\n");

                break;

            case 3:
                if(cria_deque_teste(d) == 1)
                    remover_elem(d);
                else
                    printf("Deque ainda n�o foi criado!\n");

                break;

            case 4:

                if(cria_deque_teste(d) == 1)
                    imprimir(d);
                else
                    printf("Deque ainda n�o foi criado!\n");

                break;

            case 5:

                if(cria_deque_teste(d) == 1)
                    apagar_deque(&d);
                else
                    printf("Deque ainda n�o foi criado!\n");

                break;

            case 6:

                system("cls");

                if(cria_deque_teste(d) == 1)
                    free(d);

                printf("Programa encerrado!\n");
                break;

            default:
                printf("Op��o inv�lida, por favor tente novamente!\n");
                break;
        }

        printf("=======================================\n\n");
    }

    return 0;
}


void remover_elem(Deque f){
    int teste, elem, i;

    printf("[1] Remover no final\n");
    printf("[2] Remover no in�cio\n>> ");
    scanf("%d", &i);

    if(i == 1){
        teste = remove_fim(f, &elem);
        if(teste == 1)
            printf("O elemento %d foi removido!\n", elem);
        else
            printf("N�o foi poss�vel remover o elemento!\n");
    } else if(i == 2){
        teste = remove_ini(f, &elem);
        if(teste == 1)
            printf("O elemento %d foi removido!\n", elem);
        else
            printf("N�o foi poss�vel remover o elemento!\n");
    } else
        printf("Opc�o inv�lida!\n");

}

void inserir_elem(Deque f){
    int teste, elem, i;

    printf("[1] Inserir no final\n");
    printf("[2] Inserir no in�cio\n>> ");
    scanf("%d", &i);

    if(i == 1){
        printf("Digite o valor que deseja inserir: ");
        scanf("%d", &elem);
        teste = insere_fim(f, elem);
    } else if(i == 2){
        printf("Digite o valor que deseja inserir: ");
        scanf("%d", &elem);
        teste = insere_ini(f, elem);
    } else{
        printf("Op��o inv�lida!\n");
        teste = 0;
    }

        if(teste == 0)
            printf("\nN�o foi poss�vel inserir o elemento!\n");

}

void imprimir(Deque f){
    int elem;
    Deque aux = cria_deque();

    if(deque_vazio(f) == 1)
        printf("O deque est� vazio!\n");
    else{
        while(remove_ini(f, &elem)){
            insere_fim(aux, elem);
        }

        printf("\nElementos: [ ");
        while(remove_ini(aux, &elem) == 1){
            printf("%d ", elem);
            insere_fim(f, elem);
        }
        printf("]\n");
    }
}

int cria_deque_teste(Deque d){
    if(d != NULL)
        return 1;
    else
        return 0;
}

//---------------------------
