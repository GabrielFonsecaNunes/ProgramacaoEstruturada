// Gabriel da Fonseca Nunes
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Definindo o tipo de dados Conjunto
typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
} Conjunto;

// Função para criar um Conjunto com base em um vetor
Conjunto conjunto(int vet[], int size) {
    Conjunto novoConjunto;
    novoConjunto.tamanho = 0;

    for (int i = 0; i < size; i++) {
        int elemento = vet[i];
        int pertence = 0;

        // Verifica se o elemento já pertence ao conjunto
        for (int j = 0; j < novoConjunto.tamanho; j++) {
            if (novoConjunto.elementos[j] == elemento) {
                pertence = 1;
                break;
            }
        }

        // Se o elemento não pertence, adiciona ao conjunto
        if (!pertence) {
            novoConjunto.elementos[novoConjunto.tamanho] = elemento;
            novoConjunto.tamanho++;
        }
    }

    return novoConjunto;
}

// Função para realizar a união de dois Conjuntos
Conjunto conjunto_uniao(Conjunto A, Conjunto B) {
    Conjunto uniao;
    uniao.tamanho = 0;

    // Adiciona todos os elementos de A à união
    for (int i = 0; i < A.tamanho; i++) {
        uniao.elementos[uniao.tamanho] = A.elementos[i];
        uniao.tamanho++;
    }

    // Adiciona os elementos de B que não pertencem a A
    for (int i = 0; i < B.tamanho; i++) {
        int elemento = B.elementos[i];
        int pertence = 0;

        for (int j = 0; j < A.tamanho; j++) {
            if (A.elementos[j] == elemento) {
                pertence = 1;
                break;
            }
        }

        if (!pertence) {
            uniao.elementos[uniao.tamanho] = elemento;
            uniao.tamanho++;
        }
    }

    return uniao;
}

// Função para verificar se um elemento pertence a um Conjunto
char conjunto_pertence(int a, Conjunto A) {
    for (int i = 0; i < A.tamanho; i++) {
        if (A.elementos[i] == a) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vetA[] = {1, 2, 3, 4, 5};
    int vetB[] = {4, 5, 6, 7, 8};
    int tamanhoA = 5;
    int tamanhoB = 5;

    Conjunto A = conjunto(vetA, tamanhoA);
    Conjunto B = conjunto(vetB, tamanhoB);

    Conjunto uniaoAB = conjunto_uniao(A, B);

    printf("Conjunto A: ");
    for (int i = 0; i < A.tamanho; i++) {
        printf("%d ", A.elementos[i]);
    }

    printf("\nConjunto B: ");
    for (int i = 0; i < B.tamanho; i++) {
        printf("%d ", B.elementos[i]);
    }

    printf("\nUnião de A e B: ");
    for (int i = 0; i < uniaoAB.tamanho; i++) {
        printf("%d ", uniaoAB.elementos[i]);
    }

    printf("\n");

    int elemento = 3;
    char pertenceA = conjunto_pertence(elemento, A);
    char pertenceB = conjunto_pertence(elemento, B);

    if (pertenceA) {
        printf("%d pertence a A\n", elemento);
    } else {
        printf("%d não pertence a A\n", elemento);
    }

    if (pertenceB) {
        printf("%d pertence a B\n", elemento);
    } else {
        printf("%d não pertence a B\n", elemento);
    }

    return 0;
}
