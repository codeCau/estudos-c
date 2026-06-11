# Documentação Completa — Sistema de Gerenciamento de Tarefas em C

Este documento reúne o README do projeto, o relatório de implementações, o desenvolvimento inicial e o guia de separação do código em `include/` e `src/`.

---

# README do Projeto

Este projeto foi desenvolvido como parte de um desafio de programação em linguagem C, com o objetivo de criar um sistema de gerenciamento de tarefas funcionando totalmente pelo terminal.

O sistema permite cadastrar, listar, buscar, alterar, remover e organizar tarefas utilizando conceitos fundamentais da linguagem C, como `structs`, vetores, funções, menus, condicionais, laços de repetição e manipulação de strings.

## Objetivo do desafio

O desafio consistia em desenvolver um sistema capaz de organizar tarefas de uma equipe, permitindo o controle de informações como:

- ID da tarefa
- Título
- Descrição
- Prioridade
- Status

Além disso, o sistema deveria utilizar obrigatoriamente:

- `struct`
- vetor de structs
- funções
- menu com `switch`
- `fgets` para leitura de textos
- `strcmp` para comparações
- laços de repetição
- validações básicas
- manipulação correta de strings

## Funcionalidades principais

O sistema possui as seguintes funcionalidades:

1. Cadastrar tarefa
2. Listar todas as tarefas
3. Buscar tarefa pelo título
4. Alterar status da tarefa
5. Mostrar tarefas pendentes
6. Mostrar tarefas concluídas
7. Mostrar tarefa com maior prioridade
8. Remover tarefa pelo ID
9. Encerrar o sistema

## Estrutura da tarefa

Cada tarefa possui os seguintes campos:

```c
typedef struct {
    int id;
    char titulo[50];
    char descricao[75];
    int prioridade;
    int status;
    int dificuldade;
    int idPessoaVinculada;
} tarefa;
```

## Regras implementadas

### ID

Cada tarefa recebe um ID único gerado automaticamente pelo sistema.

### Prioridade

A prioridade da tarefa segue a seguinte regra:

| Valor | Prioridade |
|------:|------------|
| 1 | Baixa |
| 2 | Média |
| 3 | Alta |

### Status

O status da tarefa segue a seguinte regra:

| Valor | Status |
|------:|--------|
| 0 | Pendente |
| 1 | Concluída |

## Implementações extras

Após concluir os requisitos principais do desafio, foram adicionadas novas funcionalidades para deixar o sistema mais completo.

### Cadastro de pessoas

Foi criada uma nova estrutura para representar pessoas cadastradas no sistema.

Cada pessoa possui:

- ID
- Nome
- Email
- Nível

Os níveis disponíveis são:

- Júnior
- Pleno
- Sênior

### Validação de email

Foi adicionada uma função para validar o email informado no cadastro da pessoa.

O email precisa conter:

- `@`
- `.com` ou `.br`

Caso o email não siga esse formato básico, o cadastro não é concluído.

### Dificuldade da tarefa

Além da prioridade, cada tarefa também passou a possuir uma dificuldade.

As dificuldades seguem a regra:

| Valor | Dificuldade |
|------:|-------------|
| 1 | Baixa |
| 2 | Média |
| 3 | Alta |

### Vínculo entre pessoa e tarefa

Também foi implementada uma funcionalidade para vincular uma pessoa a uma tarefa.

O vínculo respeita o nível da pessoa e a dificuldade da tarefa:

| Nível | Dificuldades permitidas |
|------|--------------------------|
| Júnior | Baixa |
| Pleno | Baixa e Média |
| Sênior | Baixa, Média e Alta |

Se uma pessoa tentar assumir uma tarefa acima do seu nível permitido, o sistema bloqueia o vínculo e exibe uma mensagem explicando o motivo.

## Melhorias de legibilidade

Depois das funcionalidades principais, também foram feitas melhorias na organização do código:

- Comentários longos foram simplificados
- Variáveis abreviadas foram renomeadas
- Nomes como `o`, `trf`, `pss` e `tTotais` foram substituídos por nomes mais claros
- O código ficou mais fácil de ler, estudar e manter

Exemplos de melhorias:

