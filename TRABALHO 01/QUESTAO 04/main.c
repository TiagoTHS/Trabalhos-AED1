#include <stdlib.h>
#include "lista.h"

struct no{
    double info;
    struct no * prox;
};
typedef struct no * Lista;


Lista cria_lista(){         //criar o n� cabe�alho
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

    N->info = elem;     //n� N recebe o valor do elem pra ser inserido

    Lista aux = li;     //aux vai pro primeiro elemento

    while (aux->prox != NULL && aux->prox->info < elem) //repete at� chegar ao fim ou o pr�ximo elemento for maior que o que vai ser inserido
        aux = aux->prox;

    N->prox = aux->prox;    //N aponta para onde aux tava apontando
    aux->prox = N;          //aux passa a apontar para N

    li->info++;             //cabe�alho passa a ter um elemento a mais (contando quando itens foram adicionados
    return 1;
}


int remove_elem(Lista li, double elem){
    if (lista_vazia(li)==1)
        return 0;

    Lista aux = li;

    while(aux->prox != NULL && aux->prox->info != elem)    //enquanto n�o chegar ao fim ou achar o elem percorrer a lista
        aux = aux->prox;

    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    Lista aux2 = aux->prox;     //aux2 rebece o aux->prox (elem que vai ser removido)
    aux->prox = aux2->prox;     //aux aponta para o pr�ximo do elem que vai ser removido

    free(aux2);                 //libera o espa�o do aux2
    li->info--;                 //menos um elemento na lista
    return 1;
}

int maior_elem(Lista li){
    Lista aux = li->prox;       //aux aponta para o primeiro n� com elementos da lista
    double maior = 0;

    if(lista_vazia(li)== 1)
        return 0;

    while (aux->prox != NULL){
        aux = aux->prox;        //aux percorre a lista
    }

    if(aux->prox == NULL)
        maior = aux->info;      //como � ordenada o �ltimo elemento � o maior

    return maior;
}

int tamanho_lista(Lista li){
    return li->info;        //tamanho ficou no cabe�alho/primeiro n� da lista --> li->info
}

int obtem_elem(Lista li, int pos, double *elem){

    Lista aux = li->prox;   //aux aponta pro primeiro n� que cont�m elemento da lista
    int j = 0;

    while(aux->prox != NULL && j!= pos){
        aux = aux->prox;    //enquanto n�o achar a posi��o requerida ou at� chegar ao fim, percorre a lista
        j++;                //um contador acompanha a lista marcando quantas posi��es foram
    }

    if(j != pos && aux->prox == NULL)
        return 0;           //se chegar ao fim e n�o achar a posi��o significa que n�o tem mais elemento na posi��o desejada

    if(j == pos)
        * elem = aux->info; //se chegar a posi��o que quer, retorna o elemento dessa posi��o

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
        if(aux->info != aux2->info)     //percorre a lista, se encontrar elementos diferentes, j� fala que elas s�o diferentes
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
