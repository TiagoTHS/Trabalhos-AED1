#include "estrutura.h"

typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elem (Lista *lst, Pessoa p);
int remove_elem (Lista *lst, Pessoa p);
int menor_data(Lista *lst, Pessoa *p);
int maior_idade(Lista *lst, int local, Pessoa *p);
int obtem_elem(Lista lst, int pos, Pessoa *p);

