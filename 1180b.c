#include <stdio.h>

int main() {
    int N;
    int X[1000];

    int *atual;
    int *menor;

    if (scanf("%d", &N) != 1) return 1;

    atual = X; 
    for ( ; atual < (X + N); atual++ ) {
        if (scanf("%d", atual) != 1) return 1;
    }

    menor = X;
    atual = X + 1; 

    for ( ; atual < (X + N); atual++ ) {
        if ( *atual < *menor ) {
            menor = atual;
        }
    }

    int menorvalor = *menor;
    int posicao = (int)(menor - X); 

    printf("Menor valor: %d\n", menorvalor );
    printf("Posicao: %d\n", posicao );

    return 0;
}
