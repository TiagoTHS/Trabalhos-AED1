/*
    by
    Gabriela Santos Damazo - 12011BCC003
    Isabelli Prudencio Tedeschi - 12011BCC018
    Paulo Vitor Costa Silva - 12011BCC045
    Tiago da Silva e Souza Pinto - 12011BCC001
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaEstSeq.h"

void print_lista(Lista lst);

int main()
{
    int option, teste, list_option;
    char elem;
    Lista li1, li2, li3;

    li1 = cria_lista();
    li2 = cria_lista();
    li3 = cria_lista();

    option = 0;

    while(option != 9){ //enquanto a opção selecionada não for 4
        printf(" --------------------------------\n");
        printf("|  [1]Inserir elemento na lista  |\n");
        printf("|  [2]Remover elemento da lista  |\n");
        printf("|  [3]Remover elementos pares    |\n");
        printf("|  [4]Esvaziar lista             |\n");
        printf("|  [5]Imprimir lista             |\n");
        printf("|  [6]Tamanho da lista           |\n");
        printf("|  [7]Menor elemento da lista    |\n");
        printf("|  [8]Intercalar listas          |\n");
        printf("|  [9]Sair                       |\n");
        printf(" --------------------------------\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &option);

        switch(option){ //Faz a verificação da opção selecionada de 1 a 6

            case 1:
            //Insere um elemento na lista desejada
                system("cls");
                printf(">> Em qual lista deseja inserir [1 ou 2]? ");
                scanf("%d", &list_option);

                if(list_option == 1){

                    if(li1 == NULL){
                        printf(">> Erro: Lista vazia ou NULL!\n");
                    }else{
                        printf(">> Digite o caractere a ser inserido: ");
                        fflush(stdin);
                        scanf("%c", &elem);
                        teste = insere_ord(li1, elem);
                        if(teste == 0){
                            printf(">> Nao foi possivel inserir o elemento!\n");
                        }else{
                            printf(">> Elemento inserido com sucesso!\n");
                        }
                    }

                } else if(list_option == 2){

                    if(li2 == NULL){
                        printf(">> Erro: Lista vazia ou NULL!\n");
                    }else{
                        printf(">> Digite o caractere a ser inserido: ");
                        fflush(stdin);
                        scanf("%c", &elem);
                        teste = insere_ord(li2, elem);
                        if(teste == 0){
                            printf(">> Nao foi possivel inserir o elemento!\n");
                        }else{
                            printf(">> Elemento inserido com sucesso!\n");
                        }
                    }

                } else{
                    printf("Opcao invalida, tente novamente!\n");
                }

                break;

            case 2:
            //Remove um elemento em uma lista desejada
                system("cls");
                printf(">> Em qual lista deseja remover [1 ou 2]? ");
                scanf("%d", &list_option);

                if(list_option == 1){

                    if(li1 == NULL || lista_vazia(li1) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        printf(">> Digite o caractere a ser removido: ");
                        fflush(stdin);
                        scanf("%c", &elem);
                        teste = remove_ord(li1, elem);
                        if(teste == 0){
                            printf(">> Nao foi possivel remover o caractere!\n");
                        }else{
                            printf(">> Caractere removido com sucesso!\n");
                        }
                    }

                } else if(list_option == 2){

                    if(li2 == NULL || lista_vazia(li2) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        printf(">> Digite o caractere a ser removido: ");
                        fflush(stdin);
                        scanf("%c", &elem);
                        teste = remove_ord(li2, elem);
                        if(teste == 0){
                            printf(">> Nao foi possivel remover o caractere!\n");
                        }else{
                            printf(">> Caractere removido com sucesso!\n");
                        }
                    }

                } else{
                    printf("Opcao invalida, tente novamente!");
                }

                break;

            case 3:
            //Remove os pares das listas
                system("cls");
                printf(">> Em qual lista deseja remover [1 ou 2]? ");
                scanf("%d", &list_option);

                if(list_option == 1){

                    if(li1 == NULL || lista_vazia(li1) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        remove_pares(li1);

                        printf(">> Pares removidos, caso existam! Verifique abaixo\n");
                        printf(">> Lista 1: [ ");
                        print_lista(li1);
                        printf("]\n");
                    }

                } else if(list_option == 2){

                    if(li2 == NULL || lista_vazia(li2) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{

                        remove_pares(li2);

                        printf(">> Pares removidos, caso existam! Verifique abaixo\n");
                        printf(">> Lista 2: [ ");
                        print_lista(li2);
                        printf("]\n");
                    }

                } else{
                    printf("Opcao invalida, tente novamente!");
                }

                break;

            case 4:
            //Esvazia a lista selecionada
                system("cls");
                printf(">> Qual lista deseja esvaziar [1 ou 2]? ");
                scanf("%d", &list_option);

                if(list_option == 1){

                    if(li1 == NULL){
                        printf(">> Erro: Lista vazia ou NULL!\n");
                    }else{
                        esvaziar_lista(li1);
                        printf(">> Lista apagada com sucesso!\n");
                    }

                } else if(list_option == 2){

                    if(li2 == NULL){
                        printf(">> Erro: Lista vazia ou NULL!\n");
                    }else{
                        esvaziar_lista(li2);
                        printf(">> Lista apagada com sucesso!\n");
                    }

                } else{
                    printf("Opcao invalida, tente novamente!");
                }

                break;

            case 5:
            //Imprime as listas
                system("cls");

                printf(">> Lista 1: [ ");
                print_lista(li1);
                printf("]\n");

                printf(">> Lista 2: [ ");
                print_lista(li2);
                printf("]\n");

                break;

            case 6:
            //Mostra a quantidade de elementos da lista desejada
                system("cls");
                printf(">> Qual lista deseja consultar [1 ou 2]? ");
                scanf("%d", &list_option);

                if(list_option == 1){

                    if(li1 == NULL || lista_vazia(li1) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        printf(">> A lista 1 possui [%d] elementos\n", tamanho_lista(li1));
                    }

                } else if(list_option == 2){

                    if(li2 == NULL || lista_vazia(li2) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        printf(">> A lista 2 possui [%d] elementos\n", tamanho_lista(li2));
                    }

                } else{
                    printf("Opcao invalida, tente novamente!");
                }

                break;

            case 7:
                system("cls");
                printf(">> Qual lista deseja consultar [1 ou 2]? ");
                scanf("%d", &list_option);

                if(list_option == 1){

                    if(li1 == NULL || lista_vazia(li1) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        printf(">> O menor elemento da lista 1 eh: [%c]\n", menor_valor(li1));
                    }

                } else if(list_option == 2){

                    if(li2 == NULL || lista_vazia(li2) == 1){
                        printf(">> A lista eh vazia ou NULL!\n");
                    }else{
                        printf(">> O menor elemento da lista 2 eh: [%c]\n", menor_valor(li2));
                    }

                } else{
                    printf("Opcao invalida, tente novamente!");
                }

                break;

            case 8:
                system("cls");

                esvaziar_lista(li3);
                printf(">> Lista 3: [ ");
                if(intercalar_lista(li1, li2, li3)==1)
                    print_lista(li3);
                printf("]\n");


                break;

            case 9:
                system("cls");
                free(li1);
                free(li2);
                free(li3);
                printf("Programa encerrado!\n");
                break;

            default:
                system("cls");
                printf(">> Opcao invalida, tente novamente!\n");
                break;
        }
    }

    return 0;
}

void print_lista(Lista lst){
    int pos;
    char elem;
    if(lst == NULL || lista_vazia(lst) == 1){
        printf("A lista eh vazia ou NULL!");
    } else{
        for(pos = 0; pos < MAX; pos++){
            if(get_pos(lst, pos, &elem)==1)
                printf("%c ", elem);
            else
                break;
        }
    }
}


