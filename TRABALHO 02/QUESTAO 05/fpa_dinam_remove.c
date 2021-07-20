#include <stdlib.h>
#include "fpa_dinam_remove.h"

struct no{
    Aluno info;
    struct no * prox;
};

struct fila{
    struct no * ini;
    struct no * fim;
};

Fila cria_fila(){
    Fila f;

    f = (Fila) malloc(sizeof(struct fila));

    if (f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }

    return f;
}

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;
    else
        return 0;
}

int insere_fim(Fila f, struct aluno A){
    struct no * N;

    N = (struct no *) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->info = A; // Preenche campo info
    N->prox = NULL; // Preenche campo prox

    if (fila_vazia(f) == 1)
        f->ini = N; // Se fila vazia

    else
        (f->fim)->prox = N; // Se fila com elementos (NÃO vazia)

    f->fim = N; // Campo fim aponta para N

    return 1;
}

int remove_ord(Fila f, struct aluno *A){

     if(fila_vazia(f) == 1){
          return 0;
     }

     struct no *anterior = NULL;
     struct no *atual = f->ini;
     struct no *aux = f->ini;

     while(aux->prox != NULL){

          if(atual->info.ano > aux->prox->info.ano){
               anterior = aux;
               atual = aux->prox;
          }

          aux = aux->prox;
     }

     // Cópia dos dados para Aluno A
     (*A) = atual->info;

     // Se anterior = NULL, significa que o menor é o primeiro nó
     // Se f->ini = f->fim, a lista só tem 1 elemento
     if(anterior == NULL && f->ini == f->fim){
          f->ini = NULL;
          f->fim = NULL;
     }

     // Se anterior = NULL, significa que o menor é o primeiro nó
     // Se f->ini != f->fim, nesse caso a lista contém mais de 1 elemento
     else if(anterior == NULL && f->ini != f->fim){
          f->ini = f->ini->prox;
     }

     // Se atual->prox = NULL, significa que o menor é a última posição da fila
     // Se f->ini != f->fim, a fila contém mais de 1 elemento
     // O caso em que só tem 1 elemento é tratado no 1º if
     else if(atual->prox == NULL && f->ini != f->fim){
          f->fim = anterior;
          f->fim->prox = NULL;
     }

     // Caso o elemento se encontre no meio da fila
     else{
          anterior->prox = atual->prox;
     }

     free(atual); // ELIMINA O NÓ

     return 1; // Sucesso

}

int get_pos(Fila f, int pos, struct aluno *A){
    if(fila_vazia(f)==1 || pos < 0)
        return 0;

    int i = 0;
    struct no *aux = f->ini;

    while(aux->prox != NULL && pos > i){
        aux = aux->prox;
        i++;
    }

    if(pos != i)
        return 0;
    else
        *A = aux->info;

    return 1;
}

int esvazia_fila(Fila f){

    if(fila_vazia(f) == 1)
        return 1;

    struct no * aux;

    while(f->ini != NULL){
        aux = f->ini;
        f->ini = f->ini->prox; // Esvaziando pelo início
        free(aux);
    }

    f->fim = NULL;

    return 1;
}

void libera_fila(Fila *f){

    struct no * aux;

    while((*f)->ini != NULL){
        aux = (*f)->ini;
        (*f)->ini = (*f)->ini->prox;
        free(aux);
    }

    (*f)->fim = NULL;
    free(*f);
    *f = NULL;
}
