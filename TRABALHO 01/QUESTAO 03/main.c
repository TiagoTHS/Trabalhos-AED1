#include <stdlib.h>
#include "lista.h"

struct no{
    int info;
    struct no * prox;
};


Lista cria_lista(){
    return NULL;
}

int lista_vazia(Lista li){
    if (li == NULL)
        return 1;
    else
        return 0;
}

int insere_elem(Lista *li, int elem){
    Lista N = (Lista) malloc (sizeof(struct no));
    if(N == NULL)
        return 0;

    N->info = elem;

    if (lista_vazia(*li) || elem <= (*li)->info){  //se lista vazia ou o elemento inserido for menor que o 1o elem da lista
        N->prox = *li;   // novo elem aponta para onde a lista apontava (se vazia para NULL ou para outro elemento com valor maior)
        *li = N;         // a lista aponta para o novo elemento
        return 1;
    }

    Lista aux = *li;  //aux para primeiro elem da lista

    while (aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox; //se o próximo for NULL ou o próximo elemento for maior que o inserido, para de percorrer

    N->prox = aux->prox;  // seja pq chegou em NULL ou o próximo elem é maior, o inserido aponta para onde o aux apontava
    aux->prox = N; //o aux aponta agora pro elemento que foi inserido na sua frente

    return 1;
}

int remove_elem(Lista *li, int elem){
    if(lista_vazia(*li)==1 || elem < (*li)->info) //se o elem for menor que o primeiro, ele não tá na lista
        return 0;

    Lista aux = *li;

    if(elem == (*li)->info){ //se for logo o primeiro na lista
        *li = aux->prox; // lista passa a apontar ao seguinte do aux

        free(aux); // libera a posição do aux
        return 1;
    }

    while(aux->prox != NULL && aux->prox->info != elem)  // o aux percorre a lista enquanto não achar o elemento ou até acabar ela
        aux = aux->prox;

    if(aux->prox == NULL || aux->prox->info > elem)  // elem não tá na lista, já percorreu ela toda e não achou
        return 0;

    Lista aux2 = aux->prox; // um aux2 aponta para o elemento que vai ser retirado, aux->prox
    aux->prox = aux2->prox; // aux passa apontar pro próximo do que vai ser eliminado

    free(aux2);  //libera aux2
    return 1;
}

int maior_elem(Lista *li){

    Lista aux = *li;
    int maior = 0;

    if(lista_vazia(*li)== 1)
        return 0;

    while (aux->prox != NULL){ //percorre a lista até o fim
        aux = aux->prox;
    }

    if(aux->prox == NULL) // é uma lista ordenada, então o último elemento é sempre o maior
        maior = aux->info;

    return maior;

}

Lista intercala_lista(Lista *li, Lista *li2){
    if (lista_vazia(*li) == 1 || lista_vazia(*li2)==1)
        return 0;

    Lista aux = *li;
    Lista aux2 = *li2;

    Lista li3 = NULL;
    Lista auxN = li3;  //auxN acompanha a inserção na L3


    while (aux != NULL && aux2 != NULL){   //enquanto nenhuma das duas chegar a NULL

        if(aux->info <= aux2->info){       // L1 menor que L2
            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3 = N;          //se lista vazia L3 aponta pra N
            else
                auxN->prox = N;   //auxN (último nó da L3) aponta pra N

            N->info = aux->info;  //N recebe o valor da L1
            N->prox = NULL;       //fim da lista, então N aponta pra null

            auxN = N;             //auxN vai pro final da lista
            aux = aux->prox;
        }
        else if(aux->info > aux2->info){   //se L1 for maior L2

            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3 = N;          //L3 começa apontando pra N
            else
                auxN->prox = N;   //auxN (ultimo nó de L3) aponta pra N

            N->info = aux2->info; //N recebe o valor de aux2 (se aux é maior que aux2, então aux2 vai primeiro)
            N->prox = NULL;       //último elem entao aponta pra null

            auxN = N;             //auxN vai pro último elemento
            aux2 = aux2->prox;
        }
    }

    if(aux == NULL){           //se L1 acabar e L2 não
        while(aux2 != NULL){
            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3 = N;           //L3 aponta para N
            else
                auxN->prox = N;    //último elem da lista aponta pra N

            N->info = aux2->info;  //só resta aux2, entao N recebe o valor de aux2
            N->prox = NULL;

            auxN = N;
            aux2 = aux2->prox;     //segue em aux2 até terminar a L2
        }
        return li3;
    }

    if(aux2 == NULL){          //se L2 acabar e L1 não
        while(aux != NULL){
            Lista N = (Lista) malloc (sizeof(struct no));
            if (N == NULL)
                return 0;

            if(lista_vazia(li3)==1)
                li3 = N;           //L3 aponta para N
            else
                auxN->prox = N;    //último elem da lista aponta pra N


            N->info = aux->info;  //só resta aux2, entao N recebe o valor de aux1
            N->prox = NULL;

            auxN = N;
            aux = aux->prox;     //segue em aux2 até terminar a L2
        }
        return li3;
    }

    return li3;
}

int iguala_lista(Lista li, Lista li2){

    Lista aux = li;
    Lista aux2 = li2;

    while(aux != NULL && aux2 != NULL){   //anda com os nós enquanto não chegar ao fim
        if(aux->info != aux2->info)   //se algum elemento for diferente do outro, não são iguais, return 0
          return 0;

        aux = aux->prox;
        aux2 = aux2->prox;
    }

        return 1;
}


int obtem_elem(Lista li, int pos, int *elem){

    Lista aux = li;
    int j = 0;

    while(aux->prox != NULL && j!= pos){   //enquanto não chegar ao fim da lista e não encontrar a posição, percorre a lista
        aux = aux->prox;
        j++;
    }

    if(j != pos && aux->prox == NULL) //chegou ao fim e não encontrou o elemento, ele não tá na lista
        return 0;

    if(j == pos)
        *elem = aux->info;  //se encontra a posição que quer, devolve o elemento da posição

    return 1;
}

int tamanho_lista(Lista li){
	if(li == NULL)
		return 0;

    Lista aux = li;
	int i = 0;

    while(aux != NULL){   //enquanto não for o fim vai contando os nós
        aux = aux->prox;
        i++;
    }

    return i; //tamanho da lista
}

void limpa_lista(Lista* li){
    Lista aux;

    while(*li != NULL){
        aux = *li;   // auxiliar aponta pro primeiro elemento
        *li = (*li)->prox; // o primeiro passa a ser o próximo do primeiro elemento
        free(aux); //libera aux
    }
}



