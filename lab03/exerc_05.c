#include <stdio.h>
#include <string.h>

// Função para imprimir uma linha com quebra de linha a cada 80 caracteres
void printFormattedLine(const char *line) {
    int lineLength = strlen(line);

    for (int i = 0; i < lineLength; i++) {
        putchar(line[i]);
        if ((i + 1) % 80 == 0 || i == lineLength - 1) {
            putchar('\n');
        }
    }
}

int main() {
    char paragraph[1000]; // Tamanho máximo de um parágrafo
    char line[80];       // Tamanho máximo de uma linha

    printf("Digite o texto (Ctrl+D para encerrar a entrada):\n");

    while (fgets(paragraph, sizeof(paragraph), stdin) != NULL) {
        char *token = strtok(paragraph, "\n"); // Remover a quebra de linha

        while (token != NULL) {
            int tokenLength = strlen(token);

            if (tokenLength <= 80) {
                // O parágrafo já cabe em uma linha
                printFormattedLine(token);
            } else {
                // O parágrafo precisa ser quebrado em várias linhas
                int start = 0;
                int end = 80;

                while (start < tokenLength) {
                    strncpy(line, &token[start], end - start);
                    line[end - start] = '\0';
                    printFormattedLine(line);

                    start = end;
                    end = start + 80;
                }
            }

            token = strtok(NULL, "\n");
        }
    }

    return 0;
}