| Antes | Depois |
|------|--------|
| `o` | `opcao` |
| `trf` | `tarefas` |
| `pss` | `pessoas` |
| `tTotais` | `totalTarefas` |
| `pTotais` | `totalPessoas` |
| `idBq` | `proximoIdTarefa` |
| `idPBq` | `proximoIdPessoa` |

## Tempo de desenvolvimento

O desafio principal foi concluído em aproximadamente 5 horas e 30 minutos.

Durante o desenvolvimento, além de cumprir os requisitos obrigatórios, também consegui avançar em melhorias extras no sistema, reforçando a prática com `structs`, funções, validações e organização de código.

## Conceitos praticados

Durante o desenvolvimento deste projeto, foram praticados os seguintes conceitos:

- Criação e uso de `structs`
- Vetores de structs
- Funções separadas por responsabilidade
- Menu interativo com `switch`
- Validação de entradas
- Manipulação de strings com `fgets`, `strcmp`, `strchr` e `strstr`
- Busca por ID
- Busca por título
- Remoção de elementos em vetor
- Organização e refatoração de código
- Regras de negócio simples

## Como executar

Para compilar o programa com GCC:

```bash
gcc main.c -o sistema
```

Para executar:

```bash
./sistema
```

No Windows, o comando de execução pode ser:

```bash
sistema.exe
```

## Observação

Este projeto representa uma evolução prática no estudo da linguagem C, aplicando conceitos fundamentais em um sistema funcional de terminal.

Além de atender ao desafio proposto, o sistema recebeu funcionalidades extras relacionadas ao gerenciamento de pessoas, níveis de responsabilidade e dificuldade das tarefas.

---

# Relatório de Implementações

## Visão geral

Este relatório descreve as implementações realizadas no sistema de gerenciamento de tarefas desenvolvido em linguagem C.

O sistema foi criado inicialmente para atender aos requisitos de um desafio de programação, que solicitava funcionalidades básicas de cadastro, listagem, busca, alteração de status, remoção e organização de tarefas.

Após a conclusão da versão principal do desafio, foram adicionadas novas funcionalidades para tornar o sistema mais completo e próximo de uma situação real de organização de tarefas em equipe.

## Implementações do desafio principal

### 1. Cadastro de tarefas

Foi implementada a função responsável por cadastrar novas tarefas no sistema.

Cada tarefa possui:

- ID
- Título
- Descrição
- Prioridade
- Status

O ID é gerado automaticamente, garantindo que cada tarefa tenha uma identificação única.

O status inicial da tarefa é definido como pendente.

### 2. Listagem de tarefas

Foi criada uma função para listar todas as tarefas cadastradas.

A listagem exibe as principais informações de cada tarefa, como:

- ID
- Título
- Descrição
- Prioridade
- Status

### 3. Busca de tarefa

Foi implementada uma busca pelo título da tarefa.

O sistema compara o título informado pelo usuário com os títulos cadastrados utilizando `strcmp`.

Caso encontre a tarefa, suas informações são exibidas.

Caso contrário, o sistema informa que a tarefa não foi encontrada.

### 4. Alteração de status

Foi criada uma funcionalidade para alterar o status de uma tarefa a partir do ID.

O usuário pode marcar a tarefa como:

- Pendente
- Concluída

### 5. Listagem de tarefas pendentes

Foi implementada uma função para exibir apenas as tarefas com status pendente.

Essa funcionalidade ajuda a visualizar o que ainda precisa ser feito.

### 6. Listagem de tarefas concluídas

Foi criada uma função para exibir apenas as tarefas já concluídas.

Essa funcionalidade permite acompanhar o que já foi finalizado.

### 7. Maior prioridade

Foi implementada uma função para localizar e exibir as tarefas com maior prioridade cadastrada no sistema.

A prioridade segue a escala:

- 1: Baixa
- 2: Média
- 3: Alta

### 8. Remoção de tarefas

Foi criada uma função para remover uma tarefa a partir do ID informado pelo usuário.

Após encontrar a tarefa, o sistema reorganiza o vetor para evitar espaços vazios entre os registros.

## Implementações adicionais após o desafio

Após finalizar os requisitos principais, foram adicionadas funcionalidades extras para melhorar o sistema.

### 1. Cadastro de pessoas

Foi criada uma nova `struct` para representar pessoas dentro do sistema.

Cada pessoa possui:

