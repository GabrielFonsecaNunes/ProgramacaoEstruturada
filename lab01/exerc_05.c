// Gabriel da Fonseca Nunes 11201921456
#include <stdio.h>

// lê n inteiros fornecidos pelo usuário e armazena -os no vetor entrada
void le_vetor(int entrada[], int n){
    for(int i = 0; i < n; i++){
        printf("Informe o valor v[%d]: ", i);
        scanf("%d", &entrada[i]);
    }
}
// retorna o valor mínimo do vetor v que tem n elementos
int minimo(int v[], int n){
    int min = v[0];
    for(int i = 1; i <= n; i++){
        v[i] < min ? min = v[i] : min;
    }
    return min;
}
// retorna o valor máximo do vetor v que tem n elementos
int maximo(int v[], int n) {
    int max = v[0];
    for(int i = 1; i < n; i++){
        v[i] > max ? max = v[i] : max;
    }
    return max;
}
// retorna a média dos elementos guardados em um vetor v de n elementos
double media(int v[], int n){
    int soma;
    for(int i = 0; i < n; i++){
        soma += v[i];
    }
    double avg = (double) (soma / n);
    return avg;
}

void main(){
    int n;
    printf("Informe o tamanho do vetor:");
    scanf("%d", &n);

    int entrada[n];
    le_vetor(entrada, n);

    printf("Minimo: %d\n", minimo(entrada, n));
    printf("Maximo: %d\n", maximo(entrada, n));
    printf("Media: %f", media(entrada, n));
}