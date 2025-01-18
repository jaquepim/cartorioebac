#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para registrar um usuário
int registro() {
    char arquivo[45], cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%39s", cpf);
    limparBuffer();

    sprintf(arquivo, "%s.txt", cpf);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar arquivo.\n");
        return 1;
    }

    fprintf(file, "CPF: %s\n", cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%39s", nome);
    limparBuffer();

    file = fopen(arquivo, "a");
    fprintf(file, "Nome: %s\n", nome);
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%39s", sobrenome);
    limparBuffer();

    file = fopen(arquivo, "a");
    fprintf(file, "Sobrenome: %s\n", sobrenome);
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%39s", cargo);
    limparBuffer();

    file = fopen(arquivo, "a");
    fprintf(file, "Cargo: %s\n", cargo);
    fclose(file);

    printf("Registro salvo com sucesso!\n");
    return 0;
}

// Função para consultar um registro
int consulta() {
    char cpf[40], arquivo[45], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%39s", cpf);
    limparBuffer();

    sprintf(arquivo, "%s.txt", cpf);

    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Arquivo não localizado!\n");
        return 1;
    }

    printf("Essas são as informações do usuário:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);

    return 0;
}

// Função para deletar um registro
int deletar() {
    char cpf[40], arquivo[45];

    printf("Informe o CPF a ser deletado: ");
    scanf("%39s", cpf);
    limparBuffer();

    sprintf(arquivo, "%s.txt", cpf);

    if (remove(arquivo) == 0) {
        printf("Usuário deletado com sucesso.\n");
    } else {
        printf("Usuário não consta em sistema ou erro ao deletar.\n");
    }

    return 0;
}

// Função principal
int main() {
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");

    while (1) {
        printf("Cartório da EBAC\n\n");
        printf("Escolha a opção desejada do Menu:\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n");
        printf("Opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Tente novamente.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Essa opção não está disponível!\n");
                break;
        }
    }

    return 0;
}
