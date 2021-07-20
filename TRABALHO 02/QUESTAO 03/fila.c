#include <stdlib.h>
#include "fila.h"

#define MAX 10


struct fila{
    Cad cadastro[MAX];
    int ini, cont;
};

Fila cria_fila(){
    Fila f = (Fila) malloc (sizeof(struct fila));

    if(f != NULL){
        f->ini = 0;     //inicio, sempre aponta pro primeiro lugar
        f->cont = 0;    //verifica se a lista tá cheia/vazia
    }

    return f;
}

int fila_vazia(Fila f){
    if(f == NULL){
        return -1;
    }
    if(f->cont == 0)
        return 1;
    else
        return 0;
}

int fila_cheia(Fila f){
    if(f->cont == MAX)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, struct cadastro C){
    if(f == NULL)
        return -1;
    if(fila_cheia(f) == 1)
        return 0;

    f->cadastro[(f->ini + f->cont)%MAX] = C;
    f->cont++;

    return 1;
}

int remove_inicio(Fila f, struct cadastro *C){

    if (fila_vazia(f)==1 || f == NULL)
        return 0;

    *C = f->cadastro[f->ini];
    f->ini = (f->ini+1)%MAX;

    f->cont--;

    return 1;
}

int tamanho_fila(Fila f){
    if (f == NULL)
        return -1;

    if(fila_vazia(f)==1)
        return 0;

    return (f->cont);
}

void libera_fila(Fila *f){
    free(*f);
    *f = NULL;
}

int esvazia_fila(Fila f){
    if(fila_vazia(f)==1 || f == NULL)
        return 0;

    f->ini = 0;
    f->cont = 0;
    return 1;
}

int le_topo(Fila f, struct cadastro *C){
	if(f == NULL || fila_vazia(f)==1)
		return 0;

    *C = f->cadastro[f->ini];

    return 1;
}



