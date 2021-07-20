#include <stdlib.h>
#include "lista.h"


struct no{
	Pessoa dados;
	struct no *prox;
};

Lista cria_lista(){
	return NULL;  // Coloca a lista no estado de vazia
}

int lista_vazia(Lista lst){
	// Verifica se a lista está no estado de vazia
	if (lst == NULL)
		return 1;  // Lista vazia
	else
		return 0;  // Lista não vazia
}

int insere_elem(Lista *lst, Pessoa p){
	// Aloca um novo nó
	Lista N = (Lista) malloc(sizeof(struct no));

	if (N == NULL)
		return 0; // Falha: nó não alocado

	// Preenche os campos do novo nó
	N->dados = p; // Insere o conteúdo (valor do elem)
	N->prox = *lst; // Aponta para o 1º nó atual da lista
	*lst = N; // Faz a lista apontar para o novo nó

	return 1;
}

int menor_data(Lista *lst, Pessoa *p){
    if (lista_vazia(*lst) == 1)
		return 0; // Falha

    int dia = 0, mes = 0, ano = 0;

	Lista aux = *lst; // Ponteiro auxiliar para o 1 o nó
    Lista menor = *lst;

    if(menor->dados.local == 3){
        dia = menor->dados.data2.dia;
        mes = menor->dados.data2.mes;
        ano = menor->dados.data2.ano;
    }

	// Percorrimento até achar o elem ou final de lista
	while (aux->prox != NULL){
        if(aux->prox->dados.local == 3){
            if((aux->prox->dados.data2.ano < menor->dados.data2.ano) ||
            (aux->prox->dados.data2.ano == menor->dados.data2.ano && aux->prox->dados.data2.mes < menor->dados.data2.mes) ||
            (aux->prox->dados.data2.ano == menor->dados.data2.ano && aux->prox->dados.data2.mes == menor->dados.data2.mes &&
             aux->prox->dados.data2.dia < menor->dados.data2.dia)){

                dia = aux->prox->dados.data2.dia;
                mes = aux->prox->dados.data2.mes;
                ano = aux->prox->dados.data2.ano;

                menor = aux;
             }

        }

		aux = aux->prox;
    }

    if(dia == 0 && mes == 0 && ano == 0){
        return 0; //Falha
    }

    //Análise do primeiro nó da lista
    if(menor->dados.local == 3 && menor == *lst && (menor->dados.data2.dia == dia) &&
                                                   (menor->dados.data2.mes == mes) &&
                                                   (menor->dados.data2.ano == ano)){
        *p = menor->dados;

        *lst = (*lst)->prox;
        free(menor);
        return 1;
    }

	if (menor->prox == NULL) // Trata final de lista
		return 0; // Falha

    *p = menor->prox->dados;

	// Remove elemento ≠ 1 o nó da lista
	Lista aux2 = menor->prox; // Aponta nó a ser removido
	menor->prox = aux2->prox; // Retira nó da lista
	free(aux2); // Libera memória alocada

	return 1;
}

int maior_idade(Lista *lst, int local, Pessoa *p){
    if (lista_vazia(*lst) == 1)
		return 0; // Falha

    int idade = 0;

	Lista aux = *lst; // Ponteiro auxiliar para o 1 o nó
    Lista maior = *lst; // Ponteiro auxiliar para o 1 o nó

    if(maior->dados.local == local){ // Se o local do primeiro nó = local
        idade = maior->dados.idade;
    }

	// Percorrimento até achar o elem ou final de lista
	while (aux->prox != NULL){
        if(aux->prox->dados.local == local){
            if(aux->prox->dados.idade > idade){
                idade = aux->prox->dados.idade;
                maior = aux; // O maior termina no anterior do maior
             }
        }

		aux = aux->prox;
    }

    if(idade == 0){
        return 0; // Falha: não encontrou ninguem
    }

    //Análise do primeiro nó da lista
    if(maior->dados.local == local && maior == *lst &&  maior->dados.idade == idade ){
        *p = maior->dados;

        *lst = (*lst)->prox;
        free(maior);
        return 1;
    }

    if(maior->prox == NULL){
        return 0;
    }

    //Trata nó diferentes do primeiro nó
    *p = maior->prox->dados;

	// Remove elemento ≠ 1 o nó da lista
	Lista aux2 = maior->prox; // Aponta nó a ser removido
	maior->prox = aux2->prox; // Retira nó da lista
	free(aux2); // Libera memória alocada

	return 1;
}

int obtem_elem(Lista lst, int pos, Pessoa *p){

    if(lista_vazia(lst)== 1){
        return 0;
    }

    Lista aux = lst;   // aux aponta pro primeiro nó que contém elemento da lista
    int j = 0;

    while(aux->prox != NULL && j!= pos){
        aux = aux->prox;    //enquanto não achar a posição requerida ou até chegar ao fim, percorre a lista
        j++;                //um contador acompanha a lista marcando quantas posições foram
    }

    if(j != pos && aux->prox == NULL)
        return 0; // Se chegar ao fim e não achar a posição, não tem mais elemento na posição desejada

    if(j == pos)
        *p = aux->dados; //se chegar a posição desejada, retorna o elemento dessa posição

    return 1;
}

//------------
