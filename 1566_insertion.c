#include <stdio.h>

void insertionSort(int *v, int n) {
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        int *v = (int*) malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            scanf("%d", &v[i]);

        insertionSort(v, N);

        for (int i = 0; i < N; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");

        free(v);
    }

    return 0;
}
