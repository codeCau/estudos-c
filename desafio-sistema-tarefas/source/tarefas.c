#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "tarefas.h"
#include "pessoas.h"
#include "validacoes.h"

void cadastrartarefa() {
    if (totalTarefas >= MAX) {
        printf("\nLimite maximo de tarefas atingido!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        getchar();
        return;
    }

    printf("\n===== CADASTRO DE TAREFA =====\n");

    printf("Nome da tarefa: ");
    while (getchar() != '\n');
    fgets(tarefas[totalTarefas].titulo, 50, stdin);
    tarefas[totalTarefas].titulo[strcspn(tarefas[totalTarefas].titulo, "\n")] = '\0';

    if (verificacao(tarefas[totalTarefas].titulo) == 1) {
        printf("Nome nao pode ser vazio!\n");
        printf("Pressione enter para tentar novamente\n");
        getchar();
        return;
    }

    printf("Descricao: ");
    fgets(tarefas[totalTarefas].descricao, 50, stdin);
    tarefas[totalTarefas].descricao[strcspn(tarefas[totalTarefas].descricao, "\n")] = '\0';

    if (verifDesc(tarefas[totalTarefas].descricao) == 1) {
        printf("A descricao nao pode estar vazia!\n");
        printf("Pressione enter para tentar novamente\n");
        getchar();
        return;
    }

    lerPrioridade(totalTarefas);
    lerDificuldade(totalTarefas);

    tarefas[totalTarefas].status = 0;
    tarefas[totalTarefas].id = proximoIdTarefa;
    tarefas[totalTarefas].idPessoaVinculada = -1;

    proximoIdTarefa++;
    totalTarefas++;

    printf("\nTarefa cadastrada com sucesso!\n");
    printf("Pressione enter para voltar\n");
    getchar();
}

void mostrarBusca() {
    char nomeBuscado[50];
    int indice;

    printf("Escreva o nome da tarefa: ");
    while (getchar() != '\n');
    fgets(nomeBuscado, 50, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    indice = buscarVerify(nomeBuscado);

    if (indice == -1) {
        printf("\nTarefa nao encontrada!\n");
        getchar();
        return;
    }

    printf("\n---------------------\n");
    printf("Nome: %s\n", tarefas[indice].titulo);
    printf("---------------------\n");
    printf("ID: %d\n", tarefas[indice].id);
    printf("---------------------\n");
    printf("Prioridade: ");
    mostrarPrior(indice);
    printf("\n---------------------\n");
    printf("Dificuldade: ");
    mostrarDificuldade(indice);
    printf("\n---------------------\n");
    printf("Status: ");
    mostrarStatus(indice);
    printf("\n---------------------\n");
    printf("Descricao: %s\n", tarefas[indice].descricao);

    if (tarefas[indice].idPessoaVinculada != -1) {
        int indicePessoa = verIDPessoa(tarefas[indice].idPessoaVinculada);

        if (indicePessoa != -1) {
            printf("---------------------\n");
            printf("Responsavel: %s (", pessoas[indicePessoa].nome);
            mostrarNivel(pessoas[indicePessoa].nivel);
            printf(")\n");
        }
    }

    printf("---------------------\n");

    getchar();
}

void listar() {
    printf("\nListagem de tarefas\n");

    if (totalTarefas == 0) {
        system("cls");
        printf("Nenhuma tarefa cadastrada!\n");
        getchar();
        return;
    }

    for (int i = 0; i < totalTarefas; i++) {
        printf("--------------------------\n");
        printf("%d - %s\n", i + 1, tarefas[i].titulo);
        printf("ID: %d ", tarefas[i].id);

        printf("\nPrioridade: ");
        mostrarPrior(i);

        printf("\nDificuldade: ");
        mostrarDificuldade(i);

        printf("\nStatus: ");
        mostrarStatus(i);

        printf("\nDescricao: %s\n", tarefas[i].descricao);

        if (tarefas[i].idPessoaVinculada != -1) {
            int indicePessoa = verIDPessoa(tarefas[i].idPessoaVinculada);

            if (indicePessoa != -1) {
                printf("Responsavel: %s (", pessoas[indicePessoa].nome);
                mostrarNivel(pessoas[indicePessoa].nivel);
                printf(")\n");
            }
        }

        printf("--------------------------\n");
    }

    getchar();
}

void listarP() {
    printf("\nListagem de tarefas pendentes\n");

    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada!\n");
        getchar();
        return;
    }

    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].status != 1) {
            printf("--------------------------\n");
            printf("%d - %s\n", i + 1, tarefas[i].titulo);
            printf("ID: %d \n", tarefas[i].id);

            printf("Prioridade: ");
            mostrarPrior(i);

            printf("\nDificuldade: ");
            mostrarDificuldade(i);

            printf("\nStatus: ");
            mostrarStatus(i);

            printf("\nDescricao: %s\n", tarefas[i].descricao);
            printf("--------------------------\n");
        }
    }

    getchar();
}

