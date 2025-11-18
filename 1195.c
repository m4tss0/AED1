#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int val) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = val;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int val) {
    if (raiz == NULL) return criarNo(val);
    if (val < raiz->valor)
        raiz->esq = inserir(raiz->esq, val);
    else if (val > raiz->valor)
        raiz->dir = inserir(raiz->dir, val);
    return raiz;
}

void prefixo(No* raiz, int *primeiro) {
    if (!raiz) return;
    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
    prefixo(raiz->esq, primeiro);
    prefixo(raiz->dir, primeiro);
}

void infixo(No* raiz, int *primeiro) {
    if (!raiz) return;
    infixo(raiz->esq, primeiro);
    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
    infixo(raiz->dir, primeiro);
}

void posfixo(No* raiz, int *primeiro) {
    if (!raiz) return;
    posfixo(raiz->esq, primeiro);
    posfixo(raiz->dir, primeiro);
    if (!(*primeiro)) printf(" ");
    printf("%d", raiz->valor);
    *primeiro = 0;
}

void liberarArvore(No* raiz) {
    if (!raiz) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);

    for (int c = 1; c <= C; c++) {
        int N;
        scanf("%d", &N);

        No* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int val;
            scanf("%d", &val);
            raiz = inserir(raiz, val);
        }

        printf("Case %d:\n", c);

        int primeiro = 1;
        printf("Pre.: ");
        prefixo(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("In..: ");
        infixo(raiz, &primeiro);
        printf("\n");

        primeiro = 1;
        printf("Post: ");
        posfixo(raiz, &primeiro);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
