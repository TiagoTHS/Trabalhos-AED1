struct cadastro{
    char placa[8];
    char tipo;
    double horario;
};typedef struct cadastro Cad;
typedef struct fila * Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, struct cadastro C);
int remove_inicio(Fila f, struct cadastro *C);
int tamanho_fila(Fila f);
void libera_fila(Fila *f);
int esvazia_fila(Fila f);
int le_topo(Fila f, struct cadastro *C);
