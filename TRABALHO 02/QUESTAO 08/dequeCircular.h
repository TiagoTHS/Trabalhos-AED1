typedef struct no * Deque;

Deque cria_deque();
int deque_vazio(Deque);
int insere_final(Deque *, char);
int remove_inicio(Deque *, char *);
int remove_final(Deque *, char *);
int insere_inicio(Deque *, char);
int apaga_deque(Deque *);
int get_posicao(Deque d, int, char *);
