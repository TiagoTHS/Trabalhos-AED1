#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include "fila.h"

#define MAX 10


int verifica_menor(Fila F1, Fila F2, Fila F3, Fila F4, Fila F5);
void imprime_fila(Fila F1, Fila F2, Fila F3, Fila F4, Fila F5, Fila Espera);
void pagamento(time_t saida, struct cadastro C);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int flag = 0;
    int i, j, tamanho, tam[5], fila_menor, FLAG, opcao, op;
    char placa[8], tipo;
    Fila F1,F2, F3, F4, F5, Espera, Auxiliar;
    time_t entrada, saida;
    struct cadastro C;

    do{
        printf("\n============ MENU ============\n"
               "[1] Iniciar\n"
               "[2] Inserir cadastro\n"
               "[3] Remover cadastro\n"
               "[4] Esvaziar box\n"
               "[5] Apagar todos os registros\n"
               "[6] Visualizar estacionamento\n"
               "[7] Sair");
        printf("\n\nEscolha uma das opções acima: ");
        fflush(stdin);
        scanf("%d", &op);
        printf("\n==============================\n");


        if(op > 1 && op < 7 && flag == 0){
            printf("\n\nA fila precisa ser criada antes!\n\n");
            continue;
        }

        switch(op){

            case 1 :

                if (flag != 0){
                    printf("\nApague a lista antes de reinicializar (opção [5])\n");
                }

                F1 = cria_fila();
                F2 = cria_fila();
                F3 = cria_fila();
                F4 = cria_fila();
                F5 = cria_fila();
                Espera = cria_fila();
                Auxiliar = cria_fila();

                if(F1 == NULL || F2 == NULL || F3 == NULL || F4 == NULL || F5 == NULL || Espera == NULL || Auxiliar == NULL){
                    printf("Erro ao criar filas!");
                    return 0;
                }

                if(flag == 0)
                    printf("\nA fila foi criada com sucesso!\n");

                flag++;
                break;


            case 2:

                //O CADASTRO DO TEMPO É FEITO QUANDO SE INSERE O CARRO
                printf("Insira cadastro do carro \n\n");
                printf("Placa: "); fflush(stdin); scanf("%s", &(*placa));
                do{
                    printf("\nTipo: \n[A]avulso\n[M]mensalista:  ");
                    fflush(stdin); scanf("%c", &tipo);
                }while(tipo != 'A' && tipo != 'M');
                entrada = time(NULL);

                strcpy(C.placa, placa);
                C.tipo = tipo;
                C.horario = entrada;

                //SABER O TAMANHO PARA CONSEGUIR COLOCAR O CARRO NO BOX COM MENOS VAGAS
                fila_menor = verifica_menor(F1, F2, F3, F4, F5);
                if(fila_menor == -1){
                    printf("\nErro na verifiação do tamanho!\n");
                    break;
                }

                if(fila_menor == 1){
                    Auxiliar = F1;
                }
                if(fila_menor == 2){
                    Auxiliar = F2;
                }
                if(fila_menor == 3){
                    Auxiliar = F3;
                }
                if(fila_menor == 4){
                    Auxiliar = F4;
                }
                if(fila_menor == 5){
                    Auxiliar = F5;
                }

                //SE TODAS AS FILAS ESTIVEREM CHEIAS, VAI COLOCAR OS PRÓXIMOS CARROS NA FILA DE ESPERA
                if((fila_cheia(F1)==1) && (fila_cheia(F2)==1) && (fila_cheia(F3)==1) && (fila_cheia(F4)==1) && (fila_cheia(F5)==1)){
                    if (insere_fim(Espera, C)==0){ // FILA DE ESPERA TÁ LOTADO, NÃO ADICIONA NADA
                        printf("\nO estacionamento tá totalmente lotado!\nNão é possível adiocionar mais carros!\n");
                        break;}
                    printf("\nEstacionamente cheio, carro foi adicionado a Fila de Espera!\n");
                    break;
                }

                //SE FOR NULL, O RESULTADO É -1 E DÁ ERRADO A INSERÇÃO
                if (insere_fim(Auxiliar, C)== -1)
                    printf("\nErro ao inserir elemento!\n");
                else
                    printf("\nCarro foi inserido no Box %d!\n", fila_menor);

                break;


            case 3:
                //TAMANHO PARA PROCURAR O CARRO EM CADA FILA
                tam[0] = tamanho_fila(F1);
                tam[1] = tamanho_fila(F2);
                tam[2] = tamanho_fila(F3);
                tam[3] = tamanho_fila(F4);
                tam[4] = tamanho_fila(F5);

                //PROCURAR POR ALGUM ERRO
                for(i=0; i<5; i++){
                    if (tam[i] == -1){
                        printf("\nErro na verificação do tamanho!\n");
                        break;
                    }
                }

                printf("Informe a placa do carro a ser retirado: ");scanf("%s", placa);
                saida = time(NULL); //PEGA O HORÁRIO DE SAÍDA

                for(i=0; i<5; i++){ //PASSA POR CADA FILA
                    for(j=0; j<tam[i]; j++){ //PASSAR POR CADA ITEM DA FILA
                        if(i == 0){
                            Auxiliar = F1;
                        }
                        if(i == 1){
                            Auxiliar = F2;
                        }
                        if(i == 2){
                            Auxiliar = F3;
                        }
                        if(i == 3){
                            Auxiliar = F4;
                        }
                        if(i == 4){
                            Auxiliar = F5;
                        }

                        le_topo(Auxiliar, &C); //LÊ O PRIMEIRO ELEM
                        if(strcmp(placa, C.placa)==0){ //SE O TOPO FOR IGUAL A PLACA PROCURADA
                            remove_inicio(Auxiliar,&C); //REMOVE ELE -> FLAG = 1 -> BREAK
                            printf("\nO carro placa: %s foi removido com sucesso!\n", C.placa);
                            if(fila_vazia(Espera)!= 1){ //SE TIVER ALGUMA NA FILA DE ESPERA VAI PRO FINAL DA FILA DO LUGAR ONDE TIROU
                                remove_inicio(Espera, &C);
                                entrada = time(NULL);
                                C.horario = entrada;
                                insere_fim(Auxiliar, C);
                            }

                            //PAGAMENTO
                            pagamento(saida, C);

                            FLAG = 1; //MOSTRA QUE ACHOU O ELEMENTO, NÃO PRECISA CONTINUAR PERCORRENDO
                            break;
                        }
                        else{
                            remove_inicio(Auxiliar, &C); //O ELEMENTO NÃO ERA O DO TOPO, PASSOU ELE PRO FINAL DA FILA
                            insere_fim(Auxiliar, C);     //PRA PODER ANALISAR O PRÓXIMO TOPO
                        }
                    }
                    if(FLAG == 1) //SAIR DO SEGUNDO LAÇOS
                        break;
                }

                if(FLAG == 0){ //ACABOU AS 5 LISTAS E FLAG MOSTRA QUE NÃO ACHOU ELEMENTO
                    printf("Não foi possível localizar o carro!\n");
                }

                FLAG = 0; //VOLTA A ZERAR PRA PRÓXIMA REMOÇÃO

                break;


            case 4:

                do{
                    printf("\nDigite o box que vai ser esvaziado (1, 2, 3, 4, 5, 6-Espera, 7-Todos): ");
                    fflush(stdin);
                    scanf("%d", &op);
                }while(op < 1 || op > 7);
                if(op == 1){
                    Auxiliar = F1;
                }
                if(op == 2){
                    Auxiliar = F2;
                }
                if(op == 3){
                    Auxiliar = F3;
                }
                if(op == 4){
                    Auxiliar = F4;
                }
                if(op == 5){
                    Auxiliar = F5;
                }
                if(op == 6){
                    Auxiliar = Espera;
                }
                if(op == 7){
                    esvazia_fila(F1);esvazia_fila(F2);esvazia_fila(F3);esvazia_fila(F4);esvazia_fila(F5);
                    esvazia_fila(Espera);
                }

                if(op != 7 && esvazia_fila(Auxiliar)==0)
                    printf("\nErro ao esvaziar a box\n");
                else if(op!= 7)
                    printf("\nBox %d esvaziado com sucesso!\n", op);

                if(op == 6)
                    printf("\nBox de Espera esvaziado com sucesso!\n");
                if(op == 7)
                    printf("\nTodos os Box foram esvaziados com sucesso!\n");

                //SE ESVAZIOU ALGUM BOX ESPECIFICO, TEM QUE COLOCAR OS DA FILA DE ESPERA NO ESTACIONAMENTO
                tamanho = tamanho_fila(Espera);
                if(fila_vazia(Espera)!= 1 && op != 6){
                    for(i=0; i<tamanho; i++){
                        remove_inicio(Espera, &C);
                        fila_menor = verifica_menor(F1, F2, F3, F4, F5);
                        if(fila_menor == 1){
                            Auxiliar = F1;
                        }
                        if(fila_menor == 2){
                            Auxiliar = F2;
                        }
                        if(fila_menor == 3){
                            Auxiliar = F3;
                        }
                        if(fila_menor == 4){
                            Auxiliar = F4;
                        }
                        if(fila_menor == 5){
                            Auxiliar = F5;
                        }
                        entrada = time(NULL);
                        C.horario = entrada;
                        insere_fim(Auxiliar, C);
                    }
                }
                //PARA NÃO ENCERRAR O PROGRAMA CASO A OPÇÃO SEJA 7
                op = 0;
                break;


            case 5:
                do{
                    printf("\nCerteza que vai apagar todos os registros? sim[1], não[2]:  ");
                    fflush(stdin); scanf("%d", &opcao);
                }while(opcao != 1 && opcao!= 2);

                if(opcao == 1){
                    libera_fila(&F1);libera_fila(&F2);libera_fila(&F3);libera_fila(&F4);libera_fila(&F5);
                    libera_fila(&Auxiliar);libera_fila(&Espera);

                    printf("\nTodos os cadastros foram apagados!(Fila não existe mais)\n");
                    flag = 0;
                }

                break;

            case 6:
                imprime_fila(F1,F2,F3,F4,F5,Espera);

                break;

            case 7:
                printf("\nFIM DE PROGRAMA!!\n");
                break;

            default:
                printf("\n**Opção não válida!**\nEscolha outra opção: \n");
        }
    }while (op != 7);

    return 0;
}

