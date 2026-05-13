# Cadastro com cálculo de IMC em C

Este é um projeto simples desenvolvido em C para praticar lógica de programação, structs, funções, validação básica de dados e menus no terminal.

O programa permite cadastrar pessoas com nome, idade, altura e peso. Depois, ele lista os cadastros, mostra se a pessoa é maior ou menor de idade e calcula o IMC.

## Sobre o projeto

Este projeto faz parte dos meus estudos iniciais em linguagem C.

A ideia principal foi criar um sistema simples de cadastro, utilizando estruturas da linguagem para armazenar dados e organizar melhor o código.

Ainda é um projeto inicial, mas ele representa uma etapa importante da minha evolução, principalmente no uso de structs, funções, arrays e manipulação básica de dados.

## Funcionalidades

- Cadastro de pessoas
- Validação básica de nome
- Armazenamento de idade
- Armazenamento de altura
- Armazenamento de peso
- Listagem de pessoas cadastradas
- Verificação de maioridade
- Cálculo de IMC
- Menu simples no terminal

## O que pratiquei

Neste projeto, pratiquei conceitos importantes da linguagem C, como:

- Variáveis
- Tipos de dados
- Structs
- Arrays
- Funções
- Condicionais
- Laços de repetição
- Entrada e saída de dados
- Validação básica de strings
- Organização de código
- Uso de `fgets`
- Uso de `scanf`
- Uso de bibliotecas como `stdio.h`, `string.h` e `stdlib.h`

## Estrutura do projeto

```txt
cadastro-imc/
├── main.c
└── README.md
```

## Como executar

Para executar o projeto, é necessário ter um compilador C instalado, como o GCC.

### Compilando com GCC

Dentro da pasta do projeto, execute:

```bash
gcc main.c -o cadastro-imc
```

### Executando no Linux

```bash
./cadastro-imc
```

### Executando no Windows

```cmd
cadastro-imc.exe
```

Também é possível compilar e executar o arquivo diretamente por uma IDE ou editor de código, como o VS Code.

## Exemplo de uso

O programa apresenta um menu no terminal com opções para cadastrar uma pessoa, listar os cadastros e sair do sistema.

Exemplo de menu:

```txt
Escolha uma opcao:

1 - Cadastrar uma pessoa
2 - Liste as pessoas cadastradas
0 - Para sair do sistema
```

Ao cadastrar uma pessoa, o programa solicita:

```txt
Nome
Idade
Altura
Peso
```

Depois, ao listar os cadastros, ele exibe informações como:

```txt
Nome da Pessoa
Idade
Altura
Maior ou menor de idade
IMC
```

## Melhorias futuras

Algumas melhorias que pretendo fazer futuramente:

- Melhorar a validação de entradas
- Tratar erros ao digitar letras em campos numéricos
- Melhorar a organização das mensagens do menu
- Separar o código em múltiplos arquivos
- Criar arquivos `.h` para organizar funções
- Adicionar classificação do IMC
- Permitir remover cadastros
- Permitir editar cadastros
- Salvar os dados em arquivo
- Melhorar a compatibilidade entre Windows e Linux

## Status

Em desenvolvimento.

Este projeto ainda pode ser melhorado, mas já serve como registro da minha evolução nos estudos de C.

## Observação

Este projeto foi desenvolvido com foco em aprendizado. O código pode conter pontos a melhorar, mas faz parte do meu processo de estudo e prática.
