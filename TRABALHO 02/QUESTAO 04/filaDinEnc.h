#include "estrutura.h"

typedef struct fila *Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, Pessoa p);
int remove_ini(Fila f, Pessoa *p);
