#include <stdlib.h>
#include "lista.h"

struct no{
    double info;
    struct no * prox;
};
typedef struct no * Lista;


Lista cria_lista(){         //criar o nó cabeçalho
    Lista cab = (Lista) malloc (sizeof(struct no));

    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0;      //vai guardar o tamnho da lista
    }

    return cab;
}

int lista_vazia(Lista li){
    if (li->prox == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista li, double elem){
    Lista N = (Lista) malloc (sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info = elem;     //nó N recebe o valor do elem pra ser inserido

    Lista aux = li;     //aux vai pro primeiro elemento

    while (aux->prox != NULL && aux->prox->info < elem) //repete até chegar ao fim ou o próximo elemento for maior que o que vai ser inserido
        aux = aux->prox;

    N->prox = aux->prox;    //N aponta para onde aux tava apontando
    aux->prox = N;          //aux passa a apontar para N

    li->info++;             //cabeçalho passa a ter um elemento a mais (contando quando itens foram adicionados
    return 1;
}


int remove_elem(Lista li, double elem){
    if (lista_vazia(li)==1)
        return 0;

    Lista aux = li;

    while(aux->prox != NULL && aux->prox->info != elem)    //enquanto não chegar ao fim ou achar o elem percorrer a lista
        aux = aux->prox;

    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    Lista aux2 = aux->prox;     //aux2 rebece o aux->prox (elem que vai ser removido)
    aux->prox = aux2->prox;     //aux aponta para o próximo do elem que vai ser removido

    free(aux2);                 //libera o espaço do aux2
    li->info--;                 //menos um elemento na lista
    return 1;
}

int maior_elem(Lista li){
    Lista aux = li->prox;       //aux aponta para o primeiro nó com elementos da lista
    double maior = 0;

    if(lista_vazia(li)== 1)
        return 0;

    while (aux->prox != NULL){
        aux = aux->prox;        //aux percorre a lista
    }

    if(aux->prox == NULL)
        maior = aux->info;      //como é ordenada o último elemento é o maior

    return maior;
}

int tamanho_lista(Lista li){
    return li->info;        //tamanho ficou no cabeçalho/primeiro nó da lista --> li->info
}

int obtem_elem(Lista li, int pos, double *elem){

    Lista aux = li->prox;   //aux aponta pro primeiro nó que contém elemento da lista
    int j = 0;

    while(aux->prox != NULL && j!= pos){
        aux = aux->prox;    //enquanto não achar a posição requerida ou até chegar ao fim, percorre a lista
        j++;                //um contador acompanha a lista marcando quantas posições foram
    }

    if(j != pos && aux->prox == NULL)
        return 0;           //se chegar ao fim e não achar a posição significa que não tem mais elemento na posição desejada

    if(j == pos)
        * elem = aux->info; //se chegar a posição que quer, retorna o elemento dessa posição

    return 1;
}

Lista intercala_lista(Lista li, Lista li2){
    if (lista_vazia(li) == 1 || lista_vazia(li2)==1)
        return 0;

    Lista aux = li->prox;
    Lista aux2 = li2->prox;

    Lista li3;
    li3 = cria_lista();

    li3->prox = NULL;
    Lista auxN = li3->prox;

    while (aux != NULL && aux2 != NULL){

        if(aux->info <= aux2->info){
            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3->prox = N;
            else
                auxN->prox = N;

            N->info = aux->info;
            N->prox = NULL;

            auxN = N;
            aux = aux->prox;
        }
        else if(aux->info > aux2->info){

            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3->prox = N;
            else
                auxN->prox = N;

            N->info = aux2->info;
            N->prox = NULL;

            auxN = N;
            aux2 = aux2->prox;
        }
    }

    if(aux == NULL){
        while(aux2 != NULL){
            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3->prox = N;
            else
                auxN->prox = N;

            N->info = aux2->info;
            N->prox = NULL;

            auxN = N;
            aux2 = aux2->prox;
        }
        return li3;
    }

    if(aux2 == NULL){
        while(aux != NULL){
            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3->prox = N;
            else
                auxN->prox = N;

            N->info = aux->info;
            N->prox = NULL;

            auxN = N;
            aux = aux->prox;
        }
        return li3;
    }

    return li3;
}

int iguala_lista(Lista li, Lista li2){

    Lista aux = li->prox;
    Lista aux2 = li2->prox;

    while(aux != NULL && aux2 != NULL){
        if(aux->info != aux2->info)     //percorre a lista, se encontrar elementos diferentes, já fala que elas são diferentes
          return 0;

        aux = aux->prox;
        aux2 = aux2->prox;
    }
        return 1;
}

void limpa_lista(Lista li){
    Lista p ;
    while(li->prox != NULL){
        p = li->prox;
        li->prox = li->prox->prox;
        free(p);
    }
    li->info = 0;
}
