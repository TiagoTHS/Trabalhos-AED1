#define MAX 15

typedef struct deque *Deque;

Deque cria_deque();
int deque_vazio(Deque d);
int deque_cheio(Deque d);
int insere_fim(Deque d, int elem);
int remove_ini(Deque d, int *elem);
int insere_ini(Deque d, int elem);
int remove_fim(Deque d, int *elem);
void apagar_deque(Deque *d);