- ID
- Nome
- Email
- Nível

Os níveis disponíveis são:

- Júnior
- Pleno
- Sênior

Essa implementação permite que o sistema vá além do cadastro de tarefas, simulando também a organização de membros de uma equipe.

### 2. Validação de email

Foi implementada uma função para validar o email informado no cadastro de uma pessoa.

A validação verifica se o email contém:

- `@`
- `.com` ou `.br`

Essa validação impede que emails muito incompletos sejam cadastrados.

### 3. Dificuldade da tarefa

Foi adicionado um novo campo de dificuldade na estrutura da tarefa.

A dificuldade segue a regra:

- 1: Baixa
- 2: Média
- 3: Alta

Essa informação é diferente da prioridade.

A prioridade indica o quanto a tarefa é importante.

A dificuldade indica o quanto a tarefa é complexa.

### 4. Vínculo entre pessoa e tarefa

Foi criada uma funcionalidade para vincular uma pessoa cadastrada a uma tarefa existente.

Antes de realizar o vínculo, o sistema verifica se o nível da pessoa permite assumir a dificuldade da tarefa.

As regras são:

- Júnior pode assumir apenas tarefas de dificuldade baixa
- Pleno pode assumir tarefas de dificuldade baixa e média
- Sênior pode assumir tarefas de dificuldade baixa, média e alta

Caso a pessoa não tenha nível suficiente para a tarefa, o sistema bloqueia o vínculo e exibe uma mensagem explicativa.

### 5. Exibição do responsável pela tarefa

Ao listar ou buscar tarefas, o sistema também pode exibir a pessoa responsável, caso exista alguém vinculado à tarefa.

Isso melhora a visualização das responsabilidades dentro do sistema.

## Melhorias de organização e legibilidade

Além das novas funcionalidades, também foram feitas melhorias na leitura do código.

### Comentários

Os comentários muito grandes com várias linhas de símbolos foram simplificados.

Isso deixou o código mais limpo e menos poluído visualmente.

### Variáveis

Variáveis abreviadas foram renomeadas para nomes mais descritivos.

Exemplos:

- `o` foi alterado para `opcao`
- `trf` foi alterado para `tarefas`
- `pss` foi alterado para `pessoas`
- `tTotais` foi alterado para `totalTarefas`
- `pTotais` foi alterado para `totalPessoas`
- `idBq` foi alterado para `proximoIdTarefa`
- `idPBq` foi alterado para `proximoIdPessoa`

Essas alterações facilitaram o entendimento do código e melhoraram a manutenção do projeto.

## Tempo de desenvolvimento

A versão principal do desafio foi concluída em aproximadamente 5 horas e 30 minutos.

Após essa conclusão, foram adicionadas melhorias extras ao sistema, principalmente relacionadas ao cadastro de pessoas, vínculo de responsáveis, dificuldade das tarefas e organização do código.

## Conclusão

O projeto cumpriu os requisitos principais do desafio e também recebeu funcionalidades adicionais que ampliaram sua utilidade.

O desenvolvimento ajudou a praticar conceitos importantes da linguagem C, como:

- `structs`
- vetores
- funções
- menus
- validações
- manipulação de strings
- organização de código
- lógica de programação

Com as implementações extras, o sistema passou de um simples gerenciador de tarefas para uma base mais completa de organização de tarefas e pessoas em uma equipe.

---

# Desenvolvimento Inicial

## Progresso nas primeiras horas do desafio

Nas primeiras três horas do desafio, desenvolvi a base inicial do sistema de gerenciamento de tarefas em linguagem C.

Nesse primeiro momento, meu foco principal foi construir uma estrutura funcional para o programa, priorizando a lógica e o funcionamento das principais partes do sistema no terminal. A ideia era criar uma base sólida para depois corrigir, melhorar e organizar o código com mais calma.

Durante essa etapa inicial, comecei a estruturar os principais elementos do sistema, como a `struct` de tarefas, o vetor responsável por armazenar os dados, o menu principal, o submenu de gerenciamento, o cadastro de tarefas, a busca por título, a edição de status, a remoção de tarefas e algumas funções auxiliares de validação.

## Reaproveitamento de conhecimentos anteriores

Para ganhar velocidade no desenvolvimento, reutilizei e adaptei algumas funções de um projeto anterior que eu já havia desenvolvido.

