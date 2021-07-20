/*
ALUNOS:
    Gabriela Santos Damazo - 12011BCC003
    Isabelli Prudencio Tedeschi - 12011BCC018
    Paulo Vitor Costa Silva - 12011BCC045
    Tiago da Silva e Souza Pinto - 12011BCC001

*/

#include <stdio.h>
#include "pilha.h"

//PROTOTIPO DA FUNCAO CONVERTE
int converte(Pilha p, char c, int elem);

// PROTOTIPO DA FUNCAO IMPRIME NUMERO
void imprime_nro(Pilha p);

int main(){

    Pilha p;
    int nro, flag;
    char escolha;

    printf("\tBEM-VINDO AO PROGRAMA DE CONVERSOES\n");

    p = cria_pilha();
    if(p == NULL){
        printf("\nErro na criacao da pilha!\n\n");
        return -1;
    }

    do{

        printf("\nDigite o numero na base DECIMAL (base 10) a ser convertido: ");
        fflush(stdin);
        scanf("%d", &nro);
        if(nro < 0){
            return 0;
        }

        printf("\n=====================================================");
        printf("\n\nDigite [B] para converter de decimal para BINARIO\n");
        printf("Digite [O] para converter de decimal para OCTAL\n");
        printf("Digite [H] para converter de decimal para HEXADECIMAL\n\n");
        printf("=====================================================\n\n");

        do{
            printf("ESCOLHA: ");
            fflush(stdin);
            scanf("%c", &escolha);
        }while(escolha != 'B' && escolha != 'O' && escolha != 'H');

        flag = converte(p, escolha, nro);
        if(flag != 1){
            return 0;
        }

        imprime_nro(p);

        printf("\n\n=====================================================");
        printf("\n\nDigite um nro NEGATIVO caso deseje PARAR o programa\n");

    }while(nro >= 0);

    libera_pilha(&p);

    return 0;
}

int converte(Pilha p, char c, int elem){

    if(p == NULL || elem < 0){ // Trata falha na pilha e confere nro negativo
        return -1;
    }

    int base, bit, flag;

    flag = esvazia_pilha(p);
    if(flag == 0){
        return -1;
    }

    if(c == 'B'){
        base = 2;
    }else if(c == 'O'){
        base = 8;
    }else if(c == 'H'){
        base = 16;
    }else
        return -1; // Opcao de conversao invalida

    do{
        bit = elem % base; // Bit que vai para a pilha, resto da div
        elem = (int)(elem / base); // Confirma que eh inteiro
        push(p,bit);

    }while(elem != 0);

    return 1; // Sucesso na conversão
}

//IMPRIME NRO
void imprime_nro(Pilha p){

    if(p == NULL){
        printf("\nErro na criacao da pilha!\n\n");
        return;
    }

    if(pilha_vazia(p) == 1){
        printf("\nA pilha esta VAZIA!\n\n");
        return;
    }

    Pilha aux;
    int flag, elem;

    aux = cria_pilha();

    if(aux == NULL){
        printf("\nErro na criacao da pilha auxiliar!\n\n");
        return;
    }

    printf("\nNRO CONVERTIDO: ");
    while(pilha_vazia(p) != 1){
        flag = pop(p, &elem);
        if(flag == 0){
            printf("\nErro 1 na impressao!\n\n");
            break;
        }

        flag = push(aux, elem);
        if(flag == 0){
            printf("\nErro 2 na impressao!\n\n");
            break;
        }

        if(elem <= 9)
            printf("%d ", elem);
        else{
            if(elem == 10){
                printf("A ");
            }else if(elem == 11){
                printf("B ");
            }else if(elem == 12){
                printf("C ");
            }else if(elem == 13){
                printf("D ");
            }else if(elem == 14){
                printf("E ");
            }else if(elem == 15){
                printf("F ");
            }
        }
    }

    while(pilha_vazia(aux) != 1){
        flag = pop(aux, &elem);
        if(flag == 0){
            printf("\nErro 3 na impressao!\n\n");
            break;
        }

        flag = push(p, elem);
        if(flag == 0){
            printf("\nErro 4 na impressao!\n\n");
            break;
        }
    }

    libera_pilha(&aux);
}
