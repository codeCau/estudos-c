data de inicio
25-05-2026 23:09
data de conclusão dessa etapa!
16-05-2026 17:31

Status: #developing 

Tags: [[Arquitetura]] | [[Software]] | [[C++ Linguagem]] |  [[Funções]] | [[C Linguagem]] | [[Sistemas embarcados]]

**Projeto:** Urna eletrônica simples com Arduino Uno, LCD I2C e botões

---
## Observação sobre variáveis
Neste trabalho eu optei por não usar `struct` e `array` porque o projeto tinha poucos candidatos e a prioridade era deixar a lógica mais direta e fácil de entender durante a apresentação. Como eram apenas quatro opções de voto, usar variáveis separadas como `votosA`, `votosB`, `votosC` e `votosD` deixou o código mais simples de acompanhar, principalmente relacionando cada botão a um candidato específico.

Eu sei que com `array` e `struct` o código poderia ficar mais compacto e escalável, principalmente se houvesse muitos candidatos, mas para este projeto pequeno isso poderia deixar a explicação mais abstrata do que necessário. Como o objetivo era demonstrar o funcionamento da urna, dos botões, do display LCD, do reset, da apuração e do debounce, preferi manter uma estrutura mais explícita e didática.

---
## 1. Objetivo do projeto

O objetivo deste projeto é montar uma urna eletrônica simples usando um **Arduino Uno**, um **display LCD 16x2 com comunicação I2C** e botões físicos para registrar votos.

A urna possui quatro candidatos, representados pelas letras **A, B, C e D**. Cada candidato tem um botão próprio. Também existem dois botões extras: um botão de **reset**, para zerar todos os votos, e um botão de **apuração**, para mostrar o vencedor, os votos e as porcentagens.

A ideia geral do projeto é simular o funcionamento básico de uma urna: o usuário aperta um botão para votar, o voto é contado, o LCD mostra uma confirmação e depois volta para o placar atual.

---

## 2. Componentes utilizados

Para a montagem foram utilizados os seguintes componentes:

| Quantidade | Componente                      |
| ---------: | ------------------------------- |
|          1 | Arduino Uno R3                  |
|          1 | Display LCD 16x2 com módulo I2C |
|          6 | Push buttons                    |
|          1 | Protoboard pequena              |
|     Alguns | Jumpers/fios para ligação       |

Não foi necessário usar resistores externos nos botões, porque o código utiliza o modo **INPUT_PULLUP**, que ativa o resistor interno de pull-up do próprio Arduino.

---

## 3. Ligações físicas do LCD

O LCD usado é um modelo **16x2 com comunicação I2C**. Isso facilita bastante a montagem, porque em vez de usar vários pinos digitais do Arduino, são usados apenas dois pinos de comunicação: **SDA** e **SCL**.

A ligação do LCD ficou assim:

| Pino do LCD | Pino no Arduino Uno |
| ----------- | ------------------- |
| GND         | GND                 |
| VCC         | 5V                  |
| SDA         | A4                  |
| SCL         | A5                  |

O pino **VCC** alimenta o LCD com 5V, o **GND** fecha o negativo do circuito, o **SDA** envia e recebe os dados da comunicação I2C e o **SCL** funciona como o clock dessa comunicação.

No código, o LCD foi configurado com o endereço **0x20**, usando a biblioteca `LiquidCrystal_I2C`.

---

## 4. Ligações físicas dos botões

Cada botão foi ligado com apenas duas conexões:

1. Um terminal do botão vai para um pino digital do Arduino.
2. O outro terminal do botão vai para o trilho de **GND** da protoboard.

Como o código usa `INPUT_PULLUP`, o botão funciona com lógica invertida. Isso significa que:

| Situação do botão | Leitura no Arduino |
| ----------------- | ------------------ |
| Solto             | HIGH               |
| Pressionado       | LOW                |

Por isso, no código, um botão é considerado pressionado quando a leitura do pino é **LOW**.

A ligação dos botões ficou assim:

| Botão    | Função              | Pino no Arduino |
| -------- | ------------------- | --------------- |
| A        | Voto no candidato A | D2              |
| B        | Voto no candidato B | D3              |
| C        | Voto no candidato C | D4              |
| D        | Voto no candidato D | D5              |
| Reset    | Zera os votos       | D6              |
| Apuração | Mostra o resultado  | D7              |

Também foi ligado o trilho negativo da protoboard ao pino **GND** do Arduino, para que todos os botões compartilhem o mesmo terra.

---

## 5. Legenda dos fios usada na montagem

Na organização da montagem, foi usada uma legenda de cores para facilitar a identificação dos fios:

| Cor      | Ligação                                                    |
| -------- | ---------------------------------------------------------- |
| Vermelho | 5V do Arduino para o VCC do LCD                            |
| Preto    | GND do Arduino, GND do LCD e trilho negativo da protoboard |
| Azul     | A4 do Arduino para SDA do LCD                              |
| Roxo     | A5 do Arduino para SCL do LCD                              |
| Laranja  | Pinos D2, D3, D4 e D5 para os botões A, B, C e D           |
| Verde    | Pinos D6 e D7 para os botões de reset e apuração           |

Essa organização ajuda a visualizar melhor a montagem e evita confusão na hora de conectar os componentes.

---

## 6. Estrutura geral do código

O código começa importando as bibliotecas necessárias:

- `Wire.h`, usada para comunicação I2C.
- `LiquidCrystal_I2C.h`, usada para controlar o LCD I2C.

Depois disso, o LCD é configurado com:

```cpp
LiquidCrystal_I2C lcd(0x20, 16, 2);
```

Isso indica que o endereço I2C do LCD é **0x20** e que o display possui **16 colunas e 2 linhas**.

Em seguida, o código define os pinos usados pelos botões:

| Nome no código | Pino físico | Função |
|---|---:|---|
| `PINO_A` | 2 | Voto no candidato A |
| `PINO_B` | 3 | Voto no candidato B |
| `PINO_C` | 4 | Voto no candidato C |
| `PINO_D` | 5 | Voto no candidato D |
| `PINO_RESET` | 6 | Reset dos votos |
| `PINO_APURACAO` | 7 | Apuração dos votos |

O programa também possui quatro variáveis inteiras para guardar os votos:

```cpp
int votosA = 0;
int votosB = 0;
int votosC = 0;
int votosD = 0;
```

Cada vez que um botão de candidato é pressionado, o contador correspondente aumenta em 1.

---

## 7. Funcionamento do `setup()`

A função `setup()` é executada uma única vez quando o Arduino liga ou reinicia.

Nessa parte do código, os pinos dos botões são configurados como `INPUT_PULLUP`:

```cpp
pinMode(PINO_A, INPUT_PULLUP);
pinMode(PINO_B, INPUT_PULLUP);
pinMode(PINO_C, INPUT_PULLUP);
pinMode(PINO_D, INPUT_PULLUP);
pinMode(PINO_RESET, INPUT_PULLUP);
pinMode(PINO_APURACAO, INPUT_PULLUP);
```

Isso faz com que o Arduino use os resistores internos de pull-up. Com isso, não é necessário colocar resistores externos na protoboard.

Depois, o LCD é iniciado, a luz de fundo é ligada e são mostradas mensagens iniciais:

- Primeiro aparece `URNA ELETRONICA` e `Bem-vindo! :)`.
- Depois aparece `Pressione o voto` e `A | B | C | D`.
- Em seguida, o display passa a mostrar o placar atual dos candidatos.

---

## 8. Funcionamento do `loop()`

A função `loop()` fica repetindo continuamente enquanto o Arduino está ligado.

Dentro dela, o programa verifica se algum botão foi pressionado.

Quando o botão do candidato A é pressionado, por exemplo, acontece o seguinte:

1. O programa detecta o pressionamento do botão.
2. A variável `votosA` aumenta em 1.
3. O LCD mostra a mensagem de confirmação do voto.
4. O display volta para o placar atualizado.

A mesma lógica acontece com os candidatos B, C e D.

Além dos votos, o `loop()` também verifica:

- Se o botão de **apuração** foi pressionado.
- Se o botão de **reset** foi pressionado.

Quando o botão de reset é pressionado, todos os contadores voltam para zero:

```cpp
votosA = 0;
votosB = 0;
votosC = 0;
votosD = 0;
```

Depois disso, o LCD mostra a mensagem `RESETADO` e `Votos zerados!`.

---

## 9. Debounce por software

Um detalhe importante do projeto é o **debounce** dos botões.

Quando um botão físico é pressionado, ele pode gerar pequenas oscilações elétricas por alguns milissegundos. Isso poderia fazer o Arduino entender que o botão foi apertado várias vezes, mesmo que tenha sido apenas um clique.

Para evitar isso, o código usa a função `botaoPressionado()`.

Essa função usa `millis()` para medir o tempo desde a última mudança de estado do botão. O pressionamento só é aceito se o sinal ficar estável por **50 ms**.

Além disso, depois que o botão é detectado como pressionado, o código espera o botão ser solto:

```cpp
while (digitalRead(pino) == LOW);
```

Isso garante que cada aperto conte apenas uma vez.

Resumindo: o debounce impede votos duplicados causados pelo ricochete mecânico do botão.

---

## 10. Confirmação do voto

Sempre que um voto é registrado, o LCD mostra uma confirmação:

