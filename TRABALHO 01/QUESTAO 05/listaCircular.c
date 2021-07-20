#include <stdlib.h>
#include "listaCircular.h"

struct no {
    char info;
    struct no *prox;
};

Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista lst){
    if(lst == NULL)
        return 1;
    return 0;
}

int insere_final(Lista *lst, char elem){

    Lista N = (Lista)malloc(sizeof(struct no)); // aloca um novo n�
    if(N == NULL){return 0;} // confere se esse foi realmente criado

    N->info = elem; // Insere o conte�do (valor de elem)

    if(lista_vazia(*lst)==1){ // caso de inser��o na lista vazia
        N->prox = N;
        *lst = N;
    }
    else{ // caso de inser��o na lista n�o vazia
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }

    return 1;
}

int remove_inicio(Lista *lst, char *elem){
    if(lista_vazia(*lst)==1){return 0;}

    Lista aux = (*lst)->prox; // vari�vel auxiliar que guarda o endere�o do primeiro n�
    *elem = aux->info; // coloca o character do primeiro n� na variavel n

    if((*lst) == (*lst)->prox) // caso a lista tenha um �nico elemento
        *lst = NULL;
    else
        (*lst)->prox = aux->prox; // campo prox do n� anterior ao removido, agora aponta para o n� posterior ao removido

    free(aux); // libera mem�ria ocupada pelo n� removido da lista
    return 1;
}

int tamanho(Lista lst){
    if(lista_vazia(lst)==1){return 0;}

    Lista aux = lst->prox; // vari�vel auxiliar iniciando no primeiro n�
    int t = 1;
    while(aux != lst){ // percorrimento da lista at� o final dela
        aux = aux->prox;
        t++;
    }

    return t; // retorna o tamanho da lista
}

int get_posicao(Lista lst, int pos, char *n){
    if(lista_vazia(lst)==1 || pos < 1 ){return 0;} // confere se a lista esta vazia, e se a posi��o passada � valida

    Lista aux = lst->prox; // vari�vel auxiliar iniciando no primeiro n�
    int t = 1;
    while(aux != lst && pos > t){ // percorrimento da lista at� a posi��o desejada ou at� o final dela
        aux = aux->prox;
        t++;
    }

    if(t != pos){return 0;} // caso chegue ao final da lista e a posi��o desejada n�o seja a �ltima
    else{
        *n = aux->info; // coloca o character encontrado na posicao para a variavel n
    }

    return 1;
}

int remove_final(Lista *lst, char *n){
    if(lista_vazia(*lst)==1 || lst == NULL){return 0;}

    if((*lst) == (*lst)->prox){ // caso a lista tenha um unico elemento
        *n = (*lst)->info;
        free((*lst));
        *lst = NULL;
        return 1;
    }

    Lista aux = *lst; // vari�vel auxiliar

    while(aux->prox != (*lst)){ // percorre a lista at� a pen�ltima posi��o
        aux = aux->prox;
    }

    *n = aux->prox->info; // coloca o character da �ltima posicao na vari�vel n
    aux->prox = (*lst)->prox; // campo prox do n� anterior ao removido, agora aponta para o n� posterior ao removido
    free((*lst)); // libera mem�ria ocupada
    *lst = aux; // modifica o endere�o do �ltimo n� para o antigo pen�ltimo
    return 1;
}

int insere_inicio(Lista *lst, char elem){

    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    N->info = elem; // Insere o conte�do (valor de elem)

    if(lista_vazia(*lst)==1){ // caso de inser��o na lista vazia
        N->prox = N;
        *lst = N;
    }
    else{ // caso de inser��o na lista n�o vazia
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
    }

    return 1;
}

int insere_posicao(Lista *lst, int pos, char elem){
    if(pos < 1){return 0;}

    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    N->info = elem;

    if(lista_vazia(*lst)==1){ // caso a lista esteja vazia
        if (pos == 1){ // caso a posi��o pedida seja 1 quando a lista est� vazia
            N->prox = N;
            *lst = N;
            return 1;
        }
        else
            return 0;
    }

    Lista aux = (*lst)->prox;
    Lista aux2 = *lst; // guarda o endere�o do n� anterior ao aux

    int t = 1;
    while(aux != (*lst) && pos > t){ // percorre a lista at� a posi��o desejada ou at� o final dela
        aux2 = aux;
        aux = aux->prox;
        t++;
    }

    if(pos == t+1){ // caso a posi��o pedida seja a posi��o = tamanho + 1 (inserir no final da lista)
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
        return 1;
    }

    if(t != pos){return 0;} // caso chegue ao final da lista e a posi��o desejada n�o seja a �ltima
    else{
        aux2->prox = N;
        N->prox = aux;
    }

    return 1;
}

int remove_posicao(Lista *lst, int pos, char *elem){
    if(pos < 1 || lista_vazia(*lst)==1){return 0;}

    Lista aux = (*lst)->prox;
    Lista aux2 = (*lst); // guarda o endere�o do no anterior ao aux

    int t = 1;
    while(aux != (*lst) && pos > t){ // percorre a lista at� a posi��o desejada ou at� o final dela
        aux2 = aux;
        aux = aux->prox;
        t++;
    }

    if(t != pos){return 0;} // caso chegue ao final da lista e a posi��o desejada n�o seja a �ltima
    else if (aux == (*lst)){ // caso chegue ao final da lista e a posi��o desejada seja a �ltima
        *elem = aux->info;
        *lst = aux2;
        aux2->prox = aux->prox;
        free(aux);
        return 1;
    }
    else{
        *elem = aux->info;
        aux2->prox = aux->prox;
        free(aux);
        return 1;
    }

    return 1;
}
