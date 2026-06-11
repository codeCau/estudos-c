#ifndef TAREFAS_H
#define TAREFAS_H

void listarPrior();
void cadastrartarefa();
void mostrarBusca();
void listar();
void listarP();
void listarC();
void editartarefa();
void editarID();
void removertarefa();
void removerID();

void lerStatus(int i);
void lerPrioridade(int i);
void lerDificuldade(int i);

void mostrarStatus(int i);
void mostrarPrior(int i);
void mostrarDificuldade(int i);

int buscarVerify(char texto[]);
int verID(int idBuscado);

#endif
