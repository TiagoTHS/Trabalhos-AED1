/*
Escolha do método para o exercício 7

Nesse exercício, devido a grande quantidade de opeações de remoções,
nosso grupo resolveu utilizar o TAD lista dinâmica encadeada. E também, por se tratar
de um grupo de soldados em um circulo, a técnica de encadeamento circular é a melhor opção
para solucionar o problema de Josephus, já que podemos passar a contagem pelo mesmo elemento
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

    Lista N = (Lista)malloc(sizeof(struct no)); // aloca um novo nó
    if(N == NULL){return 0;} // confere se esse foi realmente criado

    strcpy(N->info, elem); // insere o conteúdo (valor de elem)

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

    if(t != pos){return 0;}
    else{
        strcpy(n, aux->info); // coloca o nome encontrado na posicao para a variavel n
    }

    return 1;
}

// Altera a posicao inicial (alterando o 'lst' que guarda a posição final)
int altera_inicio(Lista *lst, int pos){
    if(lista_vazia(*lst)==1 || pos < 2){return 0;} // confere se a lista esta vazia, e se a posição passada é valida

    int t = 1;
    while(pos > t){ // percorrimento da lista até a posição desejada
        *lst = (*lst)->prox; // modifica o endereço que esta guardado em 'lst', para que a posição desejada esteja na primeira posição
        pos--;
    }

    return 1;
}

// Altera a posicao inicial (alterando o 'lst' que guarda a posição final)
int altera_inicio_nome(Lista *lst, char *n){
    if(lista_vazia(*lst)==1){return 0;}

    Lista aux = (*lst)->prox; // variável auxiliar iniciando no primeiro nó
    Lista aux2 = (*lst);    // variável auxiliar que guarda o nó anterior ao de 'aux'

    while((strcmp(aux->info, n) != 0) && aux != (*lst)){ // percorrimento da lista até o nome desejado ou até o final dela
        aux2 = aux;
        aux = aux->prox;
    }

    if(aux == (*lst) && (strcmp(aux->info, n) != 0)){return 0;} // caso chegue ao final da lista e o nome informado não é o último, indicando que o nome não está na lista
    else{
        *lst = aux2; // modifica o endereço que esta quardado em 'lst', para que o nome desejado esteja na primeira posição
    }

    return 1;
}

// remove o soldado da posição escolhida e coloca como primeiro nó o soldado a frente do eliminado
int remove_soldado(Lista *lst, int pos, char *elem){
    if(lista_vazia(*lst)==1 || pos < 1 ){return 0;}

    int t = 1;
    while(pos > t){ // percorrimento da lista até a posição desejada
        *lst = (*lst)->prox; // modifica o endereço que esta quardado em 'lst', para que o soldado após o eliminado esteja na primeira posição
        pos--;
    }

    Lista aux = (*lst)->prox; // variavel auxiliar que guarda o endereço que deve ser liberado
    strcpy(elem, aux->info); // copia o nome do soldado eliminado na variavel n
    (*lst)->prox = aux->prox; // campo prox do nó anterior ao removido, agora aponta para o nó posterior ao removido
    free(aux);  // libera memória ocupada pelo nó removido da lista

    return 1;
}
