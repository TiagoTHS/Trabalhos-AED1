#include <stdlib.h>
#include "fila.h"

#define MAX 20

struct fila{
    Cad cadastro[MAX];
    int ini, cont;
};

Fila cria_fila(){
    Fila f = (Fila) malloc (sizeof(struct fila));

    if(f != NULL){
        f->ini = 0;
        f->cont = 0;
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
    if(f == NULL){
        return -1;
    }
    if(f->cont == MAX)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, struct cadastro C){
    if(f == NULL || fila_cheia(f) == 1)
        return 0;

    //SE A FILA ESTIVER VAZIA -> CADASTRO VAI PRO PRIMEIRO LUGAR VAZIO
    // OU MENOR DE TODOS -> ADICIONA DEPOIS, ENTÃO ADICIONA NORMAL
    if(fila_vazia(f)== 1 || C.grau <= f->cadastro[(f->ini + f->cont -1)%MAX].grau){
        f->cadastro[(f->ini + f->cont)%MAX] = C;
    }

    //SE PRECISAR ADICIONAR NO INICIO -> TEM QUE COLOCAR ELE UMA POSIÇÃO ANTES
    if(C.grau >= f->cadastro[f->ini].grau){
        if(f->ini == 0)
            f->ini = MAX-1;
        else
            f->ini = ((f->ini - 1)%MAX);
        f->cadastro[f->ini] = C;
        f->cont++;
        return 1;
    }

    //AUX DESCOBRE QUAL VAI SER O LUGAR QUE VAI SER ADICIONADO O NOVO ELEMENTO
    //J CALCULA QUANTOS ELEMENTOS TEM ANTES DO LUGAR QUE VAI SER ADICIONADO O NOVO ELEMENTO
    int i, j = 0;
    int aux = f->ini;
    while(C.grau <= f->cadastro[aux].grau && aux != ((f->ini + f->cont - 1)%MAX)){
        aux = ((aux + 1)%MAX);
        j++;
    }

    //SE TEM ELEMENTOS DOS DOIS LADOS É PRA INSERIR ENTRE DOIS NÚMEROS
    //DEPOIS DE ANDAR COM TODOS QUE SÃO MENORES, O NÚMERO É ADICIONADO NO LUGAR DO AUX
    if(C.grau >= f->cadastro[(aux)%MAX].grau ){
        for(i=0; i<=(f->cont - j); i++){ //TEM QUE MOVER TODOS UMA POSIÇÃO PRA FRENTE
            f->cadastro[(f->ini + f->cont - i)%MAX] = f->cadastro[(f->ini + f->cont - 1 - i)%MAX];
        }
        f->cadastro[(aux)%MAX] = C;
    }

    f->cont++;
    return 1;
}

int remove_inicio(Fila f, struct cadastro *C){
    if (f == NULL || fila_vazia(f)==1)
        return 0;

    *C = f->cadastro[f->ini];
    f->ini = (f->ini+1)%MAX;

    f->cont--;

    return 1;
}

int tamanho_fila(Fila f){
    if (f == NULL)
        return -1;

    return (f->cont);
}

int get_pos(Fila f, int pos, struct cadastro *C){
    if(f == NULL || fila_vazia(f)==1 || pos < 0 || pos >= f->cont)
        return 0;


    *C = f->cadastro[(f->ini + pos)%MAX];


    return 1;
}


int esvazia_fila(Fila f){
    if(f == NULL || fila_vazia(f)==1)
        return 0;

    f->ini = 0;
    f->cont = 0;

    return 1;
}

void libera_fila(Fila *f){
    free(*f);
    *f = NULL;
}

