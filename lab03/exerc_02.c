// Gabriel da Fonseca Nunes
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_CHAIN 100

void size_max_chain(char chain[MAX_CHAIN]){
    int max_chain_zero = 0;
    int sum = 0;

    for (int i = 0; chain[i] != '\0'; i++){
        if(chain[i] == '0'){
            for (int j = i; chain[j] == '0'; j++){
                sum += 1;
            }
        }
        max_chain_zero = sum > max_chain_zero ? sum: max_chain_zero;
        sum = 0;
    }

    printf("%i\n", max_chain_zero);
}

void main(){
    char chain[MAX_CHAIN];

    fgets(chain, MAX_CHAIN, stdin);

    size_max_chain(chain);
}