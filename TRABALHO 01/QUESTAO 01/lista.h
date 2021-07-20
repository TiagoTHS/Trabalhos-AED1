typedef struct lista * Lista;


Lista cria_lista();

int lista_vazia(Lista lst);

int lista_cheia(Lista lst);

int insere_elem(Lista lst, float elem);

int remove_elem(Lista lst, float elem);

int get_pos(Lista lst, int posicao, float *elem);

int remove_impar(Lista lst);

int maior_elem(Lista lst, float *elem);

int tamanho_lista(Lista lst, int *tam);

int esvazia_lista(Lista lst);

Lista inverte_lista(Lista lst);

Lista concatena(Lista lst, Lista lst2);

void apaga_lista(Lista *lst);
