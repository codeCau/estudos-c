#include <stdio.h>
#include <stdlib.h>

#include "menus.h"
#include "tarefas.h"
#include "pessoas.h"

void menu() {
    printf("\n=============================\n");
    printf(" SISTEMA DE TAREFAS\n");
    printf("=============================\n");
    printf("1 - Gerenciar tarefas\n");
    printf("2 - Buscar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("4 - Listar pendentes\n");
    printf("5 - Listar concluidas\n");
    printf("6 - Maior prioridade\n");
    printf("7 - Gerenciar pessoas\n");
    printf("0 - Sair\n");
    printf("=============================\n");
    printf("Opcao: ");
}

void subMenuGerenciar() {
    int opcaoSubmenu;

    do {
        system("cls");
        printf("\n===== GERENCIAR TAREFAS =====\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Mudar status\n");
        printf("3 - Remover tarefa\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcaoSubmenu);

        switch (opcaoSubmenu) {
            case 1:
                system("cls");
                cadastrartarefa();
                getchar();
                break;

            case 2:
                system("cls");
                editarID();
                getchar();
                break;

            case 3:
                system("cls");
                removerID();
                getchar();
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcaoSubmenu != 0);
}

void subMenuPessoas() {
    int opcaoSubmenu;

    do {
        system("cls");
        printf("\n===== GERENCIAR PESSOAS =====\n");
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Listar pessoas\n");
        printf("3 - Vincular pessoa a tarefa\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Opcao: ");
        scanf("%d", &opcaoSubmenu);

        switch (opcaoSubmenu) {
            case 1:
                system("cls");
                cadastrarPessoa();
                getchar();
                break;

            case 2:
                system("cls");
                listarPessoas();
                getchar();
                break;

            case 3:
                system("cls");
                vincularPessoa();
                getchar();
                break;

            case 0:
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcaoSubmenu != 0);
}
