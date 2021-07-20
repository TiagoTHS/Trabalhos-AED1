/*
Nome e matrícula dos integrantes do grupo:

Tiago da Silva e Souza Pinto - 12011BCC001
Paulo Vitor Costa Silva - 12011BCC045
Gabriela Santos Damazo - 12011BCC003
Isabelli Prudencio Tedeschi - 12011BCC018
*/

#include <stdio.h>
#include "lista.h"

//PROTOTIPO DA IMPRIME LISTA
void imprime_lista(Lista lst);

int main(){

    Lista lst;
    Lista lst2;
    Lista lst3; // para inverter e concatenar
    Lista lstAux; // apenas para facilitar no acesso das listas

    int flag, opcao, op, tam, verifica;
    float elem;

    do{

    // MENU
    printf("-------------------------------------------------\n");
    printf("Escolha uma opcao!\n");
    printf("Digite [1] para criar listas.\n");
    printf("Digite [2] para inserir elemento.\n");
    printf("Digite [3] para remover elemento.\n");
    printf("Digite [4] para remover numeros impares.\n");
    printf("Digite [5] para encontrar maior numero.\n");
    printf("Digite [6] para saber tamanho da lista.\n");
    printf("Digite [7] para esvaziar lista.\n");
    printf("Digite [8] para inverter lista.\n");
    printf("Digite [9] para concatenar listas.\n");
    printf("Digite [10] para imprimir lista.\n");
    printf("Digite [11] para apagar listas.\n");
    printf("Digite [12] para sair.\n");
    printf("\n");
    scanf("%d", &opcao);

        switch(opcao){

            case 1:

                // CHAMADA DA FUNCAO CRIA LISTA PARA L1, L2, L3
                lst = cria_lista();
                lst2 = cria_lista();
                lst3 = cria_lista();

                if(lst == NULL || lst2 == NULL || lst3 == NULL){
                    printf("\nErro na criacao das listas!\n\n");
                    return -1;
                }
                else{
                    printf("\nAs 3 listas foram criadas com sucesso!\n\n");
                    verifica = 1;
                }

                break;

            case 2:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op != 3){
                        printf("\nDigite o numero de qual lista voce deseja inserir um elemento (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    if(lista_cheia(lstAux) == 1){
                        printf("\nA lista esta CHEIA!\n");
                        break;
                    }

                    printf("\nDigite o numero que deseja inserir: ");
                    fflush(stdin);
                    scanf("%f", &elem);

                    // CHAMADA DA FUNCAO INSERE ELEMENTO
                    flag = insere_elem(lstAux, elem);

                    if(flag == 1){
                        printf("\nElemento inserido com sucesso!\n");
                    }
                    else{
                        printf("\nErro ao inserir elemento!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 3:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op != 3){
                        printf("\nDigite o numero de qual lista voce deseja remover um elemento (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    if(lista_vazia(lstAux) == 1){
                        printf("\nA lista esta VAZIA!\n");
                        break;
                    }

                    printf("\nDigite o numero que deseja remover: ");
                    fflush(stdin);
                    scanf("%f", &elem);

                    // CHAMADA DA FUNCAO REMOVE ELEMENTO
                    flag = remove_elem(lstAux, elem);

                    if(flag == 1){
                        printf("\nElemento removido com sucesso!\n");
                    }
                    else{
                        printf("\nErro ao remover elemento!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 4:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op != 3){
                        printf("\nDigite o numero de qual lista voce deseja remover os nros impares (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    if(lista_vazia(lstAux) == 1){
                        printf("\nA lista esta VAZIA!\n");
                        break;
                    }

                    // CHAMADA DA FUNCAO REMOVE IMPARES
                    flag = remove_impar(lstAux);

                    if(flag == 1){
                        printf("\nImpares removidos com sucesso!\n");
                    }
                    else{
                        printf("\nErro ao remover impares!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 5:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op != 3){
                        printf("\nDigite o numero de qual lista voce deseja procurar o maior elemento (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    if(lista_vazia(lstAux) == 1){
                        printf("\nA lista esta VAZIA!\n");
                        break;
                    }

                    // CHAMADA DA FUNCAO MAIOR ELEMENTO
                    flag = maior_elem(lstAux, &elem);

                    if(flag == 1){
                        printf("\nMaior elemento da lista eh: %f\n", elem);
                    }
                    else{
                        printf("\nErro ao encontrar elemento!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 6:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op!= 3){
                        printf("\nDigite o numero de qual lista voce deseja saber o tamanho (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    // CHAMADA DA FUNCAO MAIOR ELEMENTO
                    flag = tamanho_lista(lstAux, &tam);

                    if(flag == 1){
                        printf("\nA lista tem tamanho: %d\n", tam);
                    }
                    else{
                        printf("\nErro ao encontrar elemento!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 7:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op != 3){
                        printf("\nDigite o numero de qual lista voce deseja esvaziar (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    // CHAMADA DA FUNCAO MAIOR ELEMENTO
                    flag = esvazia_lista(lstAux);

                    if(flag == 1){
                        printf("\nLista esvaziada com sucesso!\n");
                    }
                    else{
                        printf("\nErro ao esvaziar lista!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 8:

                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2){
                        printf("\nDigite o numero de qual lista voce deseja inverter (1 ou 2): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else{
                        lstAux = lst2;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    // CHAMADA DA FUNCAO MAIOR ELEMENTO
                    lst3 = inverte_lista(lstAux);

                    if(lst3 != NULL){
                        printf("\nLista escolhida foi invertida com sucesso!\n");
                        printf("\nLista contendo a inversao pode ser vista ao imprimir lista 3!\n");
                    }
                    else{
                        printf("\nErro ao inverter lista!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 9:

                if(verifica == 1){
                    if(lst == NULL || lst2 == NULL || lst3 == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    // CHAMADA DA FUNÇÃO CONCATENA
                    lst3 = concatena(lst, lst2);

                    if(lst3 != NULL){
                        printf("\nListas 1 e 2 concatenadas com sucesso!\n");
                        printf("\nLista contendendo a concatenacao pode ser vista ao imprimir lista 3!\n");
                    }
                    else{
                        printf("\nErro ao concatenar listas!\n");
                    }
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 10:
                if(verifica == 1){
                    op = 0;
                    while(op != 1 && op != 2 && op != 3){
                        printf("\nDigite o numero da lista que deseja imprimir (1, 2 ou 3): ");
                        fflush(stdin);
                        scanf("%d", &op);
                    }
                    if(op == 1){
                        lstAux = lst;
                    }
                    else if(op == 2){
                        lstAux = lst2;
                    }
                    else{
                        lstAux = lst3;
                    }

                    if(lstAux == NULL){
                        printf("\nA lista ainda nao foi criada!\n");
                        break;
                    }

                    if(lista_vazia(lstAux) == 1){
                        printf("\nA lista esta VAZIA!\n");
                        break;
                    }

                    imprime_lista(lstAux);
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
                }

                break;

            case 11:

                if(verifica == 1){
                    if(lst == NULL || lst2 == NULL || lst3 == NULL){
                        printf("\nAs listas ainda nao foram criadas!\n");
                        break;
                    }

                    apaga_lista(&lst);
                    apaga_lista(&lst2);
                    apaga_lista(&lst3);

                    printf("\nAs 3 listas foram apagadas com sucesso!\n\n");
                }
                else{
                    printf("\nListas ainda nao foram criadas!\n\n");
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

// IMPRIMIR A LISTA
void imprime_lista(Lista lst){

    int i, flag = 1;
    float elem = 0;

    i = 1;

    printf("\n\nLista = { ");

    while(flag != 0){

        // CHAMADA DA FUNÇÃO GET POSICAO
        flag = get_pos(lst, i, &elem);

            if(flag != 0){
                printf("%f ", elem);
                i++;
        }
    }
    printf("}\n\n");
}
