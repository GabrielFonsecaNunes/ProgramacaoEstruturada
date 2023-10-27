// Gabriel da Fonseca 11201921546 

#include <stdio.h>
#include <string.h>
#define MAX_CHAIN 100

// Função para verificar se a sequência 'v' está contida na sequência 's'
int is_in(char s[MAX_CHAIN], char v[MAX_CHAIN]) {
    int len_s = strlen(s);
    int len_v = strlen(v);

    for (int i = 0; i < len_s; i++) {
        if (s[i] == v[0]) {
            for (int j = 0; s[i + j] == v[j]; j++) {
                if (len_v == j) {
                    return 1; // Se 'v' estiver contida em 's', retorna 1 (true)
                }
            }
        }
    }

    return 0; // Se 'v' não estiver contida em 's', retorna 0 (false)
}

int main(int argc, char const *argv[]) {
    // Definindo vetores v e s
    char p[MAX_CHAIN]; 
    char s[MAX_CHAIN]; 

    fgets(p, MAX_CHAIN, stdin);
    fgets(s, MAX_CHAIN, stdin);

    // Verifica se 's' contém 'v' e imprime "SIM" ou "NAO" com base no resultado
    is_in(p, s) != 0 ? printf("SIM\n") : printf("NAO\n"); 
    return 0;
}