int verifica_menor(Fila F1, Fila F2, Fila F3, Fila F4, Fila F5){
    int fila_menor;
    int i;

    int tam[5];
    tam[0] = tamanho_fila(F1);
    tam[1] = tamanho_fila(F2);
    tam[2] = tamanho_fila(F3);
    tam[3] = tamanho_fila(F4);
    tam[4] = tamanho_fila(F5);

    int menor = tam[0];
    for(i=0; i<5; i++){
        if (tam[i] == -1){
            printf("\nErro na verificação do tamanho!\n");
            return -1;
        }
    }

    for(i=0; i<5; i++){
        if (menor > tam[i]){
            menor = tam[i];
            fila_menor = i;
        }
    }

    return fila_menor+1;
}

void pagamento(time_t saida, struct cadastro C){
    double tempo, horas, minutos;
    int aux;
    if (C.tipo == 'A'){ //SE FOR AVULSO TEM QUE PAGAR
        tempo = difftime(saida,C.horario); //DIFERENÇA TEMPO DE SAIDA - ENTRADA

        //RESPOSTA EM TEMPO DADA EM SEGUNDOS
        horas = tempo/60.0; //SIMULAR SEGUNDOS EM MINUTOS -> DIVIDIR PARA ACHAR AS HORAS
        aux = (int)horas;
        minutos = (horas - (double)aux)*60.0; //O RESTO DAS "HORAS" SÃO OS MINUTOS
        printf("\nVocê ficou por %dh%.0fmin", aux, minutos);

        if(horas<1){
            printf("\nO preço a ser pago é: 10.00\n");
        }
        else{
            if(minutos>15){ //PAGA A HORA SE FOR MAIS DE 15 MIN
                tempo = (horas)*3 + 10;
                printf("\nO preço a ser pago é: %.0f.00\n", tempo);
            }
            else{ //LIMITE DE 15 MIN SEM PAGAR A HORA CHEIO
                tempo = (horas-1)*3 + 10;
                printf("\nO preço a ser pago é: %.0f.00\n", tempo);
            }
        }
    }
    else if (C.tipo == 'M'){
        printf("//Cobrança mensal//\n    tchau\n");
    }

}

