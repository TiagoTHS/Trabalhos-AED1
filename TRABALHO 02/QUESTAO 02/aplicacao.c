#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilhaDinEncad.h"

int valida_escopo(char *s);
int conversao(char *s, char *ss);
int avalia_exp(char *s, int *total);

int main()
{
    char st[20], pf[20];
    int total, op, FLAG = 0;

    printf("Digite a expressao: ");
    scanf("%s", st);

    do{
        printf("\n----- Menu ----");
        printf("\n\n[1] Valida escopo da expressao\n[2] Conversao para pos-fixa\n[3] Avalia expressao\n[4] Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
        case 1:{
            if (valida_escopo(st) == 0)
                return -1;
            printf("\nEscopo sem problemas!\n");
        }break;
        case 2:{
            if (conversao(st, pf) == 0)
                return -1;
            printf("\nAssim ficou a expressao na forma pos-fixa: \n\n%s\n", pf);
            FLAG++;
        }break;
        case 3:{
            if (!FLAG){
                printf("\nPrimeiro faca a conversao para a forma pos-fixa\n");
            }
            else {
                printf("\nA partir da expressao : %s\n\n", pf);
                if (avalia_exp(pf, &total) == 0)
                    return -1;
                printf("\nO resultado final da expressao e: %d\n", total);
            }
        }
        }
    }while(op != 4);

    printf("Encerrando o programa...\n");

    return 0;
}

int valida_escopo(char *s){
    int i, r;
    Pilha P = cria_pilha();
    char top = 'x';
    char lx;
    int inv;
    int tp;

    for(i = 0; s[i] != '\0'; i++){
        r = le_topo(P, &tp, &inv, &top); // r == 0, pilha está vazia

        // Parte de abertura
        if(s[i] == '{'){
            if((top == '[' || top == '(')){
                printf("Precedencia nao e obedecida\n");
                return 0;
            }
            else
                empilha(&P, 1, 0, s[i]);
        }


        if (s[i] == '['){
            if((top == '(')){
                printf("Precedencia nao e obedecida\n");
                return 0;
            }
            else
                empilha(&P, 1, 0, s[i]);
        }


        if (s[i] == '(')
            empilha(&P, 1, 0, s[i]);

        // Parte de fechamento
        if(s[i] == '}'){
            if(top == '[' || top == '(' || r == 0){
                printf("Ordem dos fechamentos divergem da ordem das aberturas\n");
                return 0;
            }
            else
                desempilha(&P, &tp, &inv, &lx);
        }


        if (s[i] == ']'){
            if(top == '{' || top == '(' || r == 0){
                printf("Ordem dos fechamentos divergem da ordem das aberturas\n");
                return 0;
            }
            else
                desempilha(&P, &tp, &inv, &lx);
        }


        if (s[i] == ')'){
            if(top == '{' || top == '[' || r == 0){
                printf("Ordem dos fechamentos divergem da ordem das aberturas\n");
                return 0;
            }
            else
                desempilha(&P, &tp, &inv, &lx);
        }
    }

    return pilha_vazia(P);
}

int conversao(char *s, char *s2){
    int i, j = 0;
    Pilha P = cria_pilha();
    char top;
    char c;
    int inv;
    int tp;

    if (valida_escopo(s) != 1){
        printf("Escopo nao e valido para a conersao\n\n");
        return 0;
    }

    for(i = 0; s[i] != '\0'; i++){

        if(s[i] == '^'){
            while(le_topo(P, &tp, &inv, &top) && top == '^'){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == '*'){
            while(le_topo(P, &tp, &inv, &top) && (top == '^' || top == '*' || top == '/')){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == '/'){
            while(le_topo(P, &tp, &inv, &top) && (top == '^' || top == '*' || top == '/')){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == '+'){
            while(le_topo(P, &tp, &inv, &top) && (top == '^' || top == '*' || top == '/' || top == '+' || top == '-')){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == '-'){
            while(le_topo(P, &tp, &inv, &top) && (top == '^' || top == '*' || top == '/' || top == '+' || top == '-')){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == '('){
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == ')'){
            while(le_topo(P, &tp, &inv, &top) && top != '('){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }

            desempilha(&P, &tp, &inv, &c); // desempilha e ignora o parenteses de abertura
        }
        else if(s[i] == '['){
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == ']'){
            while(le_topo(P, &tp, &inv, &top) && top != '['){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }

            desempilha(&P, &tp, &inv, &c); // desempilha e ignora o colchete de abertura
        }
        else if(s[i] == '{'){
            empilha(&P, 1, 0, s[i]);
        }
        else if(s[i] == '}'){
            while(le_topo(P, &tp, &inv, &top) && top != '{'){
                desempilha(&P, &tp, &inv, &c);
                s2[j] = c;
                j++;
            }

            desempilha(&P, &tp, &inv, &c); // desempilha e ignora a chave de abertura
        }
        else{
            s2[j] = s[i];
            j++;
        }

    }

    while(desempilha(&P, &tp, &inv, &c)==1){
        s2[j] = c;
        j++;
    }

    return 1;
}

int avalia_exp(char *s, int *total){
    int i, res, valor, tp;
    int x1, x2;
    char c = 'x';
    Pilha P = cria_pilha();

    for(i = 0; s[i] != '\0'; i++){

        if(s[i] == '^'  || s[i] == '*'  || s[i] == '/'  || s[i] == '+'  || s[i] == '-' ){
            if (desempilha(&P,&tp,&x2,&c) == 0){
                printf("Erro ao desempilhar\n");
                return 0;
            }
            if (desempilha(&P,&tp,&x1,&c) == 0){
                printf("Numero de operandos nao e adequado\n");
                return 0;
            }

            if(s[i] == '^')
                res = pow(x1,x2);
            else if (s[i] == '*')
                res = x1 * x2;
            else if (s[i] == '/')
                res = x1 / x2;
            else if (s[i] == '+')
                res = x1 + x2;
            else
                res = x1 - x2;

            empilha(&P,0,res,c);
        }
        else if(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']' || s[i] == '{' || s[i] == '}')
            continue;
        else{
            printf("Digite o valor de '%c' na expressao: ", s[i]);
            setbuf(stdin, NULL);
            scanf("%d", &valor);
            empilha(&P,0,valor,c);
        }

    }

    desempilha(&P,&tp,total,&c);

    return 1;
}
