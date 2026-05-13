# Sistema Escolar em C

Este é um projeto acadêmico desenvolvido em C para praticar lógica de programação, structs, arrays, matrizes, funções, menus no terminal e manipulação de dados.

O sistema permite cadastrar alunos, cadastrar notas por disciplina, listar alunos e visualizar notas registradas.

## Sobre o projeto

Este projeto faz parte dos meus estudos em linguagem C e foi desenvolvido com base em uma atividade feita inicialmente em Portugol durante o curso.

A ideia principal foi adaptar e evoluir a lógica do projeto original para C, utilizando conceitos que estou estudando, como arrays, matrizes, structs, funções e organização de menus no terminal.

Ainda é um projeto em desenvolvimento, mas representa uma etapa importante da minha evolução, principalmente por ser uma transição de uma lógica mais simples em Portugol para uma estrutura mais organizada em C.

## Origem do projeto

A primeira versão da ideia foi feita em Portugol como parte de uma atividade do curso.

Na versão em Portugol, eu optei por não utilizar arrays e matrizes, porque o trabalho era em dupla e isso poderia dificultar o entendimento da minha dupla naquele momento.

Por esse motivo, acabei utilizando formas mais simples para organizar o código, incluindo abreviações em nomes de variáveis e uma estrutura mais direta, com o objetivo de facilitar a leitura e a explicação durante o desenvolvimento da atividade.

Na versão em C, decidi adaptar a ideia original e melhorar a estrutura do projeto, aplicando arrays, matrizes, structs e funções para praticar melhor a linguagem e deixar o sistema mais próximo de uma organização real de código.

A proposta desta versão não é apenas copiar o projeto original, mas reescrever, melhorar e aprender com o processo.

## Observação sobre nomes de variáveis

Durante esse projeto e também em alguns trabalhos depois dele, eu ainda tinha o costume de abreviar bastante os nomes das variáveis.

No começo, isso fazia sentido para mim, porque eu conseguia entender o que cada abreviação significava dentro do meu próprio raciocínio. Porém, com o tempo, percebi que o código que eu escrevo não é feito apenas para mim.

Depois dessa percepção, comecei a evitar abreviações muito complexas ou difíceis de entender e passei a usar nomes mais objetivos.

Por exemplo, em vez de usar abreviações muito curtas e pouco claras, comecei a preferir nomes como `opNumero`, quando a variável representa uma opção numérica escolhida pelo usuário.

Essa mudança ainda faz parte do meu processo de evolução, mas já me ajudou a escrever códigos mais legíveis e fáceis de revisar.

## Funcionalidades

- Cadastro de alunos
- Cadastro de disciplinas
- Cadastro de notas
- Cálculo de médias
- Listagem de alunos cadastrados
- Visualização de notas por disciplina
- Menu principal no terminal
- Menu para seleção de alunos
- Menu para seleção de disciplinas
- Validação básica de nomes

## O que pratiquei

Neste projeto, pratiquei conceitos importantes da linguagem C, como:

- Variáveis
- Tipos de dados
- Structs
- Arrays
- Matrizes
- Funções
- Condicionais
- Laços de repetição
- Entrada e saída de dados
- Manipulação de strings
- Uso de `fgets`
- Uso de `scanf`
- Uso de `strcpy`
- Uso de `strlen`
- Uso de `strpbrk`
- Organização básica de menus
- Separação de responsabilidades por funções
- Uso de bibliotecas como `stdio.h`, `string.h`, `stdlib.h`, `stdbool.h` e `windows.h`

## Estrutura do projeto

```txt
sistema-escolar/
├── main.c
├── README.md
└── referencias/
    └── versao-portugol.por
```

## Como o sistema funciona

Ao iniciar o programa, o sistema solicita o nome do administrador e carrega as disciplinas disponíveis.

Depois disso, o menu principal permite escolher entre as opções de cadastro, listagem e gerenciamento de notas.

Exemplo de menu:

```txt
Escolha uma opcao:

1 - Cadastrar um aluno
2 - Listar alunos cadastrados
3 - Cadastrar notas
4 - Mostrar resultados de alunos
9 - Sair do sistema
```

## Disciplinas utilizadas

O projeto trabalha com algumas disciplinas pré-definidas no código:

```txt
Matemática
História
Ciências
Educação Física
Português
```

## Exemplo de uso

Fluxo básico do programa:

```txt
1. Cadastrar alunos
2. Escolher um aluno
3. Escolher uma disciplina
4. Cadastrar as notas
5. Calcular a média
6. Consultar os resultados
```

## Como executar

Para executar o projeto, é necessário ter um compilador C instalado, como o GCC.

### Compilando com GCC

Dentro da pasta do projeto, execute:

```bash
gcc main.c -o sistema-escolar
```

### Executando no Linux

```bash
./sistema-escolar
```

### Executando no Windows

```cmd
sistema-escolar.exe
```

Também é possível compilar e executar o arquivo diretamente por uma IDE ou editor de código, como o VS Code.

## Observações importantes

Este projeto foi feito com foco em aprendizado.

Algumas partes do código ainda podem ser melhoradas, principalmente em organização, validação de entradas e redução de repetição em alguns blocos.

A versão atual foi construída durante meu processo de aprendizado, então algumas decisões refletem o meu nível de conhecimento no momento em que o projeto foi desenvolvido.

A ideia é manter esse projeto como registro da minha evolução e futuramente refatorar partes do código conforme eu aprender mais sobre C, organização de projetos e boas práticas.

## Melhorias futuras

Algumas melhorias que pretendo fazer futuramente:

- Melhorar a validação de entradas
- Tratar erros ao digitar letras em campos numéricos
- Reduzir repetição nos menus e nos `switch cases`
- Melhorar o cálculo e a exibição das médias
- Separar o código em múltiplos arquivos
- Criar arquivos `.h` para organizar structs e funções
- Melhorar os nomes de algumas variáveis
- Adicionar persistência de dados em arquivos
- Permitir editar alunos cadastrados
- Permitir remover alunos
- Permitir cadastrar disciplinas dinamicamente
- Melhorar a compatibilidade entre Windows e Linux
- Refatorar o código para deixá-lo mais limpo e organizado

## Status

Em desenvolvimento.

Este projeto em C ainda não está finalizado, mas já representa uma parte importante da minha evolução nos estudos. Pretendo continuar melhorando o código, a organização e algumas funcionalidades conforme eu aprender mais.

## Observação sobre a versão em Portugol

A versão original em Portugol foi feita com uma estrutura mais simples, porque a proposta do trabalho era ser desenvolvida em dupla.

Como minha dupla poderia ter dificuldade para acompanhar uma estrutura com arrays e matrizes naquele momento, optei por simplificar a lógica e reduzir a complexidade do código.

Por isso, algumas variáveis e escolhas da versão original podem não estar tão claras para quem for ver o projeto depois. Mesmo assim, essa versão teve importância no processo, porque serviu como base para eu adaptar e evoluir a ideia em C.

Na versão em C, procurei aplicar conceitos mais estruturados para melhorar minha prática e entender melhor como organizar dados em um sistema simples.

## Observação final

Este projeto não tem o objetivo de ser um sistema escolar completo ou pronto para uso real.

Ele foi desenvolvido para estudo, prática e evolução na linguagem C.
