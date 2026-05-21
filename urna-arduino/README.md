# Urna Eletrônica Simples com Arduino

Projeto de uma urna eletrônica simples feita com Arduino Uno, display LCD 16x2 I2C e botões físicos para registrar votos.

A ideia do projeto é simular uma votação básica com quatro candidatos, confirmação visual no LCD, reset dos votos, apuração do resultado, cálculo de porcentagem e verificação de empate.

## Status do projeto

Projeto finalizado como trabalho acadêmico.

Este repositório não tem como objetivo receber novas funcionalidades ou atualizações futuras, porque foi desenvolvido para uma atividade específica. Mesmo assim, o código e a documentação ficam disponíveis para quem quiser estudar, entender a lógica ou usar como base para criar a própria versão.

## Uso como base

Este projeto pode ser usado como referência para estudos, principalmente por quem está começando com Arduino, botões, LCD I2C e lógica de programação.

Quem quiser pode adaptar a ideia para outros projetos, como:

- Urna com mais candidatos;
- Sistema de votação com confirmação extra;
- Projeto com LEDs ou buzzer;
- Versão usando `array` e `struct`;
- Versão com armazenamento dos votos em memória;
- Simulações no Tinkercad ou testes em Arduino físico.

A proposta deste repositório é servir como uma base simples e didática, não como um sistema real de votação.

## Objetivo

O objetivo deste projeto foi praticar conceitos de programação e sistemas embarcados usando Arduino.

Durante o desenvolvimento foram trabalhados conceitos como:

- Entradas digitais;
- Botões físicos;
- Display LCD 16x2 com comunicação I2C;
- Lógica de votação;
- Controle de fluxo;
- Funções;
- Debounce por software;
- Cálculo de porcentagem;
- Verificação de empate;
- Organização e documentação de projeto.

## Funcionamento geral

A urna possui quatro candidatos, representados pelas letras A, B, C e D.

Cada candidato possui um botão próprio. Quando um botão é pressionado, o voto é registrado, o LCD mostra uma mensagem de confirmação e depois volta para o placar atualizado.

Além dos botões de voto, o projeto também possui:

- Um botão de reset, usado para zerar todos os votos;
- Um botão de apuração, usado para mostrar o vencedor, os votos, as porcentagens e possíveis empates.

Fluxo básico do sistema:

1. O Arduino inicia o LCD.
2. O display mostra uma mensagem inicial.
3. O sistema aguarda o usuário pressionar um botão.
4. Quando um voto é registrado, o contador do candidato aumenta.
5. O LCD mostra a confirmação do voto.
6. O placar é atualizado.
7. Ao pressionar apuração, o sistema calcula o total de votos, as porcentagens e verifica se houve vencedor ou empate.
8. Ao pressionar reset, todos os votos são zerados.

## Componentes utilizados

| Quantidade | Componente |
|---:|---|
| 1 | Arduino Uno R3 |
| 1 | Display LCD 16x2 com módulo I2C |
| 6 | Push buttons |
| 1 | Protoboard pequena |
| Alguns | Jumpers/fios para ligação |

Os botões usam `INPUT_PULLUP`, então não foi necessário usar resistores externos para eles.

## Ligações do LCD

| Pino do LCD | Pino no Arduino Uno |
|---|---|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

