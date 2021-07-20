#include <stdlib.h>
#include "pilha.h"

#define MAX 50

struct pilha{
    int vetor[MAX];
    int topo;
};

// CRIA PILHA
Pilha cria_pilha(){
    Pilha p;

    p = (Pilha)malloc(sizeof(struct pilha));

    if(p != NULL)
        p->topo = -1;

    return p;
}

// PILHA VAZIA
int pilha_vazia(Pilha p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

// PILHA CHEIA
int pilha_cheia(Pilha p){
    if(p->topo == MAX-1)
        return 1;
    else
        return 0;
}

// PUSH
int push(Pilha p, int elem){
    if (p == NULL || pilha_cheia(p) == 1)
        return 0;

    // Insere o elemento no topo
    p->topo++;
    p->vetor[p->topo] = elem;

    return 1;
}

// POP
int pop(Pilha p, int *elem){
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;

    *elem = p->vetor[p->topo]; // Retorna o elemento
    p->topo--;	// Remove o elemento do topo

    return 1;
}

// LE TOPO
int le_topo(Pilha p, int *elem){
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;

    *elem = p->vetor[p->topo]; // Retorna o elemento

    return 1;
}

// ESVAZIA PILHA
int esvazia_pilha(Pilha p){

    if(p == NULL)
        return 0; // Falha

    p->topo = -1;
    return 1; // Sucesso
}

// LIBERA PILHA
void libera_pilha(Pilha *p){
    free(*p); // Libera pilha
    (*p) = NULL; // Coloca como NULL por precaução
}
