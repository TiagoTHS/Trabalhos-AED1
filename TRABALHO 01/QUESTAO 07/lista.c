/*
Escolha do m�todo para o exerc�cio 7

Nesse exerc�cio, devido a grande quantidade de opea��es de remo��es,
nosso grupo resolveu utilizar o TAD lista din�mica encadeada. E tamb�m, por se tratar
de um grupo de soldados em um circulo, a t�cnica de encadeamento circular � a melhor op��o
para solucionar o problema de Josephus, j� que podemos passar a contagem pelo mesmo elemento
diversas vezes.
*/

#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no {
    char info[MAX];
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

int insere_final(Lista *lst, char *elem){

    Lista N = (Lista)malloc(sizeof(struct no)); // aloca um novo n�
    if(N == NULL){return 0;} // confere se esse foi realmente criado

    strcpy(N->info, elem); // insere o conte�do (valor de elem)

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

    if(t != pos){return 0;}
    else{
        strcpy(n, aux->info); // coloca o nome encontrado na posicao para a variavel n
    }

    return 1;
}

// Altera a posicao inicial (alterando o 'lst' que guarda a posi��o final)
int altera_inicio(Lista *lst, int pos){
    if(lista_vazia(*lst)==1 || pos < 2){return 0;} // confere se a lista esta vazia, e se a posi��o passada � valida

    int t = 1;
    while(pos > t){ // percorrimento da lista at� a posi��o desejada
        *lst = (*lst)->prox; // modifica o endere�o que esta guardado em 'lst', para que a posi��o desejada esteja na primeira posi��o
        pos--;
    }

    return 1;
}

// Altera a posicao inicial (alterando o 'lst' que guarda a posi��o final)
int altera_inicio_nome(Lista *lst, char *n){
    if(lista_vazia(*lst)==1){return 0;}

    Lista aux = (*lst)->prox; // vari�vel auxiliar iniciando no primeiro n�
    Lista aux2 = (*lst);    // vari�vel auxiliar que guarda o n� anterior ao de 'aux'

    while((strcmp(aux->info, n) != 0) && aux != (*lst)){ // percorrimento da lista at� o nome desejado ou at� o final dela
        aux2 = aux;
        aux = aux->prox;
    }

    if(aux == (*lst) && (strcmp(aux->info, n) != 0)){return 0;} // caso chegue ao final da lista e o nome informado n�o � o �ltimo, indicando que o nome n�o est� na lista
    else{
        *lst = aux2; // modifica o endere�o que esta quardado em 'lst', para que o nome desejado esteja na primeira posi��o
    }

    return 1;
}

// remove o soldado da posi��o escolhida e coloca como primeiro n� o soldado a frente do eliminado
int remove_soldado(Lista *lst, int pos, char *elem){
    if(lista_vazia(*lst)==1 || pos < 1 ){return 0;}

    int t = 1;
    while(pos > t){ // percorrimento da lista at� a posi��o desejada
        *lst = (*lst)->prox; // modifica o endere�o que esta quardado em 'lst', para que o soldado ap�s o eliminado esteja na primeira posi��o
        pos--;
    }

    Lista aux = (*lst)->prox; // variavel auxiliar que guarda o endere�o que deve ser liberado
    strcpy(elem, aux->info); // copia o nome do soldado eliminado na variavel n
    (*lst)->prox = aux->prox; // campo prox do n� anterior ao removido, agora aponta para o n� posterior ao removido
    free(aux);  // libera mem�ria ocupada pelo n� removido da lista

    return 1;
}
