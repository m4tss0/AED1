#include <stdio.h>
#include <stdlib.h>

void validarSudoku(int *matriz) {
    int i, j, k, l, m;
    
    for (i = 0; i < 9; i++) {
        int *nums = (int *)calloc(10, sizeof(int));
        for (j = 0; j < 9; j++) {
            nums[matriz[i * 9 + j]]++;
        }
        for (k = 1; k <= 9; k++) {
            if (nums[k] != 1) {
                printf("NAO\n");
                free(nums);
                return;
            }
        }
        free(nums);
    }

    for (j = 0; j < 9; j++) {
        int *nums = (int *)calloc(10, sizeof(int));
        for (i = 0; i < 9; i++) {
            nums[matriz[i * 9 + j]]++;
        }
        for (k = 1; k <= 9; k++) {
            if (nums[k] != 1) {
                printf("NAO\n");
                free(nums);
                return;
            }
        }
        free(nums);
    }

    for (k = 0; k < 3; k++) {
        for (l = 0; l < 3; l++) {
            int *nums = (int *)calloc(10, sizeof(int));
            for (i = k * 3; i < k * 3 + 3; i++) {
                for (j = l * 3; j < l * 3 + 3; j++) {
                    nums[matriz[i * 9 + j]]++;
                }
            }
            for (m = 1; m <= 9; m++) {
                if (nums[m] != 1) {
                    printf("NAO\n");
                    free(nums);
                    return;
                }
            }
            free(nums);
        }
    }

    printf("SIM\n");
}

int main() {
    int n, k, i, j;
    scanf("%d", &n);
    
    for (k = 1; k <= n; k++) {
        int *matriz = (int *)malloc(9 * 9 * sizeof(int));
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &matriz[i * 9 + j]);
            }
        }

        printf("Instancia %d\n", k);
        validarSudoku(matriz);
        printf("\n");
        free(matriz);
    }

    return 0;
}
