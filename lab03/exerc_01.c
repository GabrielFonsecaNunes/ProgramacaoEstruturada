// Gabriel da Fonseca Nunes 11201921456
#include <stdio.h>
#include <string.h>
#define MAX 100

void print_pharse(char frase[MAX], char v) {

    for(int i = 0; frase[i] != v; i++){
        printf("%c", frase[i]);
    }
    printf("\n");
}

void main() {
    char v;
    char frase[100];

    scanf("%c\n", &v);
    fflush(stdin);

    fgets(frase, 100, stdin);
    fflush(stdin);
    
    print_pharse(frase, v);
}