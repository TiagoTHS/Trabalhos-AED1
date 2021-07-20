/*
Tiago da Silva e Souza Pinto - 12011BCC001
Paulo Vitor Costa Silva - 12011BCC045
Gabriela Santos Damazo - 12011BCC003
Isabelli Prudencio Tedeschi - 12011BCC018
*/

#include <stdio.h>
#include <locale.h>
#include "lista.h"

void imprime_lista(Lista L);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int op, flag = 0, opcao;
    double elemento;
    Lista L;
    Lista L2;
    Lista L3;

    do{
        do{
            printf("\n****************************\n"
                   "[1] Criar lista\n"
                   "[2] Inserir um elemento\n"
                   "[3] Remover um elemento\n"
                   "[4] Maior elemento da lista\n"
                   "[5] Tamanho da lista\n"
                   "[6] Verificar se as listas são iguais\n"
                   "[7] Intercalar as listas\n"
                   "[8] Imprimir lista\n"
                   "[9] Apagar Lista\n"
                   "[10] Sair");
            printf("\n\nEscolha uma das opções acima: ");
            scanf("%d", &op);
            printf("\n****************************\n");

            if (op < 1 || op > 10)
                printf("\n\n**Opção não válida!**\n\n");

        }while(op < 1 || op > 10);

        if (op == 10){
            break;
        }
        else if(op != 1 && flag == 0){
            printf("\nA lista precisa ser criada antes!\n");
            continue;
        }


        switch(op){

            case 1 :{

                L = cria_lista();
                L2 = cria_lista();
                L3 = cria_lista();

                if (flag != 0){
                    printf("\nA lista foi inicializada mais uma vez!\n");
                }
                else
                    printf("\nA lista foi criada com sucesso!\n");

                flag++;
                break;
            };

            case 2:{
                opcao = 0;
                do{
                    printf("\nEm qual das listas vai inserir o elemento (1 ou 2 ou 3): ");
                    fflush(stdin);
                    scanf("%d", &opcao);

                    if (opcao < 1 || opcao > 3)
                        printf("\n\n**Opção não válida!**\n\n");

                }while(opcao < 1 || opcao > 3);


                //INSERIR O ELEMENTO
                printf("\nDigite o número que você quer inserir: ");
                fflush(stdin);
                scanf("%lf", &elemento);

                if(opcao == 1){
                    if (insere_elem(L, elemento)==0)
                        printf("\nErro ao inserir elemento!\n");
                    else
                        printf("\nO elemento foi inserido com sucesso!\n\n");
                }
                if(opcao == 2){
                    if (insere_elem(L2, elemento)==0)
                        printf("\nErro ao inserir elemento!\n");
                    else
                        printf("\nO elemento foi inserido com sucesso!\n\n");
                }
                if(opcao == 3){
                    if (insere_elem(L3, elemento)==0)
                        printf("\nErro ao inserir elemento!\n");
                    else
                        printf("\nO elemento foi inserido com sucesso!\n\n");
                }

                break;
            }

            case 3:{

                opcao = 0;
                do{
                    printf("\nEm qual das listas vai remover o elemento (1 ou 2 ou 3): ");
                    fflush(stdin);
                    scanf("%d", &opcao);

                    if (opcao < 1 || opcao > 3)
                        printf("\n**Opção não válida!**\n");

                }while(opcao < 1 || opcao > 3);


                //REMOVER O ELEMENTO
                printf("\nQual elemento vai ser removido: ");
                fflush(stdin);
                scanf("%lf", &elemento);

                if(opcao == 1){
                    if (remove_elem(L, elemento)==0)
                        printf("\nLista está vazia ou o elemento não foi encontrado!\n");
                    else
                        printf("\nO elemento %lf foi removido com sucesso!\n", elemento);
                }
                if(opcao == 2){
                    if (remove_elem(L2, elemento)==0)
                        printf("\nLista está vazia ou o elemento não foi encontrado!\n");
                    else
                        printf("\nO elemento %lf foi removido com sucesso!\n", elemento);
                }
                if(opcao == 3){
                    if (remove_elem(L3, elemento)==0)
                        printf("\nLista está vazia ou o elemento não foi encontrado!\n");
                    else
                        printf("\nO elemento %lf foi removido com sucesso!\n", elemento);
                }

                break;
            }

            case 4:{

                opcao = 0;
                do{
                    printf("\nEm qual das listas vai verificar o maior elemento (1 ou 2 ou 3): ");
                    fflush(stdin);
                    scanf("%d", &opcao);

                    if (opcao < 1 || opcao > 3)
                        printf("\n\n**Opção não válida!**\n\n");
                }while(opcao < 1 || opcao > 3);



                double maior;
                if(opcao == 1){
                    maior = maior_elem(L);
                    printf("\nO maior elemento da lista é: %lf\n", maior);
                }
                if(opcao == 2){
                    maior = maior_elem(L2);
                    printf("\nO maior elemento da lista é: %lf\n", maior);
                }
                if(opcao == 3){
                    maior = maior_elem(L3);
                    printf("\nO maior elemento da lista é: %lf\n", maior);
                }

                break;
            }

            case 5:{

                opcao = 0;
                do{
                    printf("\nEm qual das listas vai verificar o tamanho da lista (1 ou 2 ou 3): ");
                    fflush(stdin);
                    scanf("%d", &opcao);

                    if (opcao < 1 || opcao > 3)
                        printf("**Opção não válida!**\n");

                }while(opcao < 1 || opcao > 3);


                int num;
                if(opcao == 1){
                    num = tamanho_lista(L);
                    printf("\nA lista tem %d elementos!\n", num);
                }
                if(opcao == 2){
                    num = tamanho_lista(L2);
                    printf("\nA lista tem %d elementos!\n", num);
                }
                if(opcao == 3){
                    num = tamanho_lista(L3);
                    printf("\nA lista tem %d elementos!\n", num);
                }

                break;
            }

            case 6: {
                //VERIFICAR SE LISTAS SÃO IGUAIS
                if(iguala_lista(L, L2)== 1)
                    printf("\nListas são iguais!!\n");
                else
                    printf("\nListas diferentes!\n");

                break;
            }

            case 7: {
                //INTERCALAR LISTA
                L3 = intercala_lista(L, L2);
                    printf("\nLista intercalada com sucesso!\n");

                break;
            }

            case 8: {

                opcao = 0;
                do{
                    printf("\nImprimir qual lista (1, 2 ou 3): ");
                    fflush(stdin);
                    scanf("%d", &opcao);

                    if (opcao < 1 || opcao > 3)
                        printf("**Opção não válida!**\n");

                }while(opcao < 1 || opcao > 3);


                //IMPRIMIR LISTA
                if(opcao == 1)
                    imprime_lista(L);
                if(opcao == 2)
                    imprime_lista(L2);
                if(opcao == 3)
                    imprime_lista(L3);

                break;
            }

            case 9: {
                limpa_lista(L);
                limpa_lista(L2);
                limpa_lista(L3);

                printf("Listas limpas!\n");

                break;
            }

        }
    }while (op != 10);

    printf("PROGRAMA FINALIZADO!");

    return 0;
}

void imprime_lista(Lista L){

    if(lista_vazia(L) == 1){
        printf("Lista vazia!\n");
        return;
    }

    printf("\nLista: {");

    int i=0;
    double elem;

    while(obtem_elem(L, i, &elem) != 0){
        printf(" %lf ", elem);
        i++;
    }

    printf("}\n");
    return;
}