Na versão adaptada para o Tinkercad, o código usa a biblioteca `Adafruit_LiquidCrystal`:

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
```

E a inicialização do display é feita com:

```cpp
lcd.begin(16, 2);
```

## Ligações dos botões

Cada botão é ligado entre um pino digital do Arduino e o GND.

Como o código usa `INPUT_PULLUP`, a lógica do botão fica invertida:

| Situação do botão | Leitura no Arduino |
|---|---|
| Solto | HIGH |
| Pressionado | LOW |

Por isso, no código, um botão é considerado pressionado quando a leitura do pino é `LOW`.

| Botão | Função | Pino no Arduino |
|---|---|---|
| A | Voto no candidato A | D2 |
| B | Voto no candidato B | D3 |
| C | Voto no candidato C | D4 |
| D | Voto no candidato D | D5 |
| Reset | Zera os votos | D6 |
| Apuração | Mostra o resultado | D7 |

Também é necessário ligar o trilho negativo da protoboard ao GND do Arduino, para que todos os botões compartilhem o mesmo terra.

## Legenda dos fios

| Cor | Ligação |
|---|---|
| Vermelho | 5V do Arduino para o VCC do LCD |
| Preto | GND do Arduino, GND do LCD e trilho negativo da protoboard |
| Azul | A4 do Arduino para SDA do LCD |
| Roxo | A5 do Arduino para SCL do LCD |
| Laranja | Pinos D2, D3, D4 e D5 para os botões A, B, C e D |
| Verde | Pinos D6 e D7 para os botões de reset e apuração |

## Estrutura do código

O código principal está no arquivo:

```text
urna_pronta.ino
```

A lógica foi separada em funções para deixar o programa mais organizado e mais fácil de explicar.

Principais partes do código:

| Função | Responsabilidade |
|---|---|
| `setup()` | Configura os botões, inicia o LCD e mostra as mensagens iniciais |
| `loop()` | Verifica continuamente os botões de voto, reset e apuração |
| `botaoPressionado()` | Faz a leitura dos botões com debounce |
| `exibirConfirmacao()` | Mostra no LCD que o voto foi computado |
| `atualizarDisplay()` | Atualiza o placar dos candidatos no LCD |
| `exibirVencedor()` | Mostra o resultado da votação |
| `calcularPorcentagem()` | Calcula a porcentagem de votos de cada candidato |
| `encontrarVencedor()` | Verifica qual candidato venceu ou se houve empate |

## Variáveis de votos

Os votos são armazenados em variáveis separadas:

```cpp
int votosA = 0;
int votosB = 0;
int votosC = 0;
int votosD = 0;
```

Essa escolha deixou o código mais direto para um projeto pequeno, com apenas quatro candidatos.

Em uma versão maior, com muitos candidatos, faria mais sentido usar `array` e `struct` para deixar o sistema mais compacto e escalável. Porém, neste trabalho, a prioridade foi manter a lógica simples, explícita e fácil de acompanhar durante a montagem e a apresentação.

## Debounce dos botões

O projeto usa debounce por software para evitar que um único clique seja contado mais de uma vez.

Botões físicos podem gerar pequenas oscilações elétricas quando são pressionados. Sem debounce, o Arduino poderia interpretar um único aperto como vários cliques.

Para evitar isso, a função `botaoPressionado()` usa `millis()` e espera o sinal ficar estável por 50 ms antes de aceitar o clique.

Depois que o botão é identificado como pressionado, o código espera ele ser solto antes de aceitar outra leitura. Isso ajuda a garantir que cada aperto conte apenas uma vez.

## Confirmação do voto

Sempre que um voto é registrado, o LCD mostra uma mensagem de confirmação, como no exemplo:

```text
Voto computado!
Cand. A
```

A letra muda de acordo com o candidato escolhido.

Essa mensagem aparece por um curto período e depois o display volta automaticamente para o placar atualizado.

## Atualização do placar

A função `atualizarDisplay()` mostra os votos atuais no LCD.

O display é organizado de forma simples:

```text
A:0  B:0
C:0  D:0
```

Sempre que um voto é registrado ou o reset é acionado, essa função é chamada para atualizar as informações exibidas.

## Apuração dos votos

Ao pressionar o botão de apuração, o sistema:

1. Soma todos os votos;
2. Verifica se existe pelo menos um voto registrado;
3. Procura o maior número de votos;
4. Verifica se existe empate;
5. Calcula as porcentagens;
6. Mostra o vencedor ou os candidatos empatados no LCD;
7. Mostra os votos e porcentagens de cada candidato;
8. Mostra o total geral de votos.

Se nenhum voto tiver sido registrado, o LCD mostra uma mensagem avisando que ainda não existem votos.

## Cálculo de porcentagem

A porcentagem é calculada com a função `calcularPorcentagem()`.

A função também evita divisão por zero quando o total de votos é igual a 0:

```cpp
if (total == 0) {
  return 0;
}
```

A fórmula usada arredonda melhor o resultado inteiro:

```cpp
(votos * 100 + total / 2) / total
```

## Correção feita para o Tinkercad

Durante o desenvolvimento, o LCD I2C não estava iniciando corretamente no Tinkercad.

A montagem estava correta, mas a biblioteca anterior não funcionava bem com o LCD I2C do simulador.

Antes, o código usava:

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
```

