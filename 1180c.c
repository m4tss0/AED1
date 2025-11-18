#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *X;               
    int menorvalor, posicao;

    scanf("%d", &N);

    X = (int*) malloc(N * sizeof(int));
    if (X == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    menorvalor = X[0];
    posicao = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menorvalor) {
            menorvalor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menorvalor);
    printf("Posicao: %d\n", posicao);

    free(X);
    return 0;
}
