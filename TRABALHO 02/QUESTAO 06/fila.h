struct cadastro{
    char nome[50];
    int orgao;
    int idade;
    int grau;
};typedef struct cadastro Cad;
typedef struct fila * Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_fim(Fila f, struct cadastro C);
int remove_inicio(Fila f, struct cadastro *C);
int tamanho_fila(Fila f);
int get_pos(Fila f, int pos, struct cadastro *C);
int esvazia_fila(Fila f);
void libera_fila(Fila *f);