```text
Voto computado!
Cand. A
```

A letra muda de acordo com o candidato votado.

Essa mensagem aparece por 1 segundo e depois o display volta automaticamente para o placar.

Essa confirmação serve como feedback visual para mostrar que o voto realmente foi registrado.

---

## 11. Atualização do placar

A função `atualizarDisplay()` mostra os votos atuais no LCD.

O display fica organizado assim:

```text
A:0  B:0
C:0  D:0
```

Cada vez que um voto entra ou o reset é acionado, essa função é chamada para atualizar os valores mostrados na tela.

O código também ajusta a posição dos candidatos B e D dependendo da quantidade de dígitos dos votos, para evitar que os números fiquem muito grudados no LCD.

---

## 12. Botão de apuração

O botão de apuração é ligado no pino **D7**.

Quando ele é pressionado, o programa chama a função `exibirVencedor()`.

Essa função calcula o total de votos:

```cpp
int total = votosA + votosB + votosC + votosD;
```

Depois ela verifica três situações:

### 12.1 Nenhum voto registrado

Se o total de votos for zero, o LCD mostra:

```text
Sem votos!
Registre votos
```

Isso evita que o programa tente calcular porcentagens sem nenhum voto.

### 12.2 Empate

Se dois ou mais candidatos tiverem a mesma maior quantidade de votos, o LCD mostra:

```text
EMPATE!
Cands: A B
```

As letras exibidas dependem de quais candidatos empataram.

### 12.3 Vencedor único

Se existir apenas um candidato com mais votos, o LCD mostra o vencedor, a quantidade de votos e a porcentagem:

```text
VENCEDOR: A
3 votos  60%
```

Depois, o programa também mostra uma tela com os votos e porcentagens dos candidatos A e B, outra tela com os candidatos C e D, e por fim o total geral de votos.

---

## 13. Cálculo da porcentagem

A função `calcularPorcentagem()` recebe a quantidade de votos de um candidato e o total de votos.

Ela retorna a porcentagem inteira daquele candidato.

O código também evita divisão por zero:

```cpp
if (total == 0) return 0;
```

A fórmula usada é:

```cpp
(votos * 100 + total / 2) / total
```

Essa fórmula faz um arredondamento melhor da porcentagem, em vez de simplesmente cortar o valor decimal.

---

## 14. Como o código encontra o vencedor

A função `encontrarVencedor()` compara os votos dos quatro candidatos.

Primeiro, ela procura qual é a maior quantidade de votos entre A, B, C e D.

Depois, ela verifica se mais de um candidato tem essa mesma quantidade. Se mais de um candidato tiver o maior valor, o programa considera que houve empate.

Se não houver empate, a função retorna a letra do candidato vencedor.

---

## 15. Explicação resumida para apresentação

Nesta montagem, eu usei um Arduino Uno para controlar uma urna eletrônica simples. O LCD 16x2 com I2C foi ligado nos pinos A4 e A5 do Arduino, usando A4 como SDA e A5 como SCL. A alimentação do LCD vem do 5V e do GND do Arduino.

Os botões foram ligados na protoboard, cada um com um terminal conectado ao pino digital do Arduino e o outro terminal conectado ao GND. Como o código usa `INPUT_PULLUP`, não precisei usar resistores externos. Por causa disso, quando o botão está solto o Arduino lê HIGH, e quando o botão é pressionado ele lê LOW.

Os botões A, B, C e D servem para registrar votos nos candidatos. O botão reset, ligado no pino D6, zera todos os votos. O botão de apuração, ligado no pino D7, mostra o vencedor, os votos, as porcentagens e também identifica empate.

No código, cada candidato tem uma variável própria para contar os votos. Quando um botão é pressionado, o contador daquele candidato aumenta em 1, o LCD mostra a mensagem de voto computado e depois volta para o placar.

Também foi usado debounce por software para evitar que um único aperto seja contado mais de uma vez. Isso é feito com `millis()` e um tempo de estabilidade de 50 ms. Depois que o botão é detectado, o código espera ele ser solto antes de aceitar outro voto.

A apuração soma todos os votos, calcula as porcentagens e verifica se existe um vencedor único ou empate. Se não houver votos, o sistema mostra uma mensagem avisando que nenhum voto foi registrado.

---

## 16. Conclusão

O projeto mostra de forma prática como usar entradas digitais, comunicação I2C, LCD, botões e lógica de programação com Arduino.

A montagem funciona porque os botões enviam sinais para o Arduino, o Arduino processa esses sinais no código, atualiza os contadores de votos e mostra as informações no LCD.

Com isso, o projeto simula uma urna eletrônica básica, com votação, confirmação, reset, apuração, cálculo de porcentagem e verificação de empate.
