#define MAX 20
typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista);
int insere_final(Lista *, char *);
int tamanho(Lista);
int get_posicao(Lista, int, char *);
int altera_inicio(Lista *lst, int pos);
int altera_inicio_nome(Lista *lst, char *n);
int remove_soldado(Lista *lst, int pos, char *elem);
