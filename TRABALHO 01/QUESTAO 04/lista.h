typedef struct no * Lista;

Lista cria_lista();
int lista_vazia(Lista li);
int insere_elem(Lista li, double elem);
int insere_lista3(Lista li, double elem);
int remove_elem(Lista li, double elem);
int maior_elem(Lista li);
int tamanho_lista(Lista li);
Lista intercala_lista(Lista li, Lista li2);
int iguala_lista(Lista li, Lista li2);
int obtem_elem(Lista li, int pos, double *elem);
void limpa_lista(Lista li);
