void validarSudoku(int matriz[9][9]) {
    int i, j, k, l, m;

    for (i = 0; i < 9; i++) {
        int nums[10] = {0};
        for (j = 0; j < 9; j++) {
            nums[matriz[i][j]]++;
        }
        for (k = 1; k <= 9; k++) {
            if (nums[k] != 1) {
                printf("NAO\n");
                return;
            }
        }
    }

    for (j = 0; j < 9; j++) {
        int nums[10] = {0};
        for (i = 0; i < 9; i++) {
            nums[matriz[i][j]]++;
        }
        for (k = 1; k <= 9; k++) {
            if (nums[k] != 1) {
                printf("NAO\n");
                return;
            }
        }
    }

    for (k = 0; k < 3; k++) {
        for (l = 0; l < 3; l++) {
            int nums[10] = {0};
            for (i = k * 3; i < k * 3 + 3; i++) {
                for (j = l * 3; j < l * 3 + 3; j++) {
                    nums[matriz[i][j]]++;
                }
            }
            for (int m = 1; m <= 9; m++) {
                if (nums[m] != 1) {
                    printf("NAO\n");
                    return;
                }
            }
        }
    }

    printf("SIM\n");
}

int main() {
    int n, k, i, j;
    int matriz[9][9];

    scanf("%d", &n);

    for (k = 1; k <= n; k++) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        validarSudoku(matriz);
        printf("\n");
    }

    return 0;
}
