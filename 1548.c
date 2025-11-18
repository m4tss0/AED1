#include <stdio.h>

void insertsortdescresc(int v[], int n) {
    int i, j, atual;

    for (i = 1; i < n; i++) {
        atual = v[i];
        j = i - 1;

        while (j >= 0 && v[j] < atual) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = atual;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int M;
        scanf("%d", &M);

        int original[1000];
        int ordenado[1000];

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i]; 
        }

        insertsortdescresc(ordenado, M);

        int iguais = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i]) {
                iguais++;
            }
        }

        printf("%d\n", iguais);
    }

    return 0;
}
