#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        while (1) {
            int quero[1000];

            scanf("%d", &quero[0]);
            if (quero[0] == 0) {   
                printf("\n");
                break;
            }

            for (int i = 1; i < N; i++)
                scanf("%d", &quero[i]);

            int stack[1000];
            int top = -1;
            int prox = 1;        

            int possivel = 1;

            for (int i = 0; i < N; i++) {
                int alvo = quero[i];

                while (prox <= N && (top == -1 || stack[top] != alvo)) {
                    stack[++top] = prox++;
                }

                if (stack[top] == alvo) {
                    top--;  
                } else {
                    possivel = 0;
                    break;
                }
            }

            if (possivel)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
