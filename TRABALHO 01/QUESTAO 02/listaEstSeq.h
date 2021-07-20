#define MAX 10

typedef struct lista *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, char elem);
int remove_ord (Lista lst, char elem);
int get_pos(Lista lst, int pos, char *elem);
void esvaziar_lista(Lista lst);
int menor_valor(Lista lst);
int tamanho_lista(Lista lst);
int remove_pares(Lista lst);
int intercalar_lista(Lista lst1, Lista lst2, Lista lst3);
