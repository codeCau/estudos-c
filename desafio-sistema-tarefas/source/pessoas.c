#include <stdio.h>
#include <string.h>

#include "dados.h"
#include "pessoas.h"
#include "tarefas.h"
#include "validacoes.h"

void cadastrarPessoa() {
    if (totalPessoas >= MAX) {
        printf("\nLimite maximo de pessoas atingido!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        getchar();
        return;
    }

    printf("\n===== CADASTRO DE PESSOA =====\n");

    printf("Nome: ");
    while (getchar() != '\n');
    fgets(pessoas[totalPessoas].nome, 50, stdin);
    pessoas[totalPessoas].nome[strcspn(pessoas[totalPessoas].nome, "\n")] = '\0';

    if (verificacao(pessoas[totalPessoas].nome) == 1) {
        printf("Nome nao pode ser vazio!\n");
        printf("Pressione enter para tentar novamente\n");
        getchar();
        return;
    }

    printf("Email: ");
    fgets(pessoas[totalPessoas].email, 75, stdin);
    pessoas[totalPessoas].email[strcspn(pessoas[totalPessoas].email, "\n")] = '\0';

    if (validarEmail(pessoas[totalPessoas].email) == 0) {
        printf("\nEmail invalido! O email deve conter '@' e terminar com '.com' ou '.br'.\n");
        printf("Pressione enter para tentar novamente\n");
        getchar();
        return;
    }

    int nivelEscolhido;

    printf("Nivel:\n");
    printf("1 - Junior\n");
    printf("2 - Pleno\n");
    printf("3 - Senior\n");
    printf("Opcao: ");
    scanf("%d", &nivelEscolhido);

    while (nivelEscolhido < 1 || nivelEscolhido > 3) {
        printf("Nivel invalido! Digite 1, 2 ou 3: ");
        scanf("%d", &nivelEscolhido);
    }

    pessoas[totalPessoas].nivel = (Nivel)nivelEscolhido;
    pessoas[totalPessoas].id = proximoIdPessoa;

    proximoIdPessoa++;
    totalPessoas++;

    printf("\nPessoa cadastrada com sucesso!\n");
    printf("Pressione enter para voltar\n");
    getchar();
}

void listarPessoas() {
    printf("\nListagem de pessoas\n");

    if (totalPessoas == 0) {
        printf("Nenhuma pessoa cadastrada!\n");
        getchar();
        return;
    }

    for (int i = 0; i < totalPessoas; i++) {
        printf("--------------------------\n");
        printf("ID: %d\n", pessoas[i].id);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Email: %s\n", pessoas[i].email);
        printf("Nivel: ");
        mostrarNivel(pessoas[i].nivel);
        printf("\n--------------------------\n");
    }

    getchar();
}

void vincularPessoa() {
    if (totalPessoas == 0) {
        printf("\nNenhuma pessoa cadastrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    if (totalTarefas == 0) {
        printf("\nNenhuma tarefa cadastrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    int idPessoa;
    int idTarefa;
    int indicePessoa;
    int indiceTarefa;

    printf("===== VINCULAR PESSOA A TAREFA =====\n");

    printf("ID da pessoa: ");
    scanf("%d", &idPessoa);

    indicePessoa = verIDPessoa(idPessoa);

    if (indicePessoa == -1) {
        printf("\nPessoa nao encontrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    printf("ID da tarefa: ");
    scanf("%d", &idTarefa);

    indiceTarefa = verID(idTarefa);

    if (indiceTarefa == -1) {
        printf("\nTarefa nao encontrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    if (podePegarTarefa(pessoas[indicePessoa], tarefas[indiceTarefa]) == 0) {
        printf("\n[ERRO] %s (", pessoas[indicePessoa].nome);
        mostrarNivel(pessoas[indicePessoa].nivel);
        printf(") nao pode pegar esta tarefa!\n");
        printf("Dificuldade da tarefa: ");
        mostrarDificuldade(indiceTarefa);
        printf("\nJunior aceita ate dificuldade 1, Pleno ate 2, Senior ate 3.\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    tarefas[indiceTarefa].idPessoaVinculada = pessoas[indicePessoa].id;

    printf("\n%s vinculado(a) a tarefa '%s' com sucesso!\n",
           pessoas[indicePessoa].nome,
           tarefas[indiceTarefa].titulo);

    printf("Pressione enter para voltar\n");
    getchar();
}

void mostrarNivel(Nivel nivel) {
    switch (nivel) {
        case JUNIOR:
            printf("Junior");
            break;

        case PLENO:
            printf("Pleno");
            break;

        case SENIOR:
            printf("Senior");
            break;

        default:
            printf("N/A");
            break;
    }
}

int podePegarTarefa(pessoa p, tarefa t) {
    return (t.dificuldade <= (int)p.nivel);
}

int verIDPessoa(int idBuscado) {
    for (int i = 0; i < totalPessoas; i++) {
        if (idBuscado == pessoas[i].id) {
            return i;
        }
    }

    return -1;
}

int buscarPessoaVerify(char texto[]) {
    for (int i = 0; i < totalPessoas; i++) {
        if (strcmp(texto, pessoas[i].nome) == 0) {
            return i;
        }
    }

    return -1;
}
