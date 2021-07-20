#include <stdlib.h>
#include "filaDinEnc.h"

struct no{
    Pessoa dados;  // Campo dados armazena os dados de cada pessoa
    struct no *prox;  // Campo prox aponta para o pr�ximo n� (sucessor)
};

struct fila{
    struct no *ini;  // Endere�a o primeiro n� da fila
    struct no *fim;  // Endere�a o �ltimo n� da fila
};

Fila cria_fila(){
    Fila f;  // Declara uma nova fila
    f = (Fila) malloc(sizeof(struct fila));  // Aloca todas as posi��es da estrutura fila

    /* Verifica se a fila � diferente de NULL e coloca a fila no estado de vazia
       inicializando os campos ini e fim com NULL*/
    if(f != NULL){
        f->ini = NULL;
        f->fim = NULL;
    }

    return f;
}

int fila_vazia(Fila f){
    // Verifica se a fila est� no estado de vazia (ini = NULL)
    if(f->ini == NULL)
        return 1;  // Fila vazia
    else
        return 0;  // Fila n�o vazia
}

int insere_fim(Fila f, Pessoa p){
    struct no *N;  // Declara um novo n� N
    N = (struct no*) malloc(sizeof(struct no)); //Faz a aloca��o do novo n�

    if(N == NULL)  // Verifica se o n� � NULL (aloca��o n�o funcionou)
        return 0;  //Falha na aloca��o

    N->dados = p;  // O campo info recebe o valor do elemento
    N->prox = NULL;  // O campo prox recebe NULL

    if(fila_vazia(f) == 1)  //Se a fila est� vazia
        f->ini = N;  // O campo ini passa a apontar para o novo n�
    else  // Se a fila possui elementos
        (f->fim)->prox = N;  // O �ltimo n� da fila passa a apontar para o novo n�

    f->fim = N;  // O campo fim aponta para o novo n�

    return 1;
}

int remove_ini(Fila f, Pessoa *p){
    if(fila_vazia(f) == 1)  // Se a fila est� vazia
        return 0;  // Opera��o falha

    // Declara um ponteiro auxiliar que recebe o endere�o do primeiro n� da fila
    struct no *aux = f->ini;  // Aux aponta para o 1� n�
    *p = aux->dados;  // O elemento recebe o valor do n� / Retorna o valor do elemento

    // Se a fila possui um �nico elemento (ini = fim)
    if(f->ini == f->fim)
        f->fim = NULL;  // O campo fim passa a apontar para NULL

    // O campo ini da fila passa a apontar para o sucessor do n� que foi endera�ado por aux
    f->ini = aux->prox;  // Retira o primeiro n� da fila
    free(aux);  // Libera a mem�ria usado pelo n� removido

    return 1;
}

//TAMANHO

//---------------------------
