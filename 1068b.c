#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char dado;
    struct Node *prox;
} Node;

typedef struct {
    Node *topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = NULL;
}

int pilha_vazia(Pilha *p) {
    return (p->topo == NULL);
}

void push(Pilha *p, char c) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    if (pilha_vazia(p))
        return 0;   

    Node *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
    return 1;
}

void limpa(Pilha *p) {
    while (!pilha_vazia(p))
        pop(p);
}

int main() {
    char expr[1005];

    while (fgets(expr, sizeof(expr), stdin)) {
        Pilha p;
        inicializa(&p);
        int correto = 1;

        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                push(&p, '(');
            } 
            else if (expr[i] == ')') {
                if (!pop(&p)) {  
                    correto = 0;
                    break;
                }
            }
        }

        if (!pilha_vazia(&p))
            correto = 0;

        if (correto)
            printf("correct\n");
        else
            printf("incorrect\n");

        limpa(&p);
    }

    return 0;
}
