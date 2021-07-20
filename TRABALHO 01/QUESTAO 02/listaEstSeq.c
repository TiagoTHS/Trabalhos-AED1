#include <stdlib.h>
#include "listaEstSeq.h"

struct lista{
    char no[MAX];
    int Fim;
};

//Cria uma nova lista
Lista cria_lista(){
    Lista lst;
    lst = (Lista) malloc(sizeof(struct lista));

    if (lst != NULL)
        lst->Fim = 0; // Lista vazia

    return lst;
}

//Verifica se a lista é vazia
int lista_vazia(Lista lst){
    if (lst->Fim == 0)
        return 1; // Lista vazia
    else
        return 0; // Lista NÃO vazia
}

//Verifica se a lista está cheia
int lista_cheia(Lista lst){
    if (lst->Fim == MAX)
        return 1; // Lista cheia
    else
        return 0; // Lista NÃO cheia
}

//Insere um elemento de forma ordenada (descrescente)
int insere_ord(Lista lst, char elem){
    //Verifica se a lista é NULL ou está cheia
    if (lst == NULL || lista_cheia(lst) == 1)
        return 0; // Falha se True

    // Trata lista vazia ou elemento <= último da lista
    if (lista_vazia(lst) == 1 || (int)elem <= lst->no[lst->Fim-1]){
        lst->no[lst->Fim] = elem; // Insere no final
    } else{
        int i, aux = 0;
        while((int)elem <= lst->no[aux]) // Percorrimento da lista
            aux++;
        for (i = lst->Fim; i > aux; i--) // Deslocamento
            lst->no[i] = lst->no[i-1];
       lst->no[aux] = elem; // Inclui o elemento na lista
    }

    lst->Fim++; // Avança o Fim
    return 1; // Sucesso
}

//Remove um determinado elemento da lista
int remove_ord (Lista lst, char elem){
    if (lst == NULL || lista_vazia(lst) == 1 || (int)elem > lst->no[0] || (int)elem < lst->no[lst->Fim-1])
        return 0; // Falha

    int i, Aux = 0;

    // Percorre até achar o elem ou nó maior, ou final de lista
    while (Aux < lst->Fim && lst->no[Aux] > (int)elem)
        Aux++;

    if (Aux == lst->Fim || lst->no[Aux] < (int)elem) // Não existe elemento
        return 0; // Falha

    // Deslocamento à esq. do sucessor até o final da lista
    for (i = Aux+1; i < lst->Fim; i++)
         lst->no[i-1] = lst->no[i];

    lst->Fim--; // Decremento do campo Fim
    return 1; // Sucesso
}

//Obtem um elemento da lista dada sua posição
int get_pos(Lista lst, int pos, char *elem){
	if(lista_vazia(lst)== 1 || lst == NULL || pos < 0 || pos >= lst->Fim)
		return 0;

	*elem = lst->no[pos];
	return 1;
}

//Esvazia a lista
void esvaziar_lista(Lista lst){
    free(lst);
    lst = cria_lista();
}

//Verifica qual o menor elemento da lista
int menor_valor(Lista lst){
    int i = 0;
    int menor = lst->no[i]; //O menor valor recebe o primeiro nó da lista

    for(i = 1; i < lst->Fim; i++){ //Percorre a lista
        if(menor > lst->no[i]) //Verifica se o proximo nó é o menor elemento
            menor = lst->no[i];
    }

    return menor;
}

//Verifica o tamanho da lista (quantidade de elementos)
int tamanho_lista(Lista lst){
	if(lst == NULL){
		return -1;
	} else {
		return lst->Fim;
	}
}

//Remove os elementos pares da lista
int remove_pares(Lista lst){
    int i, j;

    //Verifica se a lista é vazia ou NULL
    if(lista_vazia(lst) == 1 || lst == NULL)
        return 0; //Falha

    for(i = 0; i < lst->Fim; i++){
        if(lst->no[i] % 2 == 0){
            for(j = i+1; j < (lst->Fim); j++){
                lst->no[j-1] = lst->no[j];
            }
            lst->Fim--; //Decrementa o final da lista
            i--;
        }
    }

    return 1;
}

//Intercala duas listas e retorna uma terceira
int intercalar_lista(Lista lst1, Lista lst2, Lista lst3){
    int pos = 0, i = 0, j = 0;

    //Verifica se ambas as listas são iguais a NULL
    if (lst1 == NULL && lst2 == NULL)
        return 0; // Falha
    //Caso só uma seja NULL, lista 3 é igual a lista com elementos.
    else if(lst1 == NULL)
        lst3 = lst2;
    else if(lst2 == NULL)
        lst3 = lst1;

    //Percorre a lista enquanto o primeiro nó das listas não for o último nó e a posição for menor que MAX
    while((lst1->no[i] != lst1->no[lst1->Fim] || lst2->no[j] != lst2->no[lst2->Fim]) && pos < MAX){
        /*Compara as posições i e j da lista 1 e 2, respectivamente,
         e incrementa apenas aquela que for passada para a posição pos da lista 3*/
        if(lst1->no[i] > lst2->no[j]){
            lst3->no[pos] = lst1->no[i];
            i++;
        } else {
            lst3->no[pos]= lst2->no[j];
            j++;
        }
        pos++; //incrementa a posição da lst3
        lst3->Fim++; //incrementa o fim da lst3
    }

    return 1;
}

