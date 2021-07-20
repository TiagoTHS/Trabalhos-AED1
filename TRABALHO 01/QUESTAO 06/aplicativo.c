/*
Nome e matrícula dos integrantes do grupo:

Tiago da Silva e Souza Pinto - 12011BCC001
Paulo Vitor Costa Silva - 12011BCC045
Gabriela Santos Damazo - 12011BCC003
Isabelli Prudencio Tedeschi - 12011BCC018
*/

#include <stdio.h>
#include "listaDuplamEncad.h"

//PROTOTIPO DA IMPRIME LISTA
void imprime_lista(Lista lst);

int main(){

    Lista lst;
    Lista lst2; // para a lista invertida e nros primos

    int flag, opcao, elem, verifica, op;

    do{

    // MENU
    printf("-------------------------------------------------------------------\n");
    printf("Escolha uma opcao!\n");
    printf("Digite [1] para criar listas.\n");
    printf("Digite [2] para inserir o elemento desejado.\n");
    printf("Digite [3] para remover o elemento desejado.\n");
    printf("Digite [4] para remover todas as ocorrencias de um elemento.\n");
    printf("Digite [5] para remover o maior elemento\n");
    printf("Digite [6] para saber tamanho da lista.\n");
    printf("Digite [7] para esvaziar lista.\n");
    printf("Digite [8] para inverter lista.\n");
    printf("Digite [9] para mostrar lista com nros primos.\n");
    printf("Digite [10] para imprimir lista.\n");
    printf("Digite [11] para apagar listas.\n");
    printf("Digite [12] para sair.\n");
    printf("\n");
    scanf("%d", &opcao);

        switch(opcao){

            case 1:

                // CHAMADA DA FUNCAO CRIA LISTA PARA L1, L2
                lst = cria_lista();
                lst2 = cria_lista();

                if(lst == NULL || lst2 == NULL){
                    printf("\nListas criadas com sucesso!\n\n");
                    verifica = 1;
                }
                else{
                    printf("\nErro na criação das listas!\n\n");
                }

                break;

            case 2:

                if(verifica == 1){

                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja inserir um elemento (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }

                    if(op == 1){
                        printf("\nDigite o numero que deseja inserir: ");
                        fflush(stdin);
                        scanf("%d", &elem);

                        // CHAMADA DA FUNCAO INSERE ELEMENTO
                        flag = insere_elem(&lst, elem);

                        if(flag == 1){
                            printf("\nElemento inserido com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao inserir elemento!\n");
                        }
                    }
                    else{
                        printf("\nDigite o numero que deseja inserir: ");
                        fflush(stdin);
                        scanf("%d", &elem);

                        // CHAMADA DA FUNCAO INSERE ELEMENTO
                        flag = insere_elem(&lst2, elem);

                        if(flag == 1){
                            printf("\nElemento inserido com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao inserir elemento!\n");
                        }
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 3:
                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja remover um elemento (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        if(lista_vazia(lst) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        printf("\nDigite o numero que deseja remover: ");
                        fflush(stdin);
                        scanf("%d", &elem);

                        // CHAMADA DA FUNCAO REMOVE ELEMENTO
                        flag = remove_elem(&lst, elem);

                        if(flag == 1){
                            printf("\nElemento removido com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao remover elemento!\n");
                        }
                    }
                    else{
                        if(lista_vazia(lst2) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        printf("\nDigite o numero que deseja remover: ");
                        fflush(stdin);
                        scanf("%d", &elem);

                        // CHAMADA DA FUNCAO REMOVE ELEMENTO
                        flag = remove_elem(&lst2, elem);

                        if(flag == 1){
                            printf("\nElemento removido com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao remover elemento!\n");
                        }
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 4:
                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja remover todas as ocorrencias de um elemento (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        if(lista_vazia(lst) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        printf("\nDigite o numero que deseja remover todas as ocorrencias: ");
                        fflush(stdin);
                        scanf("%d", &elem);

                        // CHAMADA DA FUNÇÃO REMOVE_TODOS
                        flag = remove_todos(&lst, elem);

                        if(flag > 0){
                            printf("\nTodas as ocorrencias do elemento (%d) foram removidas com sucesso!\n", elem);
                        }
                        else{
                            printf("\nErro ao remover as ocorrencias do elemento!\n");
                        }
                    }
                    else{
                        if(lista_vazia(lst2) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        printf("\nDigite o numero que deseja remover todas as ocorrencias: ");
                        fflush(stdin);
                        scanf("%d", &elem);

                        // CHAMADA DA FUNÇÃO REMOVE_TODOS
                        flag = remove_todos(&lst2, elem);

                        if(flag > 0){
                            printf("\nTodas as ocorrencias do elemento (%d) foram removidas com sucesso!\n", elem);
                        }
                        else{
                            printf("\nErro ao remover as ocorrencias do elemento!\n");
                        }
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 5:
                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja remover o maior elemento (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        if(lista_vazia(lst) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        // CHAMADA DA FUNÇÃO REMOVE MAIOR ELEM
                        flag = remove_maior_elem(&lst, &elem);

                        if(flag == 1){
                            printf("\nMaior elemento (%d) foi removido com sucesso!\n", elem);
                        }
                        else{
                            printf("\nErro ao remover elemento!\n");
                        }
                    }
                    else{
                        if(lista_vazia(lst2) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        // CHAMADA DA FUNÇÃO REMOVE MAIOR ELEM
                        flag = remove_maior_elem(&lst2, &elem);

                        if(flag == 1){
                            printf("\nMaior elemento (%d) foi removido com sucesso!\n", elem);
                        }
                        else{
                            printf("\nErro ao remover elemento!\n");
                        }
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 6:
                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja saber o tamanho (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        // CHAMADA DA FUNÇÃO TAMANHO LISTA
                        flag = tamanho_lista(lst);
                        printf("\nTamanho da lista = %d\n", flag);
                    }
                    else{
                        // CHAMADA DA FUNÇÃO TAMANHO LISTA
                        flag = tamanho_lista(lst2);
                        printf("\nTamanho da lista = %d\n", flag);
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 7:
                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja esvaziar (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        if(lista_vazia(lst) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        // CHAMADA DA FUNÇÃO ESVAZIA LISTA
                        flag = esvazia_lista(&lst);

                        if(flag == 1){
                            printf("\nLista esvaziada com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao esvaziar lista!\n");
                        }
                    }
                    else{
                        if(lista_vazia(lst2) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        // CHAMADA DA FUNÇÃO ESVAZIA LISTA
                        flag = esvazia_lista(&lst2);

                        if(flag == 1){
                            printf("\nLista esvaziada com sucesso!\n");
                        }
                        else{
                            printf("\nErro ao esvaziar lista!\n");
                        }
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 8:
                if(verifica == 1){
                    if(lista_vazia(lst) == 1){
                        printf("\nA lista esta VAZIA!\n");
                        break;
                    }

                    // CHAMADA DA FUNÇAO INVERTE LISTA
                    lst2 = inverte_lista(lst);

                    if(lst2 != NULL){
                        printf("\nLista 1 foi invertida com sucesso!\n");
                        printf("\nLista 1 invertida pode ser encontrada ao imprimir lista 2!\n");
                    }
                    else{
                        printf("\nErro ao inverter lista!\n");
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 9:
                if(verifica == 1){
                    if(lista_vazia(lst) == 1){
                        printf("\nA lista esta VAZIA!\n");
                        break;
                    }

                    // CHAMADA DA FUNÇAO PRIMOS LISTA
                    lst2 = primos_lista(lst);

                    if(lst2 != NULL){
                        printf("\nLista 2 com primos foi criada com sucesso!\n");
                        printf("\nLista 2 com primos pode ser encontrada ao imprimir lista 2!\n");
                    }
                    else{
                        printf("\nErro ao formar lista com nros primos!\n");
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 10:
                 if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja imprimir (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        if(lista_vazia(lst) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        // CHAMADA DA FUNCAO IMPRIME LISTA
                        imprime_lista(lst);
                    }
                    else{
                        if(lista_vazia(lst2) == 1){
                            printf("\nA lista esta VAZIA!\n");
                            break;
                        }

                        // CHAMADA DA FUNCAO IMPRIME LISTA
                        imprime_lista(lst2);
                    }
                }
                else
                    printf("\nListas ainda nao foram criadas!\n");

                break;

            case 11:
                if(verifica == 1){

                    // CHAMADA DA FUNÇÃO APAGA LISTA PARA L1 e L2
                    apaga_lista(&lst);
                    apaga_lista(&lst2);

                    printf("\nListas apagadas com sucesso!\n");

                    verifica = 0;
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n");
                }

                break;

            case 12:

                printf("\nPrograma finalizado com sucesso!\n");

                break;

            default:
                printf("\nEssa opcao nao existe!\n");
        }

    }while(opcao != 12);

    return 0;
}

// IMPRIME LISTA
void imprime_lista(Lista lst){

    int elem = 0;
    int i = 0;

    if(lista_vazia(lst) == 1)
        printf("\nA lista esta VAZIA!\n");
    else{
        printf("\n\nLista = { ");
        // CHAMADA DA FUNÇÃO OBTEM VALOR ELEMENTO
        while(obtem_valor_elem(lst, i, &elem) == 1){
            printf("%d ", elem);
            i++;
        }
        printf("}\n\n");
    }
    printf("\n");
}
