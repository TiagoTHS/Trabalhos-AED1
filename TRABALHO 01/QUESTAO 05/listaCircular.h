typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista);
int insere_final(Lista *, char);
int remove_inicio(Lista *, char *);
int tamanho(Lista);
int get_posicao(Lista, int, char *);
int insere_inicio(Lista *, char);
int remove_final(Lista *, char *);
int insere_posicao(Lista *, int, char);
int remove_posicao(Lista *, int, char *);
