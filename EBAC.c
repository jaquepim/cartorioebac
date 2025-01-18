#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Fun��o para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fun��o para registrar um usu�rio
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

// Fun��o para consultar um registro
int consulta() {
    char cpf[40], arquivo[45], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%39s", cpf);
    limparBuffer();

    sprintf(arquivo, "%s.txt", cpf);

    FILE *file = fopen(arquivo, "r");
    if (file == NULL) {
        printf("Arquivo n�o localizado!\n");
        return 1;
    }

    printf("Essas s�o as informa��es do usu�rio:\n");
    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);

    return 0;
}

// Fun��o para deletar um registro
int deletar() {
    char cpf[40], arquivo[45];

    printf("Informe o CPF a ser deletado: ");
    scanf("%39s", cpf);
    limparBuffer();

    sprintf(arquivo, "%s.txt", cpf);

    if (remove(arquivo) == 0) {
        printf("Usu�rio deletado com sucesso.\n");
    } else {
        printf("Usu�rio n�o consta em sistema ou erro ao deletar.\n");
    }

    return 0;
}

// Fun��o principal
int main() {
    int opcao = 0;
    setlocale(LC_ALL, "Portuguese");

    while (1) {
        printf("Cart�rio da EBAC\n\n");
        printf("Escolha a op��o desejada do Menu:\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n");
        printf("\t4 - Sair\n");
        printf("Op��o: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inv�lida! Tente novamente.\n");
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
                printf("Essa op��o n�o est� dispon�vel!\n");
                break;
        }
    }

    return 0;
}