void imprime_fila(Fila F1, Fila F2, Fila F3, Fila F4, Fila F5, Fila Espera){

    if(F1 == NULL || F2 == NULL || F3 == NULL || F4 == NULL || F5 == NULL || Espera == NULL){
        printf("\nSem fila para ser mostrada!\n");
        return;
    }

    Fila Auxiliar;
    Auxiliar = cria_fila();
    if(Auxiliar == NULL){
        return;
    }

    int tam[6];
    tam[1] = tamanho_fila(F1);
    tam[2] = tamanho_fila(F2);
    tam[3] = tamanho_fila(F3);
    tam[4] = tamanho_fila(F4);
    tam[5] = tamanho_fila(F5);
    tam[6] = tamanho_fila(Espera);

    struct cadastro C;
    int i, j;

    printf("Estacionamento: \n\n");

    for(i=1; i<=5;i++){
        printf("---------------------------------------------------\n");
        printf("BOX %d: ", i);
        for(j=1;j<=tam[i];j++){
            if(i == 1)
                Auxiliar = F1;
            if(i == 2)
                Auxiliar = F2;
            if(i == 3)
                Auxiliar = F3;
            if(i == 4)
                Auxiliar = F4;
            if(i == 5)
                Auxiliar = F5;
            remove_inicio(Auxiliar, &C);
            printf("%s   ", C.placa);
            insere_fim(Auxiliar, C);
        }
        printf("\n");
    }

    printf("---------------------------------------------------\n");
    printf("FILA DE ESPERA: ");
    for(j=1;j<=tam[6];j++){
        remove_inicio(Espera, &C);
        printf("%s   ", C.placa);
        insere_fim(Espera, C);
    }
    printf("\n---------------------------------------------------\n\n");

    return;
}
