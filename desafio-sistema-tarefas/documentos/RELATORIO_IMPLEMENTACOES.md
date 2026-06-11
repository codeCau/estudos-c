# Relatório de Implementações — Sistema de Gerenciamento de Tarefas em C

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
