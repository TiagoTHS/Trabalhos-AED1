typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int k, int ak);
int remove_ord(Lista *lst, int k);
int get_pos(Lista lst, int pos, int *k, int *ak);
int get_value(Lista lst, int k, int *ak);
int esvaziar_lista(Lista *lst);

