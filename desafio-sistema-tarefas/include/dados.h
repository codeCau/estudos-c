#ifndef DADOS_H
#define DADOS_H

#include "constantes.h"
#include "modelos.h"

// Variaveis globais declaradas com extern.
// A criacao real delas fica no arquivo src/dados.c.
extern tarefa tarefas[MAX];
extern pessoa pessoas[MAX];

extern int opcao;
extern int totalTarefas;
extern int totalPessoas;
extern int proximoIdTarefa;
extern int proximoIdPessoa;

#endif
