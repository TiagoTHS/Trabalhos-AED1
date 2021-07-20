#include <stdio.h>
#include <stdlib.h>
#include "dequeCircular.h"

void insercao(Deque *F);
void remocao(Deque *F);
void imprime_deque(Deque F);

int main()
{
    Deque F;
    int op, FLAG = 0;

    do{
        printf("\n----- Menu ----");
        printf("\n\n[1] Cria deque\n[2] Inserir elemento\n[3] Remover elemento\n[4] Imprimir deque\n[5] Apaga deque\n[6] Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
        case 1:{
            if (!FLAG){
                F = cria_deque();
                FLAG++;
                printf("Deque inicializado com sucesso\n");
            }
            else
                printf("Deque ja criado\n");
        }break;
        case 2:{
            if(FLAG){
                insercao(&F);
            }
            else
                printf("Deque ainda nao inicializado\n");
        }break;
        case 3:{
            if(FLAG){
                remocao(&F);
            }
            else
                printf("Deque ainda nao criado\n");
        }break;
        case 4:{
            if(!FLAG)
                printf("Deque ainda nao criado\n");
            else
                imprime_deque(F);
        }break;
        case 5:{
            if(!FLAG)
                printf("Deque ainda nao criado\n");
            else{
                apaga_deque(&F);
                FLAG--;
            }
        }
        }
    }while(op != 6);

    printf("Encerrando o programa...\n");

    return 0;
}

void imprime_deque(Deque F){
    int i;
    char c;

    if(deque_vazio(F)==1)
        printf("Deque vazio!\n");
    else{
        printf("--- Deque ---\n");
        printf("{ ");
        for (i = 1; ; i++){
            if (get_posicao(F,i,&c)==0)
                break;
            printf("%c ", c);
        }
        printf("}\n");
    }
}

void insercao(Deque *F){
    int e;
    char c;

    printf("\nDigite o caracter que deseja inserir: ");
    setbuf(stdin, NULL);
    scanf("%c", &c);

    do{
        printf("\n--- Escolha a maneira de inserir ---\n");
        printf("[1] Inserir no inicio\n[2] Inserir no final\n");
        printf("\nDigite a opcao desejada: ");
        setbuf(stdin, NULL);
        scanf("%d", &e);

        switch (e){
            case 1:{
                if(insere_inicio(F,c)==1){
                    printf("Caracter inserido com sucesso!\n");
                }
                else
                    printf("Nao foi possivel inserir o caracter\n");
            }break;
            case 2:{
                if(insere_final(F,c)==1){
                    printf("Caracter inserido com sucesso!\n");
                }
                else
                    printf("Nao foi possivel inserir o caracter\n");
            }
        }
    }while(e < 1 || e > 2);
}

void remocao(Deque *F){
    int e;
    char c;

    do{
        printf("\n--- Escolha a maneira de remover ---\n");
        printf("[1] Remover no inicio\n[2] Remover no final\n");
        printf("\nDigite a opcao desejada: ");
        setbuf(stdin, NULL);
        scanf("%d", &e);

        switch (e){
            case 1:{
                if(remove_inicio(F,&c)==1){
                    printf("Caracter '%c' removido com sucesso!\n", c);
                }
                else
                    printf("Nao foi possivel remover o caracter\n");
            }break;
            case 2:{
                if(remove_final(F,&c)==1){
                    printf("Caracter '%c' removido com sucesso!\n", c);
                }
                else
                    printf("Nao foi possivel remover o caracter\n");
            }
        }

    }while(e < 1 || e > 2);
}
