/*
    Após a analise do problema, foi utilizada a Lista Dinâmica/Encadeada Simples
    pois foi possível perceber que não se sabe o tamanho máximo do polinômio, assim
    podendo trabalhar com polinômios grandes (lista grande), e que o programa consiste
    em inserir e remover elementos quase constantemente. Para melhor organizar o polinômio
    o critério de ordenação foi o crescente.
*/

#include <stdlib.h>
#include "lista.h"

struct no{
    int expoente, coeficiente;
    struct no *prox;
};

//Cria uma nova lista
Lista cria_lista(){
    return NULL; //Lista vazia recebe NULL
}

//Verifica se a lista é vazia
int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1; // Lista vazia
    else
        return 0; // Lista NÃO vazia
}

//Insere um elemento de forma ordenada na lista
int insere_ord(Lista *lst, int k, int ak){

    Lista N = (Lista)malloc(sizeof(struct no)); //Aloca um novo da nó

    //Verifica se a alocacão foi bem sucedida
    if (N == NULL)
        return 0; //Falha: nó não alocado

    //Insere o conteúdo(valores dos elementos)
    N->expoente = k;
    N->coeficiente = ak;

    //Verifica se a inserção deve ser feita no início da lista
    if (lista_vazia(*lst) || k <= (*lst)->expoente){
        N->prox = *lst; //Aponta para o 1º nó atual da lista
        *lst = N; //Faz a lista apontar para o novo nó
        return 1;
    }

    // Percorrimento da lista (elem > 1º nó da lista)
    Lista aux = *lst; //Faz aux apontar para 1º nó
    while (aux->prox != NULL && aux->prox->expoente < k)
        aux = aux->prox; // Avança na lista

    //Insere o novo elemento na lista
    N->prox = aux->prox;
    aux->prox = N;

    return 1;
}

//Remove um determinado elemento da lista
int remove_ord(Lista *lst, int k){
    //Verifica se a lista é vazia ou se K é menor que o primeiro elemento
    if(lista_vazia(*lst) || k < (*lst)->expoente)
        return 0; //Falha

    Lista aux = *lst; //Ponteiro auxiliar para o primeiro nó

    //Remove o elemento caso seja o 1º nó da lista
    if (k == (*lst)->expoente){
        *lst = aux->prox; // Lista aponta para o 2 o nó
        free(aux); // Libera memória alocada
        return 1;
    }

    // Percorrimento até final de lista, achar elem ou nó maior
    while (aux->prox != NULL && aux->prox->expoente < k)
        aux = aux->prox;  //Avança na lista

    //verifica se o elemento nao esta na lista
    if (aux->prox == NULL || aux->prox->expoente > k)
        return 0; //Falha

    //Remove o elemento diferente do 1º nó da lista
    Lista aux2 = aux->prox; //Aponta o nó a ser removido
    aux->prox = aux2->prox; //Retira o nó da lista
    free(aux2);             // libera memória alocada
    return 1;
}

//Obtem um elemento da lista dada sua posição
int get_pos(Lista lst, int pos, int *k, int *ak){
    //Verifica se a lista é vazia ou se a ṕosição é menor que zero
    if (lista_vazia(lst) || pos < 0)
        return 0; //Falha

    //Percorrimento da lista
    while (lst != NULL && pos--)
        lst = lst->prox; //Avança na lista

    //Verifica a lista é NULL
    if (lst == NULL)
        return 0; //Falha

    //Retorna o valor do nó
    *k = lst->expoente;
    *ak = lst->coeficiente;

    return 1;
}

//Obtem um elemento na lista dado seu valor
int get_value(Lista lst, int k, int *ak){
    if(lista_vazia(lst) || k < lst->expoente)
        return 0;

    //Percorrimento da lista enquanto diferente de NULL, e o expoente é menor que k
    while(lst != NULL && lst->expoente < k)
        lst = lst->prox; //Avança na lista

    //Verifica se a lista é NULL ou se o expoente é maior que k
    if(lst == NULL || lst->expoente > k)
        return 0; //Falha

    //Retorna o valor do nó
    *ak = lst->coeficiente;

    return 1;
}

//Esvazia a lista
int esvaziar_lista(Lista *lst){
    //Inicializa aux com o início da lista
    Lista aux = *lst, aux2;

    //Libera os elementos conforme percorre a lista
    while (aux != NULL){
        aux2 = aux->prox; //Variável aux2 recebe o próximo nó
        free(aux);        //Libera o nó na lista
        aux = aux2;       //aux passa a ser o próximo nó
    }

    //A lista aponta pra NULL, elementos foram eliminados
    *lst = NULL;

    return 1;
}


