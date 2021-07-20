#ifndef FPA_DINAM_REMOVE_H_INCLUDED
#define FPA_DINAM_REMOVE_H_INCLUDED

struct aluno{
    float matricula;
    char nome[50];
    float cra;
    int ano; // ano de ingresso
};
typedef struct aluno Aluno;


typedef struct fila * Fila;

Fila cria_fila();

int fila_vazia(Fila f);

int insere_fim(Fila f, struct aluno A);

int remove_ord(Fila f, struct aluno *A);

int get_pos(Fila f, int pos, struct aluno *A);

int esvazia_fila(Fila f);

void libera_fila(Fila *f);

#endif // FPA_DINAM_REMOVE_H_INCLUDED
