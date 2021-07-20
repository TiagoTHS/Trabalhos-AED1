typedef struct no * Pilha; // Pilha aponta pro topo

Pilha cria_pilha();
int pilha_vazia(Pilha);
int empilha(Pilha *, int, int, char);
int desempilha(Pilha *, int *, int *, char *);
int le_topo(Pilha, int *, int *, char *);
int esvazia_pilha(Pilha *);
