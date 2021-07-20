/*
Tiago da Silva e Souza Pinto - 12011BCC001
Paulo Vitor Costa Silva - 12011BCC045
Gabriela Santos Damazo - 12011BCC003
Isabelli Prudencio Tedeschi - 12011BCC018
*/

#include <stdio.h>
#include "listaCircular.h"

void insercao(Lista *L);
void remocao(Lista *L);
void imprime_lista(Lista L);

int main()
{
    Lista L;
    int op, FLAG = 0;

    do{
        printf("\n----- Menu ----");
        printf("\n\n[1] Cria lista\n[2] Inserir elemento\n[3] Remover elemento\n[4] Imprimir lista\n[5] Tamanho\n[6] Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
        case 1: {
            if(!FLAG){
                L = cria_lista();
                FLAG++;
                printf("Lista criada com sucesso!\n");
            }
            else
                printf("Lista ja criada!\n");
        } break;
        case 2: {
            if(FLAG)
                insercao(&L);
            else
                printf("Lista ainda nao criada!\n");
        } break;
        case 3: {
            if(FLAG)
                remocao(&L);
            else
                printf("Lista ainda nao criada!\n");
        } break;
        case 4: {
            if(FLAG)
                imprime_lista(L);
            else
                printf("Lista ainda nao criada!\n");
        } break;
        case 5: {
            if(FLAG)
                printf("A lista possui %d elementos!\n", tamanho(L));
            else
                printf("Lista ainda nao criada!\n");
        }
        }
    }while(op != 6);

    printf("Encerrando o programa...\n");

    return 0;
}

void imprime_lista(Lista L){
    int i;
    char n;
    if(lista_vazia(L)==1)
        printf("Lista vazia!\n");
    else{
        printf("--- Lista ---\n");
        printf("{ ");
        for (i = 1; ; i++){
            if (get_posicao(L,i,&n)==0)
                break;
            printf("%c ", n);
        }
        printf("}\n");
    }
}

void insercao(Lista *L){
    int e, pos;
    char n;
    printf("\nDigite o character que deseja inserir: \n");
    setbuf(stdin, NULL);
    scanf("%c", &n);

    do{
        printf("\n--- Escolha a maneira de inserir ---\n");
        printf("[1] Inserir no inicio\n[2] Inserir no final\n[3] Inserir em uma posicao especifica\n");
        printf("\nDigite a opcao desejada: ");
        setbuf(stdin, NULL);
        scanf("%d", &e);

        switch (e){
            case 1:{
                if(insere_inicio(L,n)==1){
                    printf("Character inserido com sucesso!\n");
                }
                else
                    printf("Nao foi possivel inserir o character\n");
            }break;
            case 2:{
                if(insere_final(L,n)==1){
                    printf("Character inserido com sucesso!\n");
                }
                else
                    printf("Nao foi possivel inserir o character\n");
            }break;
            case 3:{
                printf("\nDigite a posicao em que quer inserir o character: ");
                setbuf(stdin, NULL);
                scanf("%d", &pos);
                if(insere_posicao(L,pos,n)==1){
                    printf("Character inserido com sucesso!\n");
                }
                else
                    printf("Nao foi possivel inserir o character\n");
            }
        }
    }while(e < 1 || e > 3);
}

void remocao(Lista *L){
    int e, pos;
    char n;

    do{
        printf("\n--- Escolha a maneira de remover ---\n");
        printf("[1] Remover no inicio\n[2] Remover no final\n[3] Remover em uma posicao especifica\n");
        printf("\nDigite a opcao desejada: ");
        setbuf(stdin, NULL);
        scanf("%d", &e);

        switch (e){
            case 1:{
                if(remove_inicio(L,&n)==1){
                    printf("Character %c removido com sucesso!\n", n);
                }
                else
                    printf("Nao foi possivel remover o character\n");
            }break;
            case 2:{
                if(remove_final(L,&n)==1){
                    printf("Character %c removido com sucesso!\n", n);
                }
                else
                    printf("Nao foi possivel remover o character\n");
            }break;
            case 3:{
                printf("\nDigite a posicao em que quer remover o character: ");
                setbuf(stdin, NULL);
                scanf("%d", &pos);
                if(remove_posicao(L,pos,&n)==1){
                    printf("Character %c removido com sucesso!\n", n);
                }
                else
                    printf("Nao foi possivel remover o character\n");
            };
        }

    }while(e < 1 || e > 3);
}
