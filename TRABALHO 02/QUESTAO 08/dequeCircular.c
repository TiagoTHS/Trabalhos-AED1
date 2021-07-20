#include <stdlib.h>
#include "dequeCircular.h"

struct no {
    char info;
    struct no *prox;
    struct no *ant;
};

Deque cria_deque(){
    return NULL;
}

int deque_vazio(Deque d){
    if(d == NULL)
        return 1;
    return 0;
}

int insere_final(Deque *d, char elem){

    Deque N = (Deque)malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    N->info = elem;

    if(deque_vazio(*d)==1){
        N->prox = N;
        N->ant = N;
    }
    else{
        N->prox = (*d)->prox;
        N->ant = *d;
        (*d)->prox = N;
    }

    *d = N;

    return 1;
}

int remove_inicio(Deque *d, char *elem){
    if(deque_vazio(*d)==1){return 0;}

    Deque aux = (*d)->prox;
    *elem = aux->info;

    // caso o deque tenha apenas 1 elemento
    if((*d) == (*d)->prox)
        *d = NULL;
    else{
        (*d)->prox = aux->prox;
        aux->prox->ant = *d;
    }

    free(aux);
    return 1;
}

int remove_final(Deque *d, char *elem){
    if(deque_vazio(*d)==1){return 0;}

    *elem = (*d)->info;

    // caso o deque tenha apenas 1 elemento
    if((*d) == (*d)->prox){
        free((*d));
        *d = NULL;
        return 1;
    }

    Deque aux = (*d)->ant;

    aux->prox = (*d)->prox;
    (*d)->prox->ant = aux;
    free((*d));
    *d = aux;

    return 1;
}

int insere_inicio(Deque *d, char elem){

    Deque N = (Deque)malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    N->info = elem;

    if(deque_vazio(*d)==1){
        N->prox = N;
        N->ant = N;
        *d = N;
    }
    else{
        N->prox = (*d)->prox;
        N->ant = *d;
        (*d)->prox = N;
        (*d)->prox->ant = N;
    }

    return 1;
}

int apaga_deque(Deque *d){
    if(deque_vazio(*d)==1){
        free(*d);
        return 1;
    }

    Deque aux = *d;

    while((*d) != (*d)->prox){
        aux = aux->prox;
        free(aux);
    }

    free(*d);

    return 1;
}

int get_posicao(Deque d, int pos, char *elem){
    if(deque_vazio(d)==1 || pos < 1 || d == NULL){return 0;}

    Deque aux = d->prox;
    int t = 1;
    while(aux != d && pos > t){
        aux = aux->prox;
        t++;
    }

    if(t != pos){return 0;}
    else{
        *elem = aux->info;
        return 1;
    }

    return 1;
}
