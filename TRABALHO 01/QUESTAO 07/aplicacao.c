/*
Tiago da Silva e Souza Pinto - 12011BCC001
Paulo Vitor Costa Silva - 12011BCC045
Gabriela Santos Damazo - 12011BCC003
Isabelli Prudencio Tedeschi - 12011BCC018
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <time.h>

int inicio(Lista *L);
int pos_al(Lista *L);
int sold_esp(Lista *L);

int main()
{
    Lista L;
    char n[MAX];
    int op;

    L = cria_lista();

    printf(" --- Problema de Josephus ---\n");

    printf("\n- Insercao dos soldados -\n");
    printf("!! Digite 'FIM' quando tiver inserido todos os soldados !!\n\n");

    while(1 == 1){
        printf("Digite o nome do soldado a ser inserido na lista: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", n);
        if(strcmp("FIM", n) == 0)
            break;
        if (insere_final(&L, n)==0){
            printf("\nErro ao adicionar o soldado ao final da lista!\n");
            return -1;
        }
    }

    do{
        printf("\nEscolha a maneira de iniciar a contagem: \n\n");
        printf("[1] A partir do primeiro soldado\n");
        printf("[2] A partir de uma posicao sorteada aleatoriamente\n");
        printf("[3] A partir de um soldado especifico\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);
        switch (op){
            case 1: inicio(&L); break;
            case 2: pos_al(&L); break;
            case 3: sold_esp(&L); break;
            default: printf("\n\n!!! Escolha uma opcao valida !!!\n\n");
        }
    }while(op < 1 || op > 3);

    return 0;
}

int inicio(Lista *L){
    if (lista_vazia(*L)==1){
        printf("\nLista Vazia!\n");
        return 0;
    }

    srand(time(NULL));
    int tam = tamanho(*L);
    int cont = 1 + (rand() % 100);
    char n[MAX];

    printf("\n\nNumero sorteado = %d\n\n", cont);

    while(tam > 1){
        remove_soldado(L,cont,n);
        printf("\nSoldado %s removido!", n);
        tam--;
    }

    get_posicao(*L, 1, n);
    printf("\n\n!!! %s foi o soldado sobrevivente !!!\n\n", n);

    return 1;
}

int pos_al(Lista *L){
    if (lista_vazia(*L)==1){
        printf("\nLista Vazia!\n");
        return 0;
    }

    srand(time(NULL));
    int tam = tamanho(*L);
    int pos = 1 + (rand() % tam);
    int cont = 1 + (rand() % 100);
    char n[MAX];

    get_posicao(*L,pos,n);
    printf("\n\nSoldado na posicao %d sorteado = %s\n", pos, n);

    altera_inicio(L, pos);

    printf("\n\nNumero sorteado = %d\n\n", cont);

    while(tam > 1){
        remove_soldado(L,cont,n);
        printf("\nSoldado %s removido!", n);
        tam--;
    }

    get_posicao(*L, 1, n);
    printf("\n\n!!! %s foi o soldado sobrevivente !!!\n\n", n);

    return 1;
}

int sold_esp(Lista *L){
    if (lista_vazia(*L)==1){
        printf("\nLista Vazia!\n");
        return 0;
    }

    srand(time(NULL));
    int tam = tamanho(*L);
    int cont = 1 + (rand() % 100);
    char n[MAX];

    printf("Digite o nome do soldado que sera o inicial: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", n);

    if(altera_inicio_nome(L, n)==0){
        printf("\n\n%s nao esta na lista!!\n", n);
        printf("Tente outro soldado para ser o inicial: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]", n);
    }

    printf("\n\nNumero sorteado = %d\n\n", cont);

    while(tam > 1){
        remove_soldado(L,cont,n);
        printf("\nSoldado %s removido!", n);
        tam--;
    }

    get_posicao(*L, 1, n);
    printf("\n\n!!! %s foi o soldado sobrevivente !!!\n\n", n);

    return 1;
}
