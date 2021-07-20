typedef struct no * Lista;


Lista cria_lista();

int lista_vazia(Lista lst);

int insere_elem(Lista *lst, int elem);

int remove_elem(Lista *lst, int elem);

int remove_todos(Lista *lst, int elem);

int remove_maior_elem(Lista *lst, int *elem);

int tamanho_lista(Lista lst);

int esvazia_lista(Lista *lst);

Lista inverte_lista(Lista lst);

int verifica_primos(int elemento); // Utilizada na função dos lista_primos

Lista primos_lista(Lista lst);

int obtem_valor_elem(Lista lst, int pos, int *elem);

void apaga_lista(Lista *lst);
