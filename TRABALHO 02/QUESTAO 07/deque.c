#include <stdlib.h>
#include "deque.h"

struct deque{
    int no[MAX];
    int ini, fim;
};

Deque cria_deque(){
    //Declara um novo deque d
    Deque d;

    //Aloca todas as posi��es da estrutura deque
    d = (Deque) malloc(sizeof(struct deque));

    /*Verifica se o deque � diferente de Null e coloca o deque
      no estado de vazio (ini = fim), onde s�o iniciadas com 0*/
    if(d != NULL){
        d->ini = 0;
        d->fim = 0;
    }

    return d;
}

int deque_vazio(Deque d){
    //Verifica se o deque est� no estado de vazio(ini = fim)
    if(d->ini == d->fim)
        return 1;   //Deque vazio
    else
        return 0;   //Deque n�o vazio
}

int deque_cheio(Deque d){
    //Verifica se o deque est� no estado de cheio (ini = fim + 1)
    if(d->ini == (d->fim+1)%MAX)
        return 1;   //Fila Cheia
    else
        return 0;   //Fila n�o cheia
}

int insere_fim(Deque d, int elem){
    //Verifica se o deque est� cheio antes da inser��o
    if(deque_cheio(d) == 1)
        return 0;    //Falha na inser��o

    //Insere o elemento no final do deque
    d->no[d->fim] = elem; //O vetor na posi��o fim recebe o elemento
    d->fim = (d->fim+1)%MAX; //Incrementa o fim do deque de forma circular

    return 1;
}

int remove_ini(Deque d, int *elem){
    //Verifica se o deque est� vazio antes da remo��o
    if(deque_vazio(d) == 1)
        return 0;   //Falha na remo��o

    //Remove o elemento no in�cio do deque
    *elem = d->no[d->ini]; //O elemento recebe o elemento no in�cio do deque
    d->ini = (d->ini+1)%MAX;  //Incrementa o in�cio do deque de forma circular

    return 1;
}

int insere_ini(Deque d, int elem){
    //Verifica se o deque est� cheio antes da inser��o
    if(deque_cheio(d) == 1)
        return 0;    //Falha na inser��o

    //Insere o elemento no in�cio da fila
    d->ini = (d->ini-1)%MAX;  //Decrementa o in�cio do deque de forma circular
    d->no[d->ini] = elem; //O vetor na posi��o ini recebe o elemento


    return 1;
}

int remove_fim(Deque d, int *elem){
    //Verifica se o deque est� vazia antes da remo��o
    if(deque_vazio(d) == 1)
        return 0;   //Falha na remo��o

    //Remove o elemento no final do deque

    *elem = d->no[(d->fim)]; //O elemento recebe o elemento no final da fila
    d->fim = (d->fim-1)%MAX;  //Decrementa o fim do deque de forma circular


    return 1;
}

void apagar_deque(Deque *d){
    free(*d);
    *d = NULL;
}

//--------------------
