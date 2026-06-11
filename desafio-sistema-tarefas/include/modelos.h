#ifndef MODELOS_H
#define MODELOS_H

// Representa o nivel/cargo de uma pessoa
typedef enum {
    JUNIOR = 1,
    PLENO  = 2,
    SENIOR = 3
} Nivel;

// Pessoa cadastrada no sistema
typedef struct {
    int id;
    char nome[50];
    char email[75];
    Nivel nivel;
} pessoa;

// Tarefa cadastrada no sistema
typedef struct {
    int id;
    char titulo[50];
    char descricao[75];
    int prioridade;
    int status;
    int dificuldade;          // 1 = Baixa, 2 = Media, 3 = Alta
    int idPessoaVinculada;    // -1 = sem pessoa vinculada
} tarefa;

#endif
