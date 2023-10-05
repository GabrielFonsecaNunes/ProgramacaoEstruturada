// Gabriel da Fonseca Nunes 11201921456
#include <stdio.h>

void produto_hadamard(double u[], double v[], double resultado[], int len) {
    for(int i = 0; i < len; i++) {
        resultado[i] = u[i] * v[i];
        printf("resultado[%d]: %lf\n", i, resultado[i]);
    }
}

void main() {
    int n;
    printf("Informe o tamanho do vetor:");
    scanf("%d", &n);
    printf("\n");

    double u[n];
    double v[n];
    double resultado[n];   

    for (int i = 0; i < n; i++){
        printf("Informe o valor u[%d]:", i);
        scanf("%lf", &u[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++){
        printf("Informe o valor v[%d]:", i);
        scanf("%lf", &v[i]);
    }

    printf("\n");

    produto_hadamard(u, v, resultado, n);
}