Esse reaproveitamento não foi uma cópia direta, mas sim uma adaptação de conhecimentos que eu já tinha praticado anteriormente. Como algumas partes do desafio envolviam conceitos parecidos, como cadastro, busca, edição, remoção e validação de dados, consegui aproveitar essa experiência para avançar mais rapidamente.

Essa etapa mostrou a importância de praticar projetos anteriores, pois o conhecimento acumulado ajudou a resolver problemas parecidos em um novo contexto.

## Desenvolvimento sem uso de inteligência artificial para gerar o código

Como o desafio não permitia o uso de inteligência artificial para gerar o código, optei por desenvolver a lógica por conta própria.

Essa decisão foi importante para reforçar meu aprendizado e garantir que eu realmente entendesse o funcionamento do sistema. Em vez de depender de uma solução pronta, procurei aplicar os conceitos que já vinha estudando e resolver os problemas conforme eles apareciam durante o desenvolvimento.

Esse processo ajudou a fortalecer minha lógica de programação, minha familiaridade com a linguagem C e minha capacidade de estruturar um sistema funcional utilizando terminal, funções, structs, vetores e menus.

## Organização inicial durante o desenvolvimento

Na primeira versão do código, optei por não adicionar muitos comentários diretamente no arquivo.

Essa escolha foi feita para não interromper o ritmo de desenvolvimento. Durante as primeiras horas, eu estava mais focado em fazer a lógica funcionar e em montar a estrutura principal do sistema. Para manter o controle do que precisava ser feito, corrigido ou melhorado, utilizei anotações no caderno.

No caderno, eu registrava as funcionalidades pendentes, pontos que precisavam de correção e ideias para melhorar o sistema depois. Dessa forma, consegui continuar programando com mais agilidade sem perder o acompanhamento das próximas etapas.

## Uso inicial de variáveis abreviadas

Durante a primeira fase do desenvolvimento, também utilizei algumas variáveis abreviadas.

Essa decisão foi tomada para ganhar agilidade enquanto eu escrevia e testava o código. Como eu ainda estava construindo a base do sistema e acompanhando as anotações pelo caderno, nomes mais curtos ajudaram no processo inicial de implementação.

No entanto, após a base principal estar funcionando, revisei essa escolha e substituí várias variáveis abreviadas por nomes mais descritivos. Essa melhoria deixou o código mais claro, mais organizado e mais fácil de entender tanto para mim quanto para outras pessoas que possam visualizar o projeto.

## Refatoração e melhoria da legibilidade

Depois que a base principal do desafio foi concluída, realizei uma etapa de revisão e organização do código.

Nessa fase, simplifiquei comentários, melhorei a legibilidade e substituí nomes abreviados por nomes mais claros. Essa refatoração foi importante porque deixou o código mais adequado para apresentação, manutenção e estudo futuro.

Algumas mudanças feitas nessa etapa incluíram a troca de nomes curtos por nomes mais descritivos, facilitando a leitura do código e a identificação da função de cada variável dentro do sistema.

Exemplos de melhorias aplicadas:

| Antes | Depois |
|------|--------|
| `o` | `opcao` |
| `trf` | `tarefas` |
| `pss` | `pessoas` |
| `tTotais` | `totalTarefas` |
| `pTotais` | `totalPessoas` |
| `idBq` | `proximoIdTarefa` |
| `idPBq` | `proximoIdPessoa` |

Além disso, comentários muito longos ou visualmente carregados foram simplificados, deixando o código mais limpo e direto.

## Importância dessa primeira etapa

Essa primeira versão foi essencial para o desenvolvimento do projeto.

Mesmo ainda não sendo a versão final, ela permitiu criar rapidamente uma base funcional para o sistema. A partir dela, foi possível corrigir problemas, adicionar novas funcionalidades, melhorar a organização e evoluir o projeto com mais segurança.

Essa etapa também mostrou a importância de primeiro fazer a lógica funcionar e depois revisar o código para melhorar sua qualidade. Dessa forma, o desenvolvimento ficou dividido em duas partes importantes: primeiro a construção da solução e depois a organização e refinamento do projeto.

## Conclusão

O desenvolvimento inicial do sistema foi uma etapa importante para consolidar os conhecimentos estudados em C.

