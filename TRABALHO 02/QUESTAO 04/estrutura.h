#ifndef ESTRUTURA_H_INCLUDED
#define ESTRUTURA_H_INCLUDED

struct data{
    int dia, mes, ano;
};

typedef struct data Data;

struct pessoa{
    char nome[20];
    int idade, comorbidade;
    char tipo_vacina;
    Data data1, data2;
    int local;
};

typedef struct pessoa Pessoa;

#endif
