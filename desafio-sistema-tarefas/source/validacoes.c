#include <stdio.h>
#include <string.h>

#include "validacoes.h"

int verificacao(char texto[]) {
    if (strlen(texto) == 0) {
        printf("\nNome invalido\n");
        return 1;
    }

    return 0;
}

int verifDesc(char texto[]) {
    if (strlen(texto) == 0) {
        printf("\nDescricao invalida\n");
        return 1;
    }

    return 0;
}

int validarEmail(char email[]) {
    if (strchr(email, '@') == NULL) {
        return 0;
    }

    if (strstr(email, ".com") == NULL && strstr(email, ".br") == NULL) {
        return 0;
    }

    return 1;
}
