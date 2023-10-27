// Gabriel da Fonseca Nunes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_CHAIN 100

void print_pharse(char chain[MAX_CHAIN]){
    for (int i = 0; chain[i] != '\0'; i++){
        chain[i]  = isupper(chain[i]) ? tolower(chain[i]) : toupper(chain[i]); 
    }
    printf("%s", chain);
}

int main(int argc, char const *argv[]){
    char pharse[MAX_CHAIN];
    fgets(pharse, MAX_CHAIN, stdin);
    fflush(stdin);

    print_pharse(pharse);
    return 0;
}