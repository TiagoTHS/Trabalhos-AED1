#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

//Protótipos:
void print_lista(Lista lst);

int main()
{
    int k, ak, ak_teste, flag = 0;
    int option, x, pos;
    Lista li;

    li = cria_lista();
    option = 0;

    while(option != 7){
        printf(" ------------------------------------------------\n");
        printf("|  [1]Inicializar um polinomio                   |\n");
        printf("|  [2]Inserir novo termo a P(x)                  |\n");
        printf("|  [3]Imprimir P(x)                              |\n");
        printf("|  [4]Eliminar termo da k-esima potencia de P(x) |\n");
        printf("|  [5]Reinicializar um polinomio                 |\n");
        printf("|  [6]Calcular P(x), dado um valor x             |\n");
        printf("|  [7]Sair                                       |\n");
        printf(" ------------------------------------------------\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &option);

        switch(option){

            case 1:
                system("cls");

                if(lista_vazia(li)){
                    if(insere_ord(&li, 0, 0) == 1){
                        printf(">> Polinomio inicializado com sucesso!\n");
                        flag = 1;
                    }else{
                        printf(">> Nao foi possivel inicializar o polinomio!\n");
                    }
                }else{
                    printf(">> Erro: Polinomio ja inicializado!\n");
                }

                break;

            case 2:
                system("cls");

                if(flag == 0){ // Variável de controle para a inicializacao do polinomio
                    printf(">> Polinomio nao foi inicializado!\n");
                    break;
                }

                k = -1;
                while(k < 0){
                    printf(">> Digite o valor do expoente: ");
                    scanf("%d", &k);
                }

                printf(">> Digite o valor do coeficiente: ");
                scanf("%d", &ak);

                //Faz a verificação se já existe um termo AkX^k
                if(get_value(li, k, &ak_teste) == 1){
                    remove_ord(&li, k); //Remove o valor de k
                    ak = ak + ak_teste; //Adiciona ao valor de ak o ak antigo
                }

                if(insere_ord(&li, k, ak) == 0)
                    printf(">> Erro: Nao e possivel inserir o termo!\n");
                else
                    printf(">> Termo inserido com sucesso!\n");

                break;

            case 3:
                system("cls");

                if(flag == 0){
                    printf(">> Polinomio nao foi inicializado!\n");
                    break;
                }


                print_lista(li);

                break;

            case 4:
                system("cls");

                if(flag == 0){
                    printf(">> Polinomio nao foi inicializado!\n");
                    break;
                }

                printf(">> Digite o valor de k: ");
                scanf("%d", &k);

                if(remove_ord(&li, k) == 1)
                    printf(">> Elemento removido com sucesso!\n");
                else
                    printf(">> Elemento nao encontrado!\n");
                break;

            case 5:
                system("cls");

                if(flag == 0){
                    printf(">> Polinomio nao foi inicializado!\n");
                    break;
                }

                esvaziar_lista(&li);
                if(lista_vazia(li)){
                    if(insere_ord(&li, 0, 0)){
                        printf(">> Polinomio reinicializado com sucesso!\n");
                        flag = 1;
                    }
                }

                break;

            case 6:
                system("cls");

                if(flag == 0){
                    printf(">> Polinomio nao foi inicializado!\n");
                    break;
                }

                int solve = 0;
                pos = 0;

                if(lista_vazia(li)){
                    printf(">> Polinomio nao foi inicializado!\n");
                }else{

                    printf(">> Digite o valor de x: ");
                    scanf("%d", &x);

                    while(get_pos(li, pos, &k, &ak) == 1){
                        solve = solve + (ak * pow(x, k));
                        pos++;
                    }
                    printf(">> P(%d) = %d\n", x, solve);
                }

                break;

            case 7:
                system("cls");

                free(li);
                printf("Programa encerrado!\n");
                break;

            default:
                system("cls");

                printf("Opcao invalida, tente novamente!\n");
                break;
        }
    }

    return 0;
}

//Imprime a lista de polinômios
void print_lista(Lista lst){
    printf(">> Polinomio: ");
    int pos = 0, k, ak;

    //Verifica se a lista possui elementos
    if(lista_vazia(lst) || lst == NULL)
        printf("Sem termos no polinomio!\n");

    while(get_pos(lst, pos, &k, &ak)){
        if(pos != 0)
            printf(" ");
        if(ak != 0) {
            if(ak > 0)
                printf("+");
            if(ak != 1)
                printf("%d", ak);
            if(k != 0)
                printf("x");
            if(k > 1)
                printf("^%d", k);
        }

        pos++;
    }
    printf("\n");
}