Durante as primeiras horas, consegui montar a base do projeto utilizando conceitos como `struct`, vetor de structs, funções, menu com `switch`, validações, manipulação de strings e laços de repetição.

Após essa etapa, o código foi revisado e melhorado, recebendo nomes de variáveis mais claros, comentários mais simples e uma organização mais adequada para apresentação no GitHub e em documentação.

Esse processo demonstrou evolução prática, pois envolveu não apenas escrever o código, mas também revisar, refatorar e melhorar a qualidade geral do projeto.

---

# Guia de Separação em include e src

Este guia explica como o programa foi separado em vários arquivos para deixar o projeto mais organizado.

A ideia principal é tirar tudo de um único arquivo `.c` e dividir o sistema por responsabilidade.

## Estrutura final do projeto

```text
sistema_tarefas_separado/
├── include/
│   ├── constantes.h
│   ├── dados.h
│   ├── menus.h
│   ├── modelos.h
│   ├── pessoas.h
│   ├── tarefas.h
│   └── validacoes.h
├── src/
│   ├── dados.c
│   ├── main.c
│   ├── menus.c
│   ├── pessoas.c
│   ├── tarefas.c
│   └── validacoes.c
└── Makefile
```

## Diferença entre `include` e `src`

## Pasta `include`

A pasta `include` guarda os arquivos `.h`.

Arquivos `.h` são chamados de headers.

Eles normalmente guardam:

- `structs`
- `enum`
- `#define`
- protótipos de funções
- declarações externas de variáveis globais

Eles não devem conter a lógica completa das funções.

Exemplo:

```c
void cadastrarPessoa();
```

Isso apenas avisa ao compilador que a função existe.

## Pasta `src`

A pasta `src` guarda os arquivos `.c`.

Arquivos `.c` contêm a implementação real das funções.

Exemplo:

```c
void cadastrarPessoa() {
    // código da função
}
```

## Explicação dos arquivos da pasta `include`

## `constantes.h`

Guarda constantes globais do projeto.

Neste caso, ficou responsável pelo valor máximo de registros:

```c
#define MAX 20
```

Assim, se você quiser mudar o limite de tarefas e pessoas, basta alterar esse arquivo.

## `modelos.h`

Guarda os modelos principais do sistema:

- `enum Nivel`
- `struct pessoa`
- `struct tarefa`

Esse arquivo é importante porque várias partes do sistema precisam conhecer o formato de uma pessoa e de uma tarefa.

## `dados.h`

Declara as variáveis globais com `extern`.

Exemplo:

```c
extern tarefa tarefas[MAX];
extern int totalTarefas;
```

O `extern` significa:

> Essa variável existe, mas ela foi criada de verdade em outro arquivo.

Isso evita erro de variável duplicada.

## `menus.h`

Guarda os protótipos das funções de menu:

```c
void menu();
void subMenuGerenciar();
void subMenuPessoas();
```

## `tarefas.h`

Guarda os protótipos das funções relacionadas às tarefas.

Exemplos:

```c
void cadastrartarefa();
void listar();
void mostrarBusca();
void removerID();
int verID(int idBuscado);
```

## `pessoas.h`

Guarda os protótipos das funções relacionadas às pessoas.

Exemplos:

```c
void cadastrarPessoa();
void listarPessoas();
void vincularPessoa();
void mostrarNivel(Nivel nivel);
```

## `validacoes.h`

Guarda os protótipos das funções de validação.

Exemplos:

```c
int verificacao(char texto[]);
int verifDesc(char texto[]);
int validarEmail(char email[]);
```

## Explicação dos arquivos da pasta `src`

## `main.c`

Contém apenas a função `main`.

Ele ficou responsável pelo loop principal do sistema e pelo `switch` do menu principal.

O objetivo é deixar o `main.c` mais limpo.

## `dados.c`

Cria de verdade as variáveis globais do sistema.

Exemplo:

```c
tarefa tarefas[MAX];
pessoa pessoas[MAX];

int totalTarefas = 0;
int totalPessoas = 0;
```

Esse arquivo trabalha junto com `dados.h`.

O `dados.h` declara as variáveis com `extern`.

O `dados.c` cria as variáveis de verdade.

## `menus.c`

Contém as funções de menu:

