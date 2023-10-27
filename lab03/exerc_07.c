// Gabriel da Fonseca Nunes 112019456
#include <stdio.h>
#include <stdlib.h>

// Definindo o tipo de dados Matriz
typedef struct {
    int **elementos;
    int linhas;
    int colunas;
} Matriz;

// Função para ler uma matriz quadrada de dimensões n × n
Matriz matriz_le(int n) {
    Matriz novaMatriz;
    novaMatriz.linhas = n;
    novaMatriz.colunas = n;

    novaMatriz.elementos = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        novaMatriz.elementos[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Digite os elementos da matriz (%d x %d):\n", n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &novaMatriz.elementos[i][j]);
        }
    }

    return novaMatriz;
}

// Função para multiplicar duas matrizes
Matriz matriz_multiplica(Matriz A, Matriz B) {
    Matriz resultado;
    resultado.linhas = A.linhas;
    resultado.colunas = B.colunas;

    resultado.elementos = (int **)malloc(resultado.linhas * sizeof(int *));
    for (int i = 0; i < resultado.linhas; i++) {
        resultado.elementos[i] = (int *)malloc(resultado.colunas * sizeof(int));
    }

    if (A.colunas != B.linhas) {
        printf("Erro: o número de colunas da matriz A deve ser igual ao número de linhas da matriz B.\n");
        // Aqui você pode decidir como tratar o erro, retornar uma matriz vazia ou usar outro mecanismo de tratamento de erros.
        exit(1);
    }

    for (int i = 0; i < resultado.linhas; i++) {
        for (int j = 0; j < resultado.colunas; j++) {
            resultado.elementos[i][j] = 0;
            for (int k = 0; k < A.colunas; k++) {
                resultado.elementos[i][j] += A.elementos[i][k] * B.elementos[k][j];
            }
        }
    }

    return resultado;
}

// Função para imprimir uma matriz
void matriz_imprime(Matriz M) {
    for (int i = 0; i < M.linhas; i++) {
        for (int j = 0; j < M.colunas; j++) {
            printf("%d\t", M.elementos[i][j]);
        }
        printf("\n");
    }
}

// Função para liberar a memória alocada para uma matriz
void matriz_libera(Matriz M) {
    for (int i = 0; i < M.linhas; i++) {
        free(M.elementos[i]);
    }
    free(M.elementos);
}

int main() {
    int n;
    printf("Digite a dimensão n da matriz quadrada: ");
    scanf("%d", &n);

    Matriz A = matriz_le(n);
    Matriz B = matriz_le(n);

    printf("Matriz A:\n");
    matriz_imprime(A);

    printf("Matriz B:\n");
    matriz_imprime(B);

    Matriz resultado = matriz_multiplica(A, B);

    printf("Resultado da multiplicação de A por B:\n");
    matriz_imprime(resultado);

    // Libera a memória alocada para as matrizes
    matriz_libera(A);
    matriz_libera(B);
    matriz_libera(resultado);

    return 0;
}
