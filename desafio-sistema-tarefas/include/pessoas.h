#ifndef PESSOAS_H
#define PESSOAS_H

#include "modelos.h"

void cadastrarPessoa();
void listarPessoas();
void vincularPessoa();

void mostrarNivel(Nivel nivel);

int podePegarTarefa(pessoa p, tarefa t);
int verIDPessoa(int idBuscado);
int buscarPessoaVerify(char texto[]);

#endif