- `menu()`
- `subMenuGerenciar()`
- `subMenuPessoas()`

Como essas funções chamam funções de tarefas e pessoas, esse arquivo inclui:

```c
#include "tarefas.h"
#include "pessoas.h"
```

## `tarefas.c`

Contém as funções relacionadas às tarefas.

Exemplos:

- cadastrar tarefa
- listar tarefas
- buscar tarefa
- editar status
- remover tarefa
- listar pendentes
- listar concluídas
- mostrar maior prioridade
- ler prioridade
- ler dificuldade
- mostrar status
- mostrar prioridade
- buscar por ID

Esse arquivo usa `dados.h` porque precisa acessar o vetor global `tarefas`.

## `pessoas.c`

Contém as funções relacionadas às pessoas.

Exemplos:

- cadastrar pessoa
- listar pessoas
- vincular pessoa a tarefa
- mostrar nível
- verificar se a pessoa pode pegar a tarefa
- buscar pessoa por ID

Esse arquivo usa tanto pessoas quanto tarefas, porque o vínculo depende das duas estruturas.

## `validacoes.c`

Contém funções de validação.

Exemplos:

- verificar se um texto está vazio
- verificar se a descrição está vazia
- validar email

## Por que usar `#ifndef`, `#define` e `#endif`?

Nos arquivos `.h`, foi usado este padrão:

```c
#ifndef TAREFAS_H
#define TAREFAS_H

// conteúdo do arquivo

#endif
```

Isso se chama guarda de inclusão.

Ela impede que o mesmo header seja incluído mais de uma vez durante a compilação.

Sem isso, o compilador poderia reclamar de declarações repetidas.

## Como compilar pelo terminal

Entre na pasta do projeto:

```bash
cd sistema_tarefas_separado
```

Depois compile com:

```bash
gcc src/main.c src/dados.c src/menus.c src/tarefas.c src/pessoas.c src/validacoes.c -Iinclude -o sistema
```

## O que significa `-Iinclude`?

O comando `-Iinclude` diz ao compilador:

> Procure os arquivos `.h` dentro da pasta `include`.

Sem isso, o compilador pode não encontrar arquivos como:

```c
#include "tarefas.h"
#include "pessoas.h"
#include "modelos.h"
```

## Como executar no Windows

Depois de compilar:

```bash
sistema.exe
```

ou, dependendo do terminal:

```bash
./sistema.exe
```

## Como executar no Linux ou Git Bash

Depois de compilar:

```bash
./sistema
```

## Como compilar usando o Makefile

Se você tiver `make` instalado, basta usar:

```bash
make
```

Para executar:

```bash
make run
```

Para limpar o executável:

```bash
make clean
```

## Como adicionar isso no GitHub

Uma organização recomendada para o repositório é:

```text
meu-repositorio/
├── include/
├── src/
├── Makefile
└── README.md
```

Você pode colocar os arquivos `.h` dentro de `include` e os arquivos `.c` dentro de `src`.

## Ordem recomendada para estudar os arquivos

Para entender o projeto, leia nesta ordem:

1. `include/modelos.h`
2. `include/dados.h`
3. `src/dados.c`
4. `src/main.c`
5. `src/menus.c`
6. `src/tarefas.c`
7. `src/pessoas.c`
8. `src/validacoes.c`

## Resumo da lógica da separação

O programa foi separado assim:

| Arquivo | Responsabilidade |
|---|---|
| `modelos.h` | Guarda `structs` e `enum` |
| `constantes.h` | Guarda constantes como `MAX` |
| `dados.h` | Declara variáveis globais com `extern` |
| `dados.c` | Cria as variáveis globais |
| `menus.h` / `menus.c` | Organiza os menus |
| `tarefas.h` / `tarefas.c` | Organiza funções de tarefas |
| `pessoas.h` / `pessoas.c` | Organiza funções de pessoas |
| `validacoes.h` / `validacoes.c` | Organiza funções de validação |
| `main.c` | Controla o fluxo principal do sistema |

## Observação importante

Quando um projeto é separado em vários arquivos, é normal parecer mais difícil no começo.

Mas essa separação deixa o código mais profissional, mais fácil de manter e melhor organizado para projetos maiores.

Em vez de procurar tudo em um único arquivo grande, você passa a saber onde cada parte do sistema está.
