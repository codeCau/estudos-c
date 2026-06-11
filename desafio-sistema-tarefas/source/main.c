#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "menus.h"
#include "tarefas.h"

int main() {
    do {
        system("cls");
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                subMenuGerenciar();
                getchar();
                break;

            case 2:
                system("cls");
                mostrarBusca();
                getchar();
                break;

            case 3:
                system("cls");
                listar();
                getchar();
                break;

            case 4:
                system("cls");
                listarP();
                getchar();
                break;

            case 5:
                system("cls");
                listarC();
                getchar();
                break;

            case 6:
                system("cls");
                listarPrior();
                getchar();
                break;

            case 7:
                system("cls");
                subMenuPessoas();
                getchar();
                break;

            case 0:
                printf("Sistema encerrado.\n");
                break;

            default:
                system("cls");
                printf("Escolha uma opcao existente.");
                printf("\nPressione enter para tentar novamente.");
                getchar();
                break;
        }
    } while (opcao != 0);

    return 0;
}
