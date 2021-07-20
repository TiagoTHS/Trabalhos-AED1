#include <stdlib.h>
#include <string.h>
#include "pilhaDinEncad.h"

struct no {
    int tipo;
    union{
        int i_int;
        char i_char;
    }info;
    struct no *prox;
};

Pilha cria_pilha(){
    return NULL;
}

int pilha_vazia(Pilha p){
    if(p == NULL){return 1;}

    return 0;
}

int empilha(Pilha *p, int tipo, int e, char c){
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    N->tipo = tipo;

    if(tipo == 0)
        N->info.i_int = e;
    else
        N->info.i_char = c;

    N->prox = *p;
    *p = N;

    return 1;
}

int desempilha(Pilha *p, int *tipo, int *e, char *c){
    if(pilha_vazia(*p) == 1){return 0;}

    Pilha aux = *p;

    if(aux->tipo == 0){
        *tipo = aux->tipo;
        *e = aux->info.i_int;
    }
    else{
        *tipo = aux->tipo;
        *c = aux->info.i_char;
    }

    *p = aux->prox;
    free(aux);

    return 1;
}

int le_topo(Pilha p, int *tipo, int *e, char *c){
    if(pilha_vazia(p) == 1){return 0;}

    if (p->tipo == 0)
        *e = p->info.i_int;
    else
        *c = p->info.i_char;

    return 1;
}

int esvazia_pilha(Pilha *p){
    if(pilha_vazia(*p)==1){return 0;}

    while((*p) != NULL){
        Pilha aux = *p;
        (*p) = (*p)->prox;
        free(aux);
    }

    return 1;
}
