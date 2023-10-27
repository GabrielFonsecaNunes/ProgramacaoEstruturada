// Gabriel da Fonseca Nunes
#include <stdio.h>
#include <string.h>

// Definindo a estrutura para a data
struct Data {
    int dia;
    int mes;
    int ano;
};

// Definindo a estrutura para o aluno
struct Aluno {
    char nome[100];
    struct Data dataNascimento;
    int ra;
};

// Função para cadastrar um aluno
void cadastrarAluno(struct Aluno alunos[], int *numAlunos) {
    if (*numAlunos < 100) {
        struct Aluno novoAluno;

        printf("Nome: ");
        scanf("%s", novoAluno.nome);
        printf("Dia de Nascimento: ");
        scanf("%d", &novoAluno.dataNascimento.dia);
        printf("Mês de Nascimento: ");
        scanf("%d", &novoAluno.dataNascimento.mes);
        printf("Ano de Nascimento: ");
        scanf("%d", &novoAluno.dataNascimento.ano);
        printf("RA: ");
        scanf("%d", &novoAluno.ra);

        alunos[*numAlunos] = novoAluno;
        (*numAlunos)++;
        printf("Aluno cadastrado com sucesso!\n");
    } else {
        printf("Limite de alunos atingido.\n");
    }
}

// Função para buscar alunos por nome
void buscarAlunoPorNome(struct Aluno alunos[], int numAlunos, char nomeBusca[]) {
    printf("Alunos com o nome/sobrenome \"%s\":\n", nomeBusca);

    for (int i = 0; i < numAlunos; i++) {
        if (strstr(alunos[i].nome, nomeBusca) != NULL) {
            printf("Nome: %s, Data de Nascimento: %d/%d/%d, RA: %d\n",
                   alunos[i].nome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].ra);
        }
    }
}

// Função para listar alunos com data de nascimento em um intervalo
void listarAlunosPorData(struct Aluno alunos[], int numAlunos, struct Data dataInicio, struct Data dataFim) {
    printf("Alunos com data de nascimento no intervalo de %d/%d/%d a %d/%d/%d:\n", dataInicio.dia, dataInicio.mes, dataInicio.ano, dataFim.dia, dataFim.mes, dataFim.ano);

    for (int i = 0; i < numAlunos; i++) {
        if (alunos[i].dataNascimento.ano > dataInicio.ano && alunos[i].dataNascimento.ano < dataFim.ano) {
            printf("Nome: %s, Data de Nascimento: %d/%d/%d, RA: %d\n",
                   alunos[i].nome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].ra);
        } else if (alunos[i].dataNascimento.ano == dataInicio.ano || alunos[i].dataNascimento.ano == dataFim.ano) {
            if (alunos[i].dataNascimento.mes > dataInicio.mes && alunos[i].dataNascimento.mes < dataFim.mes) {
                printf("Nome: %s, Data de Nascimento: %d/%d/%d, RA: %d\n",
                       alunos[i].nome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].ra);
            } else if (alunos[i].dataNascimento.mes == dataInicio.mes || alunos[i].dataNascimento.mes == dataFim.mes) {
                if (alunos[i].dataNascimento.dia >= dataInicio.dia && alunos[i].dataNascimento.dia <= dataFim.dia) {
                    printf("Nome: %s, Data de Nascimento: %d/%d/%d, RA: %d\n",
                           alunos[i].nome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano, alunos[i].ra);
                }
            }
        }
    }
}

int main() {
    struct Aluno alunos[100];
    int numAlunos = 0;

    int opcao;
    char nomeBusca[100];
    struct Data dataInicio, dataFim;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Buscar aluno por nome\n");
        printf("3. Listar alunos por data de nascimento\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAluno(alunos, &numAlunos);
                break;
            case 2:
                printf("Digite o nome/sobrenome a ser buscado: ");
                scanf("%s", nomeBusca);
                buscarAlunoPorNome(alunos, numAlunos, nomeBusca);
                break;
            case 3:
                printf("Digite a data de início (dia mês ano): ");
                scanf("%d %d %d", &dataInicio.dia, &dataInicio.mes, &dataInicio.ano);
                printf("Digite a data de fim (dia mês ano): ");
                scanf("%d %d %d", &dataFim.dia, &dataFim.mes, &dataFim.ano);
                listarAlunosPorData(alunos, numAlunos, dataInicio, dataFim);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}