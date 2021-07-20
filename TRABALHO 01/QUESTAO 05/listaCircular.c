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

    Lista N = (Lista)malloc(sizeof(struct no)); // aloca um novo nó
    if(N == NULL){return 0;} // confere se esse foi realmente criado

    N->info = elem; // Insere o conteúdo (valor de elem)

    if(lista_vazia(*lst)==1){ // caso de inserção na lista vazia
        N->prox = N;
        *lst = N;
    }
    else{ // caso de inserção na lista não vazia
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }

    return 1;
}

int remove_inicio(Lista *lst, char *elem){
    if(lista_vazia(*lst)==1){return 0;}

    Lista aux = (*lst)->prox; // variável auxiliar que guarda o endereço do primeiro nó
    *elem = aux->info; // coloca o character do primeiro nó na variavel n

    if((*lst) == (*lst)->prox) // caso a lista tenha um único elemento
        *lst = NULL;
    else
        (*lst)->prox = aux->prox; // campo prox do nó anterior ao removido, agora aponta para o nó posterior ao removido

    free(aux); // libera memória ocupada pelo nó removido da lista
    return 1;
}

int tamanho(Lista lst){
    if(lista_vazia(lst)==1){return 0;}

    Lista aux = lst->prox; // variável auxiliar iniciando no primeiro nó
    int t = 1;
    while(aux != lst){ // percorrimento da lista até o final dela
        aux = aux->prox;
        t++;
    }

    return t; // retorna o tamanho da lista
}

int get_posicao(Lista lst, int pos, char *n){
    if(lista_vazia(lst)==1 || pos < 1 ){return 0;} // confere se a lista esta vazia, e se a posição passada é valida

    Lista aux = lst->prox; // variável auxiliar iniciando no primeiro nó
    int t = 1;
    while(aux != lst && pos > t){ // percorrimento da lista até a posição desejada ou até o final dela
        aux = aux->prox;
        t++;
    }

    if(t != pos){return 0;} // caso chegue ao final da lista e a posição desejada não seja a última
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

    Lista aux = *lst; // variável auxiliar

    while(aux->prox != (*lst)){ // percorre a lista até a penúltima posição
        aux = aux->prox;
    }

    *n = aux->prox->info; // coloca o character da última posicao na variável n
    aux->prox = (*lst)->prox; // campo prox do nó anterior ao removido, agora aponta para o nó posterior ao removido
    free((*lst)); // libera memória ocupada
    *lst = aux; // modifica o endereço do último nó para o antigo penúltimo
    return 1;
}

int insere_inicio(Lista *lst, char elem){

    Lista N = (Lista)malloc(sizeof(struct no));
    if(N == NULL){return 0;}

    N->info = elem; // Insere o conteúdo (valor de elem)

    if(lista_vazia(*lst)==1){ // caso de inserção na lista vazia
        N->prox = N;
        *lst = N;
    }
    else{ // caso de inserção na lista não vazia
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
        if (pos == 1){ // caso a posição pedida seja 1 quando a lista está vazia
            N->prox = N;
            *lst = N;
            return 1;
        }
        else
            return 0;
    }

    Lista aux = (*lst)->prox;
    Lista aux2 = *lst; // guarda o endereço do nó anterior ao aux

    int t = 1;
    while(aux != (*lst) && pos > t){ // percorre a lista até a posição desejada ou até o final dela
        aux2 = aux;
        aux = aux->prox;
        t++;
    }

    if(pos == t+1){ // caso a posição pedida seja a posição = tamanho + 1 (inserir no final da lista)
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
        return 1;
    }

    if(t != pos){return 0;} // caso chegue ao final da lista e a posição desejada não seja a última
    else{
        aux2->prox = N;
        N->prox = aux;
    }

    return 1;
}

int remove_posicao(Lista *lst, int pos, char *elem){
    if(pos < 1 || lista_vazia(*lst)==1){return 0;}

    Lista aux = (*lst)->prox;
    Lista aux2 = (*lst); // guarda o endereço do no anterior ao aux

    int t = 1;
    while(aux != (*lst) && pos > t){ // percorre a lista até a posição desejada ou até o final dela
        aux2 = aux;
        aux = aux->prox;
        t++;
    }

    if(t != pos){return 0;} // caso chegue ao final da lista e a posição desejada não seja a última
    else if (aux == (*lst)){ // caso chegue ao final da lista e a posição desejada seja a última
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
