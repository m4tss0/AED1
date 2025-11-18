#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d", &N);

    int *fila = (int*) malloc(N * sizeof(int));
    if (fila == NULL) return 1; 

    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &M);

    char *removido = (char*) calloc(100001, sizeof(char));
    if (removido == NULL) {
        free(fila);
        return 1;
    }

    for (int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        removido[id] = 1;
    }

    int nsaiu = 1;
    for (int i = 0; i < N; i++) {
        if (!removido[fila[i]]) {
            if (!nsaiu) printf(" ");
            printf("%d", fila[i]);
            nsaiu = 0;
        }
    }
    printf("\n");
    free(fila);
    free(removido);

    return 0;
}
