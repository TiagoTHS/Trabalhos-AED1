#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "fila.h"

#define MAX 20

void imprime_fila(Fila F);

int main(){
    setlocale(LC_ALL, "Portuguese");

    char nome[50];
    int idade, orgao, grau, op, opcao, flag = 0;
    Fila F;
    struct cadastro C;

    do{
        printf("\n====== MENU DO CADASTRO ======\n\n"
               "[1] Criar fila\n"
               "[2] Inserir elemento\n"
               "[3] Remover elemento\n"
               "[4] Liberar fila\n"
               "[5] Imprimir fila\n"
               "[6] Sair");
        printf("\n\nEscolha uma das opções acima: ");
        fflush(stdin); scanf("%d", &op);
        printf("\n==============================\n");


        if(op > 1 && op < 6 && flag == 0){
            printf("\n\nA fila precisa ser criada antes!\n\n");
            continue;
        }

        switch(op){

            case 1 :
                //SÓ É POSSÍVEL CRIAR A FILA UMA ÚNICA VEZ
                if (flag != 0){
                    printf("\nNão é possível criar outra cadastro!\n"
                           "Opções: [1]Sair ou [2]Continuar: "); fflush(stdin); scanf("%d", &opcao);
                    if(opcao == 1){
                        libera_fila(&F);
                        return 0;
                    }
                    if(opcao == 2)
                        break;
                    printf("\n");
                }

                F = cria_fila();
                if(F == NULL){
                    printf("Erro ao iniciar a fila!");
                    return 0;
                }
                else
                    printf("\nA fila foi criada com sucesso!\n");

                flag++;
                break;


            case 2:
                printf("\n---Cadastro do Paciente--- \n");
                printf("\nNome: "); scanf("%s", nome);
                do{
                    printf("\nIdade: "); scanf(" %d", &idade);
                }while(idade < 0);
                do{
                    printf("\nÓrgão desejado: \n");
                    printf("[1]Coração, [2]Fígado, [3]Rins, [4]Córnea: ");
                    fflush(stdin);
                    scanf("%d", &orgao);
                }while(orgao <= 0 || orgao >= 5);
                do{
                    printf("\nGrau de Gravidade: \n"
                           "Sendo de 1(gravidade leve) a 10(gravidade emergencial): "); scanf("%d", &grau);
                }while(grau < 0 || grau > 10);

                strcpy(C.nome, nome);
                C.idade = idade;
                C.orgao = orgao;
                C.grau = grau;

                if (insere_fim(F, C)==0)
                    printf("\n>> Fila de cadastros está lotada!\n");
                else
                    printf("\n>> O cadastro foi inserido com sucesso!\n");

                break;


            case 3:

               if(remove_inicio(F, &C)==0){
                    printf("\nNão tem nenhum cadastro na fila!\n");
                }
                else{
                    printf("\nO cadastro do(a) %s foi removido com sucesso!\n", C.nome);
                }

                break;


            case 4:
                if(esvazia_fila(F)==0)
                    printf("\nCadastros apagados!");
                else
                    printf("\nErro ao esvaziar lista!");

                break;


            case 5:
                imprime_fila(F);

                break;

            case 6:
                printf("\nFIM DE PROGRAMA!!\n");
                break;

            default:
                printf("\n**Opção não válida!**\nEscolha outra opção: \n");
                break;

        }
    }while (op != 6);

    return 0;
}

void imprime_fila(Fila F){
    if(F == NULL){
        printf("\nErro ao imprimir os cadastros!\n");
        return;
    }

    if(fila_vazia(F) == 1){
        printf("\nFila vazia!\n");
        return;
    }

    struct cadastro C2;
    char orgao[10];
    int i;

    printf("\n---Lista de cadastros---\n\n");

   for(i=0;;i++){
        if(get_pos(F, i, &C2) == 0){
            break;
        }
        else{
            printf("Nome: %s \nIdade: %d \n", C2.nome, C2.idade);
            if(C2.orgao == 1)
                strcpy(orgao, "Coração");
            if(C2.orgao == 2)
                strcpy(orgao, "Fígado");
            if(C2.orgao == 3)
                strcpy(orgao, "Rins");
            if(C2.orgao == 4)
                strcpy(orgao, "Córnea");

            printf("Órgão Desejado: %s \n"
                   "Grau de Gravidade: %d\n --- \n", orgao, C2.grau);
        }
    }



    printf("\n");
    return;
}


