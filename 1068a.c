#include <stdio.h>
#include <string.h>

int main() {
    char expr[1005]; 

    while (fgets(expr, sizeof(expr), stdin)) {
        int cont = 0;
        int correto = 1;

        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '(') {
                cont++;
            } else if (expr[i] == ')') {
                if (cont == 0) { 
                    correto = 0;
                    break;
                }
                cont--;
            }
        }

        if (cont != 0) 
            correto = 0;

        if (correto)
            printf("correct\n");
            
        else
            printf("incorrect\n");
    }

    return 0;
}
