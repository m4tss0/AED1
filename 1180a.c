#include <stdio.h>
 
int main() {
    int N;
    int X[1000];
    int menorvalor, posicao;

    scanf(" %d", &N);

    for( int i = 0; i < N; i++ ){
        scanf( "%d", &X[i] );
    }

    menorvalor = X[0];
    posicao = 0;

    for( int i = 1; i < N; i++ ){
        if( X[i] < menorvalor ){
            menorvalor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menorvalor );
    printf("Posicao: %d\n", posicao );

    return 0;
}
