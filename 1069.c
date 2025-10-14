#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

void extracao() {
    char mineracao[MAX_SIZE];

    if (scanf("%s", mineracao) != 1) {
        return;
    }

    int diamantes_frente = 0;
    int diamantes_extraidos = 0;

    for (int i = 0; mineracao[i] != '\0'; i++) {
        char c = mineracao[i];

        if (c == '<') {
            diamantes_frente++;;
        }
        
        else if (c == '>') {
            if (diamantes_frente > 0) {
                diamantes_extraidos++;
                diamantes_frente--;
            } 
        }
    }
    
    printf("%d\n", diamantes_extraidos);
}

int main() {
    int N;

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        extracao();
    }

    return 0;
}
