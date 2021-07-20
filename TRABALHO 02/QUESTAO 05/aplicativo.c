#include <stdio.h>
#include "fpa_dinam_remove.h"

//PROTOTIPO DE IMPRIME FILA
void imprime_fila(Fila f);

int main(){

    Fila f;
    Aluno A;
    int flag, opcao, verifica = 0;

    do{

    // MENU
    printf("======================================================\n");
    printf("Escolha uma opcao\n");
    printf("[1] Criar fila\n");
    printf("[2] Inserir aluno na fila\n");
    printf("[3] Remover aluno com MENOR ano de ingresso da fila\n");
    printf("[4] Esvaziar fila\n");
    printf("[5] Apagar fila\n");
    printf("[6] Imprimir fila\n");
    printf("[7] Sair\n");
    printf("======================================================\n\n");
    fflush(stdin);
    scanf("%d", &opcao);

        switch(opcao){

            case 1:

                if(verifica != 1){

                    // CHAMADA DA FUNCAO CRIA FILA
                    f = cria_fila();

                    if(f == NULL){
                        printf("\nErro na criacao da fila!\n\n");
                        return -1;
                    }
                    else{
                        printf("\nFila criada com sucesso!\n\n");
                        verifica = 1;
                    }
                    break;
                }
                else{
                    printf("\nA fila ja foi criada uma vez!\n\n");
                }

                break;

            case 2:

                if(verifica == 1){

                    printf("\n----- Insira o aluno -----\n");
                    printf("\nMatricula do aluno: ");
                    fflush(stdin);
                    scanf("%f", &A.matricula);

                    printf("\nNome do aluno: ");
                    fflush(stdin);
                    scanf("%s", &(*(A.nome)));

                    printf("\nCRA do aluno: ");
                    fflush(stdin);
                    scanf("%f", &A.cra);

                    printf("\nAno de ingresso do aluno: ");
                    fflush(stdin);
                    scanf("%d", &A.ano);

                    // CHAMADA DA FUNCAO INSERE FIM
                    flag = insere_fim(f, A);

                    if(flag == 1){
                        printf("\nAluno inserido com sucesso!\n\n");
                    }
                    else{
                        printf("\nErro ao inserir aluno!\n\n");
                    }
                }
                else{
                    printf("\nA fila ainda nao foi criada!\n\n");
                }

                break;

            case 3:

                if(verifica == 1){
                    //CHAMADA DA FUNCAO FILA VAZIA
                    if(fila_vazia(f) == 1){
                        printf("\nA fila esta VAZIA!\n\n");
                        break;
                    }

                    // CHAMADA DA FUNCAO REMOVE ORDENADO
                    flag = remove_ord(f, &A);

                    if(flag == 1){
                        printf("\nAluno %s removido com sucesso!\n\n", A.nome);
                    }
                    else{
                        printf("\nErro ao remover aluno!\n\n");
                    }
                }
                else{
                    printf("\nA fila ainda nao foi criada!\n\n");
                }

                break;

            case 4:
                if(verifica == 1){
                    // CHAMADA DA FUNÇÃO ESVAZIA FILA
                    flag = esvazia_fila(f);

                    if(flag == 1){
                        printf("\nFila esvaziada com sucesso!\n\n");
                    }
                    else{
                        printf("\nErro ao esvaziar lista!\n\n");
                    }
                }
                else{
                    printf("\nA fila ainda nao foi criada!\n\n");
                }

                break;

            case 5:

                if(verifica == 1){

                    // CHAMADA DA FUNCAO LIBERA FILA
                    libera_fila(&f);

                    printf("\nFila apagada com sucesso!\n\n");

                    verifica = 0;

                }
                else{
                    printf("\nA fila ainda nao foi criada!\n\n");
                }

                break;

            case 6:

                if(verifica == 1){

                    // CHAMADA DA FUNCAO IMPRIME FILA
                    imprime_fila(f);
                }
                else{
                    printf("\nA fila ainda nao foi criada!\n\n");
                }

                break;

            case 7:
                printf("\nPrograma finalizado com sucesso!\n\n");
                break;

            default:
                printf("\nEssa opcao nao existe!\n\n");
        }

    }while(opcao != 7);

    return 0;
}

//IMPRIME FILA
void imprime_fila(Fila f){

    if(fila_vazia(f) == 1){
        printf("\nA fila esta VAZIA!\n\n");
        return;
    }

    Aluno A;
    int i = 0;

    while(get_pos(f, i, &A) != 0){
        printf("\n----- Aluno -----\n\n");
        printf("Matricula: %f\n", A.matricula);
        printf("Nome: %s\n", A.nome);
        printf("CRA: %f\n", A.cra);
        printf("Ano de ingresso: %d\n\n", A.ano);
        i++;
    }

}
