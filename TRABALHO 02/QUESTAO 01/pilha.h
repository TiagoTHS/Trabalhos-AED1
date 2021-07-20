#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilha *Pilha;


Pilha cria_pilha();

int pilha_vazia(Pilha p);

int pilha_cheia(Pilha p);

int push(Pilha p, int elem);

int pop(Pilha p, int *elem);

int le_topo(Pilha p, int *elem);

int esvazia_pilha(Pilha p);

void libera_pilha(Pilha *p);

#endif // PILHA_H_INCLUDED
