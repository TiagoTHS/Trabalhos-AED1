/*
    TAD Fila de pessoas a serem vacinadas. Alocação Din/Enc (encadeamento simples).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include "lista.h"
#include "filaDinEnc.h"

//Protótipos:
void cadastrar(Lista *lst);
void fila_diaria(Lista *lst, Fila f1, Fila f2, Fila f3, Fila f4);
void sorteia_vacina(int max_vacinas, char vacina[]);
void controle_vacina(Lista *lst, Lista *lst2, Fila f1, Fila f2, Fila f3, Fila f4);
void imprimir(Fila f);
void imprime_lista(Lista lst);
void ajusta_data(Pessoa *p, int tempo);

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Fila f1 = cria_fila();
    Fila f2 = cria_fila();
    Fila f3 = cria_fila();
    Fila f4 = cria_fila();
    Lista lst = cria_lista(); //Lista de espera
    Lista vacinados = cria_lista(); // Lista de vacinados

    int option = 0, flag;

    while(option != 5){
        printf(" ---------------MENU--------------- \n");
        printf("|                                  |\n");
        printf("| [1]Cadastrar na lista de espera  |\n");
        printf("| [2]Gerar fila diária             |\n");
        printf("| [3]Controle de vacinação         |\n");
        printf("| [4]Cenário da vacinação          |\n");
        printf("| [5]Sair                          |\n");
        printf(" ---------------------------------- \n");

        printf("\nDigite a opção desejada: ");
        scanf("%d", &option);

        switch(option){
            case 1:

                cadastrar(&lst);
                break;

            case 2:

                fila_diaria(&lst, f1, f2, f3, f4);
                break;

            case 3:

                controle_vacina(&lst, &vacinados, f1, f2, f3, f4);
                break;

            case 4:
                system("cls");

                printf("[1] Imprimir listas\n");
                printf("[2] Imprimir filas\n\n");

                scanf("%d", &flag);

                if(flag == 1){
                    printf("===== Lista de Espera =====\n\n");
                    imprime_lista(lst);
                    printf("===========================\n\n");

                    printf("=== Lista de Vacinados ===\n\n");
                    imprime_lista(vacinados);
                    printf("==========================\n\n");

                } else {
                    printf("======= Fila UTC1 =======\n\n");
                    imprimir(f1);
                    printf("=========================\n\n");

                    printf("======= Fila UTC2 =======\n\n");
                    imprimir(f2);
                    printf("=========================\n\n");

                    printf("==== Fila Sabiazinho ====\n\n");
                    imprimir(f3);
                    printf("=========================\n\n");

                    printf("==== Fila Prefeitura ====\n\n");
                    imprimir(f4);
                    printf("=========================\n\n");
                }

                break;

            case 5:

                system("cls");
                printf("Programa encerrado!\n");
                break;

            default:
                printf("Opção inválida, por favor tente novamente!\n");
                break;
        }

        printf("=======================================\n\n");
    }

    return 0;
}

void cadastrar(Lista *lst){
    Pessoa p;
    int teste;

    fflush(stdin);
    printf("Digite o nome do paciente: ");
    scanf("%[^\n]", p.nome);

    printf("Digite a idade do usuário: ");
    scanf("%d", &p.idade);

    printf("O usuário possui alguma comorbidade? [1]Sim, [0]Não\n");
    printf(">> ");
    scanf("%d", &p.comorbidade);

    if(p.comorbidade == 1){
        p.local = 1;
    } else if(p.comorbidade == 0 && p.idade <= 60){
        p.local = 2;
    } else {
        p.local = 4;
    }

    teste = insere_elem(lst, p);

    if(teste == 1){
        printf("Dados cadastrados com sucesso!\n");
    } else{
        printf("Falha ao inserir os dados.\n");
    }
}

void fila_diaria(Lista *lst, Fila f1, Fila f2, Fila f3, Fila f4){
    int aux;
    int local, qtd, i;
    Pessoa p;

    int flag;
    char vacina[12];


    for(local = 1; local <= 4; local++){

        if(local == 3)
            qtd = 12;
        else
            qtd = 6;

        sorteia_vacina(qtd, vacina);

        for(i = 0; i < qtd; i++){

            if(local != 3)
                aux = maior_idade(lst, local, &p);
            else
                aux = menor_data(lst, &p);

            if(aux == 1){
                p.tipo_vacina = vacina[i];
            } else{
                break;
            }

            if(local == 1){
                flag = insere_fim(f1, p);
                if(flag == 0)
                    return;

            } else if(local == 2){
                flag = insere_fim(f2, p);
                if(flag == 0)
                    return;

            } else if(local == 3){
                flag = insere_fim(f3, p);
                if(flag == 0)
                    return;

            } else{
                flag = insere_fim(f4, p);
                if(flag == 0)
                    return;
            }
        }
    }

}

void sorteia_vacina(int max_vacinas, char vacina[]){
    int max = max_vacinas / 3;  // Máximo de doses por vacina

    char tipo_vacina[3] = {'A', 'P', 'C'};
    int i, num;
    int cont1 = 0, cont2 = 0, cont3 = 0;

    srand(time(NULL));
    for(i = 0; i < max_vacinas; i++){
        num = rand()%3;

        if(num == 0)
            cont1++;

        if(num == 1)
            cont2++;

        if(num == 2)
            cont3++;

        while(cont1 > max || cont2 > max || cont3 > max){

            if(cont1 > max){
                while(num == 0)
                    num = rand()%3;

                if(num == 1)
                    cont2++;

                if(num == 2)
                    cont3++;

                cont1--;
            }

            if(cont2 > max){
                while(num == 1)
                    num = rand()%3;

                if(num == 0)
                    cont1++;

                if(num == 2)
                    cont3++;

                cont2--;
            }

            if(cont3 > max){
                while(num == 2)
                    num = rand()%3;

                if(num == 0)
                    cont1++;

                if(num == 1)
                    cont2++;

                cont3--;
            }
        }

        vacina[i] = tipo_vacina[num];
    }

}

void controle_vacina(Lista *lst, Lista *lst2, Fila f1, Fila f2, Fila f3, Fila f4){
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    //printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    Pessoa p;

    while(remove_ini(f1, &p)){
        if(p.tipo_vacina == 'A'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            ajusta_data(&p, 90);

            p.local = 3;

            insere_elem(lst, p);

        } else if(p.tipo_vacina == 'P'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            insere_elem(lst2, p);

        } else if(p.tipo_vacina == 'C'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            ajusta_data(&p, 60);

            p.local = 3;

            insere_elem(lst, p);
        }
    }

    while(remove_ini(f2, &p)){
        if(p.tipo_vacina == 'A'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            ajusta_data(&p, 90);

            p.local = 3;

            insere_elem(lst, p);

        } else if(p.tipo_vacina == 'P'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            insere_elem(lst2, p);

        } else if(p.tipo_vacina == 'C'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            ajusta_data(&p, 60);

            p.local = 3;

            insere_elem(lst, p);
        }
    }

    while(remove_ini(f3, &p)){
        if(p.tipo_vacina == 'A'){
            insere_elem(lst2, p);

        } else if(p.tipo_vacina == 'P'){
            insere_elem(lst2, p);

        } else if(p.tipo_vacina == 'C'){
            insere_elem(lst2, p);
        }
    }

    while(remove_ini(f4, &p)){
        if(p.tipo_vacina == 'A'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            ajusta_data(&p, 90);

            p.local = 3;

            insere_elem(lst, p);

        } else if(p.tipo_vacina == 'P'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            insere_elem(lst2, p);

        } else if(p.tipo_vacina == 'C'){
            p.data1.dia = tm.tm_mday;
            p.data1.mes = tm.tm_mon + 1;
            p.data1.ano = tm.tm_year + 1900;

            ajusta_data(&p, 60);

            p.local = 3;

            insere_elem(lst, p);
        }
    }
}

void imprimir(Fila f){
    Pessoa p;
    Fila aux = cria_fila();

    if(fila_vazia(f) == 1)
        printf("A lista está vazia!\n");
    else{
        while(remove_ini(f, &p)){
            insere_fim(aux, p);
        }

        while(remove_ini(aux, &p) == 1){
            printf("-------------------------\n");
        printf("Nome: %s\n", p.nome);
        printf("Idade: %d\n", p.idade);

        if(p.comorbidade == 1)
            printf("Comorbidade: Sim\n");
        else
            printf("Comorbidade: Não\n");

        if(p.tipo_vacina == 'A')
            printf("Vacina: Astrazeneca\n");
        else if(p.tipo_vacina == 'P')
            printf("Vacina: Pfizer\n");
        else if(p.tipo_vacina == 'C')
            printf("Vacina: Coronavac\n");


        if(p.local == 1)
            printf("Local: UTC1\n");
        else if(p.local == 2)
            printf("Local: UTC2\n");
        else if(p.local == 3)
            printf("Local: Sabiazinho\n");
        else
            printf("Local: UTC2\n");

        printf("-------------------------\n\n");
            insere_fim(f, p);
        }
        printf("\n");
    }

}

void imprime_lista(Lista lst){

    if(lista_vazia(lst) == 1){
        printf("A lista está vazia!\n");
        return;
    }

    int i = 0;
    Pessoa p;

    while(obtem_elem(lst, i, &p) != 0){
        printf("-------------------------\n");
        printf("Nome: %s\n", p.nome);
        printf("Idade: %d\n", p.idade);

        if(p.comorbidade == 1)
            printf("Comorbidade: Sim\n");
        else
            printf("Comorbidade: Não\n");

        if(p.tipo_vacina == 'A')
            printf("Vacina: Astrazeneca\n");
        else if(p.tipo_vacina == 'P')
            printf("Vacina: Pfizer\n");
        else if(p.tipo_vacina == 'C')
            printf("Vacina: Coronavac\n");


        if(p.tipo_vacina == 'P')
            printf("Data da 1ª dose: %d/%d/%d\n", p.data1.dia, p.data1.mes, p.data1.ano);
        else if(p.tipo_vacina == 'A' || p.tipo_vacina == 'C'){
            printf("Data da 1ª dose: %d/%d/%d\n", p.data1.dia, p.data1.mes, p.data1.ano);
            printf("Data da 2ª dose: %d/%d/%d\n", p.data2.dia, p.data2.mes, p.data2.ano);
        }

        if(p.local == 1)
            printf("Local: UTC1\n");
        else if(p.local == 2)
            printf("Local: UTC2\n");
        else if(p.local == 3)
            printf("Local: Sabiazinho\n");
        else
            printf("Local: UTC2\n");

        printf("-------------------------\n\n");

        i++;
    }
}

void ajusta_data(Pessoa *p, int tempo){
    int dia = (*p).data1.dia;
    int mes = (*p).data1.mes;
    int ano = (*p).data1.ano;

    dia = dia + tempo;

    int flag = 0;

    while(flag != 1){

        if(mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
        mes == 8 || mes == 10 || mes == 12){

            if(dia <= 31){
                flag = 1;
            }

        }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

            if(dia <= 30){
                flag = 1;
            }

        } else {
            if(dia <= 28){
                flag = 1;
            }
        }

        if(flag == 0){

            if(mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
            mes == 8 || mes == 10 || mes == 12){

                dia = dia - 31;
                mes++;

            } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){

                dia = dia - 30;
                mes++;

            } else{
                dia = dia - 28;
                mes++;
            }

            if(mes > 12){
                ano++;
                mes = mes - 12;
            }
         }
    }

    (*p).data2.dia = dia;
    (*p).data2.mes = mes;
    (*p).data2.ano = ano;
}

//-------------------------
