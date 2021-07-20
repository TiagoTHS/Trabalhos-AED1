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

    // Aloca um novo n� e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL){ return 0; } // Falha: n� n�o alocado

    N->info = elem; // Insere o conte�do (valor do elem)
    N->ant = NULL; // N�o tem antecessor do novo n�
    N->prox = *lst; // Sucessor do novo n� recebe mesmo end. da lista

    if (lista_vazia(*lst) == 0) // Se lista N�O vazia
        (*lst)->ant = N; // Faz o antecessor do 1o n� ser o novo n�

    *lst = N; // Faz a lista apontar para o novo n�
    return 1;
}

// REMOVER ELEMENTOS
int remove_elem(Lista *lst, int elem){
    if (lista_vazia(*lst)) // Trata lista vazia
        return 0;

    Lista aux = *lst; // Faz aux apontar para 1o n�

    while (aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if (aux->info != elem)
        return 0; // Elemento n�o est� na lista

    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant; // Sucessor do n� aponta pro anterior

    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox; // Antecessor do n� aponta pro sucessor

    if (aux == *lst)
        *lst = aux->prox;

    free(aux);
    return 1;
}

// REMOVER TODAS AS OCORR�NCIAS DE UM ELEMENTO
int remove_todos(Lista *lst, int elem){
    if (lista_vazia(*lst)) // Trata lista vazia
        return 0;

    Lista aux = *lst; // Faz aux apontar para 1o n�
    Lista teste = *lst; // Faz teste apontar para 1o n�
    int cont = 0; // Para saber qnts vezes o elemento foi removido

    while (aux != NULL){

        if(aux->info == elem){

            // Primeiro e �nico n�
            if(aux->ant == NULL && aux->prox == NULL){

                free(aux);
                (*lst) = NULL; // Coloca lista como vazia
                aux = NULL; // Coloca aux = NULL para sair do while
                cont++; // Avan�a cont

            }

            // Primeiro n� e lista com mais de um elemento
            else if(aux->ant == NULL && aux->prox != NULL){

                teste = aux->prox; // Aponta para o prox n�
                teste->ant = NULL; // Aponta a parte ant para NULL

                *lst = teste; // Inicio passa a ser o teste
                free(aux); // Remove o primeiro n�
                aux = *lst;
                cont++;

            }

            // �ltimo n� e lista com mais de um elemento
            else if(aux->ant != NULL && aux->prox == NULL){

                teste = aux->ant; // Aponta para o n� anterior
                teste->prox = NULL; // Aponta a parte prox para NULL e se torna o ultimo n�

                free(aux); // Remove o �ltimo n�
                aux = NULL; // Coloca aux = NULL para sair do while
                cont++;

            }
            else{

                teste = aux->ant; // Aponta para o n� anterior
                teste->prox = aux->prox; // Parte prox aponta para o sucessor de aux

                teste = aux->prox; // Aponta para o n� sucessor
                teste->ant = aux->ant; // Para ant aponta para o antecessor de aux

                free(aux);
                aux = teste;
                cont++;
            }
        }
        else{
            aux = aux->prox; // Avan�a aux
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

    Lista maior = *lst; // Faz maior apontar para 1o n�
    Lista aux = *lst; // Faz maior apontar para 1o n�

    while (aux != NULL){
        if(aux->info > maior->info){
            maior = aux; // Seleciona o maior elemento
        }
        aux = aux->prox; // Avan�a na lista
    }

    // Primeiro e �nico n�
    if(maior->ant == NULL && maior->prox == NULL){

        *elem = maior->info; // Copia o valor para elem
        free(maior); // Libera o n�
        (*lst) = NULL; // Coloca lista como vazia

    }
    // Primeiro n� e lista com mais de um elemento
    else if(maior->ant == NULL && maior->prox != NULL){

        *elem = maior->info; // Copia o valor para elem

        aux = maior->prox; // Coloca aux no 2o elemento da lista
        aux->ant = NULL; // O anterior do 2o elemento aponta para NULL

        *lst = aux; // Atualiza o come�o da lista
        free(maior); // Remove o primeiro n�

    }

    // �ltimo n� e lista com mais de um elemento
    else if(maior->prox == NULL && maior->ant != NULL){

        *elem = maior->info; // Copia o valor para elem

        aux = maior->ant; // Coloca aux no pen�ltimo elemento da lista
        aux->prox = NULL; // O proximo do penultimo elemento aponta para NULL

        free(maior); // Remove o �ltimo n�

    }

    else{

        *elem = maior->info; // Copia o valor para elem
        aux = maior->ant; // Coloca o aux no elemento anterior do maior
        aux->prox = maior->prox; // Faz o pr�ximo apontar para o n� da frente do maior

        aux = maior->prox; // Coloca o aux no pr�ximo elemento do maior
        aux->ant = maior->ant; // Faz o anterior apontar para o n� de tr�s do maior

        free(maior); // Remove o n�

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
            aux = aux->prox; // Avan�a aux
        }while(aux != NULL); // Percorre at� o �ltimo n�
        return qtd;
    }
}

// ESVAZIA LISTA
int esvazia_lista(Lista *lst){

    Lista aux = *lst;

    while ((*lst) != NULL){
        aux = *lst; // Faz aux apontar para 1o n�
        (*lst) = (*lst)->prox; // Avan�a lst
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

// FUN��O VERIFICA PRIMOS SER� USADA NA PRIMOS_LISTA ABAIXO
int verifica_primos(int elemento){

    int i, cont = 0;

    // NO M�XIMO O M�LTIPLO PODE SER N/2
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

// RETORNA UMA LISTA COM N�MEROS PRIMOS DA LISTA ORIGINAL
// UTILIZA A FUN��O VERIFICA PRIMOS ACIMA
Lista primos_lista(Lista lst){

    Lista lst2;
    lst2 = cria_lista();

    Lista aux = lst;
    int elem, resp, flag;

    // Encontra �ltimo n� e marca ele
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    // Come�ando do �ltimo n� e voltando para a lista n�o ficar invertida
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
