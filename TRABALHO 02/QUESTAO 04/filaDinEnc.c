#include <stdlib.h>
#include "filaDinEnc.h"

struct no{
    Pessoa dados;  // Campo dados armazena os dados de cada pessoa
    struct no *prox;  // Campo prox aponta para o próximo nó (sucessor)
};

struct fila{
    struct no *ini;  // Endereça o primeiro nó da fila
    struct no *fim;  // Endereça o último nó da fila
};

Fila cria_fila(){
    Fila f;  // Declara uma nova fila
    f = (Fila) malloc(sizeof(struct fila));  // Aloca todas as posições da estrutura fila

    /* Verifica se a fila é diferente de NULL e coloca a fila no estado de vazia
       inicializando os campos ini e fim com NULL*/
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }

    return f;
}

int fila_vazia(Fila f){
    // Verifica se a fila está no estado de vazia (ini = NULL)
    if(f->ini == NULL)
        return 1;  // Fila vazia
    else
        return 0;  // Fila não vazia
}

int insere_fim(Fila f, Pessoa p){
    struct no *N;  // Declara um novo nó N
    N = (struct no*) malloc(sizeof(struct no)); //Faz a alocação do novo nó

    if(N == NULL)  // Verifica se o nó é NULL (alocação não funcionou)
        return 0;  //Falha na alocação

    N->dados = p;  // O campo info recebe o valor do elemento
    N->prox = NULL;  // O campo prox recebe NULL

    if(fila_vazia(f) == 1)  //Se a fila está vazia
        f->ini = N;  // O campo ini passa a apontar para o novo nó
    else  // Se a fila possui elementos
        (f->fim)->prox = N;  // O último nó da fila passa a apontar para o novo nó

    f->fim = N;  // O campo fim aponta para o novo nó

    return 1;
}

int remove_ini(Fila f, Pessoa *p){
    if(fila_vazia(f) == 1)  // Se a fila está vazia
        return 0;  // Operação falha

    // Declara um ponteiro auxiliar que recebe o endereço do primeiro nó da fila
    struct no *aux = f->ini;  // Aux aponta para o 1º nó
    *p = aux->dados;  // O elemento recebe o valor do nó / Retorna o valor do elemento

    // Se a fila possui um único elemento (ini = fim)
    if(f->ini == f->fim)
        f->fim = NULL;  // O campo fim passa a apontar para NULL

    // O campo ini da fila passa a apontar para o sucessor do nó que foi enderaçado por aux
    f->ini = aux->prox;  // Retira o primeiro nó da fila
    free(aux);  // Libera a memória usado pelo nó removido

    return 1;
}

//TAMANHO

//---------------------------
