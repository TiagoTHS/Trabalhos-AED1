#include <stdlib.h>
#include "lista.h"

#define MAX 20

struct lista{
    float no[MAX];
    int fim;
};

// CRIA LISTA
Lista cria_lista(){

    Lista lst;

    lst = (Lista)malloc(sizeof(struct lista));

    if(lst != NULL){
        lst->fim = 0;
        return lst; // Sucesso
    }
    return NULL; // Falha
}

// LISTA VAZIA
int lista_vazia(Lista lst){

    if(lst == NULL){
        return -1; // Lista nao existe
    }

    if(lst->fim == 0){
        return 1; // Vazia
    }
    else{
        return 0; // Lista não vazia
    }
}

// LISTA CHEIA
int lista_cheia(Lista lst){

    if(lst == NULL){
        return -1; // Lista nao existe
    }

    if(lst->fim == MAX){
        return 1; // Cheia
    }
    else{
        return 0; // Lista não cheia
    }
}

// INSERE ELEMENTOS
int insere_elem(Lista lst, float elem){

    if(lst == NULL || lista_cheia(lst) == 1){
        return 0; // Falha
    }

    lst->no[lst->fim] = elem;

    lst->fim++; // Avança o fim

    return 1; // Sucesso

}

// REMOVE ELEMENTOS
int remove_elem(Lista lst, float elem){

    if(lst == NULL || lista_vazia(lst) == 1){
        return 0; // Falha
    }

    int i, aux = 0;

    // Percorrimento até achar o elemento ou o final da lista
    while(aux < lst->fim && (lst->no[aux] != elem)){
        aux++;
    }

    if(aux == lst->fim){ // Final da lista e não achou o elemento
        return 0;
    }

    // Deslocamento a esquerda do sucessor até o final da lista
    for(i = aux + 1; i < lst->fim; i++){
        lst->no[i - 1] = lst->no[i];
    }
    lst->fim--; // Decremento do campo Fim
    return 1; // Sucesso
}

// OBTEM VALOR ELEMENTO OU GET POS
int get_pos(Lista lst, int posicao, float *elem){

    if(lst == NULL || lst->fim == 0 || posicao > lst->fim || posicao <= 0){
        return 0; // Falha
    }

    *elem = lst->no[posicao - 1];

    return 1; // Sucesso
}

// REMOVE IMPARES
int remove_impar(Lista lst){
    if(lst == NULL || lista_vazia(lst) == 1){
        return 0; // Trata lista vazia e falha na criação
    }

    int i, j;

    for(i = 0; i < (lst->fim); i++){
        // Para caso de encontrar impar na lista
        if((int)lst->no[i] % 2 != 0){
            for(j = i + 1; j < (lst->fim); j++){
                //Volta todos os elementos da lista em 1 posição
                lst->no[j - 1] = lst->no[j];
            }
            (lst->fim)--; // Decrementa o Fim
            i--; // Decrementa o i
        }
    }
    return 1; // Sucesso
}

// MAIOR ELEMENTO
int maior_elem(Lista lst, float *elem){

    int i;

    if(lst == NULL || lista_vazia(lst) == 1){
        return 0; // Falha
    }

    for(i = 0; i < lst->fim; i++){
        // Caso elemento na primeira posição
        if(i == 0){
            *elem = lst->no[i];
        }
        else{
            if(lst->no[i] > *elem){
                 *elem = lst->no[i];
            }
        }
    }
    return 1; // Sucesso
}

// TAMANHO LISTA
int tamanho_lista(Lista lst, int *tam){

    if(lst == NULL){
        return 0; // Falha
    }

    *tam = lst->fim;

    return 1; // Sucesso
}

// ESVAZIAR LISTA
int esvazia_lista(Lista lst){
    if(lst == NULL){
        return 0; // FALHA
    }

    lst->fim = 0;

    return 1; // Sucesso
}

//INVERTE LISTA
Lista inverte_lista(Lista lst){

    Lista lst2;
    lst2 = cria_lista();
    int i;

    if(lst == NULL || lst2 == NULL){
        return NULL; // Falha
    }

    // Percorre do final ao inicio da lista
    for(i = lst->fim - 1; i >= 0; i--){
        lst2->no[lst2->fim] = lst->no[i];
        lst2->fim++; // Avança o fim
    }

    return lst2; // Sucesso
}

// CONCATENA DUAS LISTAS
Lista concatena(Lista lst, Lista lst2){

    Lista lst3;
    lst3 = cria_lista();

    if(lst == NULL || lst2 == NULL || lst3 == NULL){
        return NULL; // Falha
    }

    int i;

    for(i = 0; i < lst->fim; i++){
        lst3->no[lst3->fim] = lst->no[i];
        lst3->fim++; // Avança o fim
    }

    for(i = 0; i < lst2->fim; i++){
        // Se lista estiver cheia não tem como mais inserir e retorna lst3
        if(lista_cheia(lst3) == 1){
            return lst3; // Sucesso
        }
        lst3->no[lst3->fim] = lst2->no[i];
        lst3->fim++; // Avança o fim
    }

    return lst3; // Sucesso;
}

// APAGA LISTA
void apaga_lista(Lista *lst){
    free(*lst);
    (*lst) = NULL;
}
