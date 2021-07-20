/*
TAD Deque de números inteiros usando alocação estática/sequencial (com desperdício de posição)
com no máximo 15 elementos. O TAD deve contemplar as operações: cria_deque, deque_vazio,
deque_cheio, insere_inicio, insere_final, remove_inicio, remove_final e apagar_deque (que libera
a memória alocada para o deque). Além disso, deve-se implementar um programa aplicativo que
permita o usuário realizar repetidamente as seguintes ações: criar um deque, inserir e
remover elementos, imprimir o conteúdo do deque e liberá-lo. A opção de criação só pode ser
executada se o deque não existe (início do programa ou após usa liberação).
As demais opções só podem ser executadas após a criação de um deque. O programa também deve
ter uma opção para encerrar a execução.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "deque.h"

//Protótipos:
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

        printf("\nDigite a opção desejada: ");
        scanf("%d", &option);

        switch(option){
            case 1:

                if(cria_deque_teste(d) == 0){
                    d = cria_deque();

                    if(d != NULL)
                        printf("Deque criado com sucesso!\n");
                } else{
                    printf("Deque já criado. Para prosseguir com esta operação, primeiramente use a operação [5]\n");
                }

                break;

            case 2:

                if(cria_deque_teste(d) == 1)
                    inserir_elem(d);
                else
                    printf("Deque ainda não foi criado!\n");

                break;

            case 3:
                if(cria_deque_teste(d) == 1)
                    remover_elem(d);
                else
                    printf("Deque ainda não foi criado!\n");

                break;

            case 4:

                if(cria_deque_teste(d) == 1)
                    imprimir(d);
                else
                    printf("Deque ainda não foi criado!\n");

                break;

            case 5:

                if(cria_deque_teste(d) == 1)
                    apagar_deque(&d);
                else
                    printf("Deque ainda não foi criado!\n");

                break;

            case 6:

                system("cls");

                if(cria_deque_teste(d) == 1)
                    free(d);

                printf("Programa encerrado!\n");
                break;

            default:
                printf("Opção inválida, por favor tente novamente!\n");
                break;
        }

        printf("=======================================\n\n");
    }

    return 0;
}


void remover_elem(Deque f){
    int teste, elem, i;

    printf("[1] Remover no final\n");
    printf("[2] Remover no início\n>> ");
    scanf("%d", &i);

    if(i == 1){
        teste = remove_fim(f, &elem);
        if(teste == 1)
            printf("O elemento %d foi removido!\n", elem);
        else
            printf("Não foi possível remover o elemento!\n");
    } else if(i == 2){
        teste = remove_ini(f, &elem);
        if(teste == 1)
            printf("O elemento %d foi removido!\n", elem);
        else
            printf("Não foi possível remover o elemento!\n");
    } else
        printf("Opcão inválida!\n");

}

void inserir_elem(Deque f){
    int teste, elem, i;

    printf("[1] Inserir no final\n");
    printf("[2] Inserir no início\n>> ");
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
        printf("Opção inválida!\n");
        teste = 0;
    }

        if(teste == 0)
            printf("\nNão foi possível inserir o elemento!\n");

}

void imprimir(Deque f){
    int elem;
    Deque aux = cria_deque();

    if(deque_vazio(f) == 1)
        printf("O deque está vazio!\n");
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