Depois da correção, foi usada a biblioteca compatível com o Tinkercad:

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
```

E a inicialização passou a ser:

```cpp
lcd.begin(16, 2);
```

Com isso, o LCD passou a iniciar corretamente no simulador.

## Anotação extra: LEDs de confirmação

Durante o desenvolvimento também foi documentada uma possível implementação com três LEDs de confirmação.

Essa parte ficou registrada como anotação de melhoria, mas não é o foco da versão final do trabalho.

| LED | Pino | Uso documentado |
|---|---:|---|
| Verde | D8 | Confirmar voto ou vencedor encontrado |
| Amarelo | D9 | Indicar apuração ou ausência de votos |
| Vermelho | D10 | Indicar reset ou empate |

Cada LED deve ser ligado com resistor de 220Ω em série:

```text
Pino Arduino -> Resistor 220Ω -> Anodo do LED (+) -> Catodo do LED (-) -> GND
```

Observação: no sketch principal enviado, a lógica dos LEDs não aparece integrada. Por isso, essa parte foi mantida apenas como anotação de evolução possível para quem quiser adaptar o projeto.

## Arquivos do projeto

| Arquivo | Descrição |
|---|---|
| `urna_pronta.ino` | Código principal da urna eletrônica |
| `Arduino contador de votos(3).md` | Documentação completa da montagem e funcionamento |
| `Implementações e correção de erros.md` | Anotações sobre correções, LCD no Tinkercad e ideia dos LEDs |
| `esboço.excalidraw` | Esboço visual da montagem com Arduino, LCD, protoboard e botões |

## Como executar

### No Tinkercad

1. Crie um circuito com Arduino Uno.
2. Adicione um LCD 16x2 com I2C.
3. Adicione os seis botões.
4. Faça as ligações conforme as tabelas deste README.
5. Cole o código do arquivo `urna_pronta.ino`.
6. Inicie a simulação.
7. Pressione os botões para testar votos, reset e apuração.

### Na Arduino IDE

1. Abra o arquivo `urna_pronta.ino`.
2. Verifique se a biblioteca usada é compatível com o seu LCD.
3. Conecte o Arduino ao computador.
4. Selecione a placa Arduino Uno.
5. Selecione a porta correta.
6. Envie o código para a placa.

Observação: dependendo do módulo LCD usado fora do Tinkercad, pode ser necessário ajustar a biblioteca e o endereço I2C.

## O que foi aprendido

Com este projeto, foram praticados conceitos como:

- Uso de botões com `INPUT_PULLUP`;
- Leitura de entrada digital;
- Controle de display LCD;
- Organização de código em funções;
- Uso de variáveis para armazenar estados;
- Debounce por software;
- Cálculo de porcentagem;
- Verificação de empate;
- Correção de erro de biblioteca em ambiente de simulação;
- Documentação de montagem e funcionamento.

## Observação sobre manutenção

Este projeto foi feito para um trabalho específico, então não existe intenção de continuar desenvolvendo novas versões neste repositório.

Mesmo assim, ele fica disponível como material de consulta. Quem quiser pode usar a estrutura como base para estudar ou criar uma versão própria, alterando a quantidade de candidatos, o tipo de display, a organização do código ou adicionando novos recursos.

## Observação sobre a escolha da estrutura

Para este projeto, a estrutura foi mantida mais explícita e direta, usando variáveis separadas para cada candidato.

Mesmo que `array` e `struct` deixassem o código mais escalável, a proposta aqui foi facilitar a explicação da lógica, principalmente por ser um projeto pequeno e voltado para demonstração prática com Arduino.

## Autor

Projeto desenvolvido por Cauã Luiz de Oliveira como trabalho acadêmico e estudo prático de Arduino, programação e sistemas embarcados.
