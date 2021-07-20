#include <stdlib.h>
#include "listaDuplamEncad.h"

struct no{
    int info;
    struct no * prox;
    struct no * ant;
};

// CRIAR LISTA
Lista cria_lista(){
    return NULL;
}

// VERIFICAR LISTA VAZIA
int lista_vazia(Lista lst){
    if (lst == NULL)
        return 1;
    else
        return 0;
}

// INSERIR ELEMENTOS
int insere_elem(Lista *lst, int elem){

    // Aloca um novo nó e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL){ return 0; } // Falha: nó não alocado

    N->info = elem; // Insere o conteúdo (valor do elem)
    N->ant = NULL; // Não tem antecessor do novo nó
    N->prox = *lst; // Sucessor do novo nó recebe mesmo end. da lista

    if (lista_vazia(*lst) == 0) // Se lista NÃO vazia
        (*lst)->ant = N; // Faz o antecessor do 1o nó ser o novo nó

    *lst = N; // Faz a lista apontar para o novo nó
    return 1;
}

// REMOVER ELEMENTOS
int remove_elem(Lista *lst, int elem){
    if (lista_vazia(*lst)) // Trata lista vazia
        return 0;

    Lista aux = *lst; // Faz aux apontar para 1o nó

    while (aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if (aux->info != elem)
        return 0; // Elemento não está na lista

    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant; // Sucessor do nó aponta pro anterior

    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox; // Antecessor do nó aponta pro sucessor

    if (aux == *lst)
        *lst = aux->prox;

    free(aux);
    return 1;
}

// REMOVER TODAS AS OCORRÊNCIAS DE UM ELEMENTO
int remove_todos(Lista *lst, int elem){
    if (lista_vazia(*lst)) // Trata lista vazia
        return 0;

    Lista aux = *lst; // Faz aux apontar para 1o nó
    Lista teste = *lst; // Faz teste apontar para 1o nó
    int cont = 0; // Para saber qnts vezes o elemento foi removido

    while (aux != NULL){

        if(aux->info == elem){

            // Primeiro e único nó
            if(aux->ant == NULL && aux->prox == NULL){

                free(aux);
                (*lst) = NULL; // Coloca lista como vazia
                aux = NULL; // Coloca aux = NULL para sair do while
                cont++; // Avança cont

            }

            // Primeiro nó e lista com mais de um elemento
            else if(aux->ant == NULL && aux->prox != NULL){

                teste = aux->prox; // Aponta para o prox nó
                teste->ant = NULL; // Aponta a parte ant para NULL

                *lst = teste; // Inicio passa a ser o teste
                free(aux); // Remove o primeiro nó
                aux = *lst;
                cont++;

            }

            // Último nó e lista com mais de um elemento
            else if(aux->ant != NULL && aux->prox == NULL){

                teste = aux->ant; // Aponta para o nó anterior
                teste->prox = NULL; // Aponta a parte prox para NULL e se torna o ultimo nó

                free(aux); // Remove o último nó
                aux = NULL; // Coloca aux = NULL para sair do while
                cont++;

            }
            else{

                teste = aux->ant; // Aponta para o nó anterior
                teste->prox = aux->prox; // Parte prox aponta para o sucessor de aux

                teste = aux->prox; // Aponta para o nó sucessor
                teste->ant = aux->ant; // Para ant aponta para o antecessor de aux

                free(aux);
                aux = teste;
                cont++;
            }
        }
        else{
            aux = aux->prox; // Avança aux
        }
    }

    if(cont == 0){
        return 0;
    }
    else{
        return cont;
    }
}

// REMOVER MAIOR ELEMENTO
int remove_maior_elem(Lista *lst, int *elem){
    if (lista_vazia(*lst)) // Trata lista vazia
        return 0;

    Lista maior = *lst; // Faz maior apontar para 1o nó
    Lista aux = *lst; // Faz maior apontar para 1o nó

    while (aux != NULL){
        if(aux->info > maior->info){
            maior = aux; // Seleciona o maior elemento
        }
        aux = aux->prox; // Avança na lista
    }

    // Primeiro e único nó
    if(maior->ant == NULL && maior->prox == NULL){

        *elem = maior->info; // Copia o valor para elem
        free(maior); // Libera o nó
        (*lst) = NULL; // Coloca lista como vazia

    }
    // Primeiro nó e lista com mais de um elemento
    else if(maior->ant == NULL && maior->prox != NULL){

        *elem = maior->info; // Copia o valor para elem

        aux = maior->prox; // Coloca aux no 2o elemento da lista
        aux->ant = NULL; // O anterior do 2o elemento aponta para NULL

        *lst = aux; // Atualiza o começo da lista
        free(maior); // Remove o primeiro nó

    }

    // Último nó e lista com mais de um elemento
    else if(maior->prox == NULL && maior->ant != NULL){

        *elem = maior->info; // Copia o valor para elem

        aux = maior->ant; // Coloca aux no penúltimo elemento da lista
        aux->prox = NULL; // O proximo do penultimo elemento aponta para NULL

        free(maior); // Remove o último nó

    }

    else{

        *elem = maior->info; // Copia o valor para elem
        aux = maior->ant; // Coloca o aux no elemento anterior do maior
        aux->prox = maior->prox; // Faz o próximo apontar para o nó da frente do maior

        aux = maior->prox; // Coloca o aux no próximo elemento do maior
        aux->ant = maior->ant; // Faz o anterior apontar para o nó de trás do maior

        free(maior); // Remove o nó

    }

    return 1; // Sucesso
}

// TAMANHO LISTA
int tamanho_lista(Lista lst){

    Lista aux = lst;
    int qtd;

    if(lista_vazia(lst) == 1){
        return 0;
    }
    else{
        qtd = 0;
        do{
            qtd++; // Aumenta qtd
            aux = aux->prox; // Avança aux
        }while(aux != NULL); // Percorre até o último nó
        return qtd;
    }
}

// ESVAZIA LISTA
int esvazia_lista(Lista *lst){

    Lista aux = *lst;

    while ((*lst) != NULL){
        aux = *lst; // Faz aux apontar para 1o nó
        (*lst) = (*lst)->prox; // Avança lst
        free(aux);
    }

    *lst = NULL; // Faz lista ser voltar a ser NULL
    return 1; // Sucesso
}

// PARA INVERTER A LISTA
Lista inverte_lista(Lista lst){

    Lista lst2;
    lst2 = cria_lista();

    Lista aux = lst;
    int elem, flag;


    while(aux != NULL){
        elem = aux->info;

        // insere 1 2 3, lista ficou 3 2 1, insere de novo na lista 2 e fica 1 2 3
        flag = insere_elem(&lst2, elem);

        if(flag == 0){
            return NULL; // Falha
        }

        aux = aux->prox;
    }
    return lst2; // Sucesso
}

// FUNÇÃO VERIFICA PRIMOS SERÁ USADA NA PRIMOS_LISTA ABAIXO
int verifica_primos(int elemento){

    int i, cont = 0;

    // NO MÁXIMO O MÚLTIPLO PODE SER N/2
    // EXEMPLO: 19 / 2 = 9 -> 9 * 2 = 18
    for(i = 2; i <= elemento / 2; i++){
        if(elemento % i == 0){
            return 0;
            cont++;
        }
    }
    if(cont == 0){
        return 1;
    }

    return 0;
}

// RETORNA UMA LISTA COM NÚMEROS PRIMOS DA LISTA ORIGINAL
// UTILIZA A FUNÇÃO VERIFICA PRIMOS ACIMA
Lista primos_lista(Lista lst){

    Lista lst2;
    lst2 = cria_lista();

    Lista aux = lst;
    int elem, resp, flag;

    // Encontra último nó e marca ele
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    // Começando do último nó e voltando para a lista não ficar invertida
    while(aux != NULL){

        elem = aux->info;
        resp = verifica_primos(elem);

        if(resp == 1){
            flag = insere_elem(&lst2, aux->info);

            if(flag == 0){
                return NULL; // Falha
            }
        }
        aux = aux->ant; // Volta o aux
    }
    return lst2;
}

//OBTEM VALOR POSICAO
int obtem_valor_elem(Lista lst, int pos, int *elem){

    Lista aux = lst;
    int j = 0;

    while(aux->prox != NULL && j != pos){
        aux = aux->prox;
        j++;
    }

    if(j != pos && aux->prox == NULL)
        return 0; // Falha

    if(j == pos)
        *elem = aux->info;

    return 1; // Sucesso
}

// APAGA LISTA
void apaga_lista(Lista *lst){
    Lista aux;

    if((*lst) != NULL){
        do{
            aux = (*lst);
            (*lst) = (*lst)->prox;
            free(aux);
        }while((*lst) != NULL);
    }
    (*lst) = NULL;
}