void listarC() {
    printf("\nListagem de tarefas concluidas\n");

    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada!\n");
        getchar();
        return;
    }

    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].status != 0) {
            printf("--------------------------\n");
            printf("%d - %s\n", i + 1, tarefas[i].titulo);
            printf("ID: %d \n", tarefas[i].id);

            printf("Prioridade: ");
            mostrarPrior(i);

            printf("\nDificuldade: ");
            mostrarDificuldade(i);

            printf("\nStatus: ");
            mostrarStatus(i);

            printf("\nDescricao: %s\n", tarefas[i].descricao);
            printf("--------------------------\n");
        }
    }

    getchar();
}

void editartarefa() {
    char nomeBuscado[50];
    int indice;

    printf("\n===== EDITAR TAREFA =====\n");
    printf("Nome da tarefa a editar: ");
    while (getchar() != '\n');
    fgets(nomeBuscado, 50, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    indice = buscarVerify(nomeBuscado);

    if (indice == -1) {
        printf("\nTarefa nao encontrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    printf("\n--- Dados atuais ---\n");
    printf("Nome: %s\n", tarefas[indice].titulo);
    printf("ID: %d\n", tarefas[indice].id);
    printf("Status: %d\n", tarefas[indice].status);
    printf("--------------------\n");

    printf("\n--- Novo status ---\n");
    lerStatus(indice);

    printf("\nTarefa editada com sucesso!\n");
    printf("Pressione enter para voltar\n");
    getchar();
}

void editarID() {
    int idBuscado;
    int indice;

    printf("Escreva o ID da tarefa que voce quer editar o status: ");
    scanf("%d", &idBuscado);

    indice = verID(idBuscado);

    if (indice == -1) {
        printf("\nTarefa nao encontrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    lerStatus(indice);
}

void removertarefa() {
    char nomeBuscado[50];
    int indice;

    printf("\n===== REMOVER TAREFA =====\n");
    printf("Nome da tarefa a remover: ");
    while (getchar() != '\n');
    fgets(nomeBuscado, 50, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    indice = buscarVerify(nomeBuscado);

    if (indice == -1) {
        printf("\nTarefa nao encontrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    printf("\nRemovendo: %s\n", tarefas[indice].titulo);

    for (int i = indice; i < totalTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    totalTarefas--;

    printf("Tarefa removida com sucesso!\n");
    printf("Pressione enter para voltar\n");
    getchar();
}

void removerID() {
    int idBuscado;
    int indice;

    printf("Escreva o ID da tarefa que voce quer remover: ");
    scanf("%d", &idBuscado);

    indice = verID(idBuscado);

    if (indice == -1) {
        printf("\nTarefa nao encontrada!\n");
        printf("Pressione enter para voltar\n");
        getchar();
        return;
    }

    printf("\nRemovendo: %s\n", tarefas[indice].titulo);

    for (int i = indice; i < totalTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    totalTarefas--;

    printf("Tarefa removida com sucesso!\n");
    printf("Pressione enter para voltar\n");
    getchar();
}

void listarPrior() {
    int maiorPrioridade = 0;

    printf("\nListagem de tarefas de maior prioridade\n");

    if (totalTarefas == 0) {
        printf("Nenhuma tarefa cadastrada!\n");
        getchar();
        return;
    }

    for (int i = 0; i < totalTarefas; i++) {
        if (maiorPrioridade < tarefas[i].prioridade) {
            maiorPrioridade = tarefas[i].prioridade;
        }
    }

    for (int i = 0; i < totalTarefas; i++) {
        if (tarefas[i].prioridade == maiorPrioridade) {
            printf("--------------------------\n");
            printf("%d - %s\n", i + 1, tarefas[i].titulo);
            printf("ID: %d \n", tarefas[i].id);

            printf("Prioridade: ");
            mostrarPrior(i);

            printf("\nDificuldade: ");
            mostrarDificuldade(i);

            printf("\nStatus: ");
            mostrarStatus(i);

            printf("\nDescricao: %s\n", tarefas[i].descricao);
            printf("--------------------------\n");
        }
    }

    getchar();
    getchar();
}

void lerStatus(int i) {
    printf("Escolha o status\n");
    printf("Digite 1 para Concluido\n");
    printf("Digite 0 para Pendente: ");
    scanf("%d", &tarefas[i].status);

    while (tarefas[i].status != 0 && tarefas[i].status != 1) {
        printf("Status invalido!\n");
        printf("Digite 1 para Concluido\n");
        printf("Digite 0 para Pendente: ");
        scanf("%d", &tarefas[i].status);
    }
}

void lerPrioridade(int i) {
    printf("Prioridade da tarefa:\n");
    printf("1 - Baixa\n");
    printf("2 - Media\n");
    printf("3 - Alta\n");
    scanf("%d", &tarefas[i].prioridade);

    while (tarefas[i].prioridade < 1 || tarefas[i].prioridade > 3) {
        printf("Prioridade invalida! Digite 1, 2 ou 3: ");
        scanf("%d", &tarefas[i].prioridade);
    }
}

void lerDificuldade(int i) {
    printf("Dificuldade da tarefa:\n");
    printf("1 - Baixa\n");
    printf("2 - Media\n");
    printf("3 - Alta\n");
    scanf("%d", &tarefas[i].dificuldade);

    while (tarefas[i].dificuldade < 1 || tarefas[i].dificuldade > 3) {
        printf("Dificuldade invalida! Digite 1, 2 ou 3: ");
        scanf("%d", &tarefas[i].dificuldade);
    }
}

void mostrarStatus(int i) {
    if (tarefas[i].status == 0) {
        printf("Pendente");
    }

    if (tarefas[i].status == 1) {
        printf("Concluida");
    }
}

void mostrarPrior(int i) {
    if (tarefas[i].prioridade == 1) {
        printf("Baixa");
    }

    if (tarefas[i].prioridade == 2) {
        printf("Media");
    }

    if (tarefas[i].prioridade == 3) {
        printf("Alta");
    }
}

void mostrarDificuldade(int i) {
    switch (tarefas[i].dificuldade) {
        case 1:
            printf("Baixa");
            break;

        case 2:
            printf("Media");
            break;

        case 3:
            printf("Alta");
            break;

        default:
            printf("N/A");
            break;
    }
}

int buscarVerify(char texto[]) {
    for (int i = 0; i < totalTarefas; i++) {
        if (strcmp(texto, tarefas[i].titulo) == 0) {
            return i;
        }
    }

    return -1;
}

int verID(int idBuscado) {
    for (int i = 0; i < totalTarefas; i++) {
        if (idBuscado == tarefas[i].id) {
            return i;
        }
    }

    return -1;
}
