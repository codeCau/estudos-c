16-05-2026 22:18

Status:

Tags: [[Arquitetura]] | [[Software]] | [[C++ Linguagem]] |  [[Funções]] | [[C Linguagem]] | [[Sistemas embarcados]]

---
# 📖Implementação de LED's de confirmação
### O que foi adicionado e por quê

#### Novas constantes de pino

```C
const int LED_VERDE    = 8;
const int LED_AMARELO  = 9;
const int LED_VERMELHO = 10;
```

Três constantes para os pinos dos LEDs, igual ao padrão que já estava sendo usado para os botões. Facilita trocar o pino depois sem precisar caçar o número espalhado pelo código.

#### No `setup()` — três coisas novas

```C
pinMode(LED_VERDE,    OUTPUT);
pinMode(LED_AMARELO,  OUTPUT);
pinMode(LED_VERMELHO, OUTPUT);
todosLedsApagados();

digitalWrite(LED_VERDE,    HIGH);
digitalWrite(LED_AMARELO,  HIGH);
digitalWrite(LED_VERMELHO, HIGH);
delay(400);
todosLedsApagados();
```

Primeiro configura os pinos como saída e apaga tudo. Depois faz um "teste de inicialização": os três acendem juntos por 400 ms e apagam. Serve tanto para confirmar que estão ligados corretamente quanto para dar um visual de "sistema ligando".

#### Função `todosLedsApagados()`

```C
void todosLedsApagados() {
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERMELHO, LOW);
}
```

Evita repetir três `digitalWrite LOW` toda vez que precisar zerar os LEDs. Sem ela, qualquer lugar que precisasse apagar tudo viraria três linhas repetidas.

#### Função `piscarLed(pino, vezes, ms)`

```C
void piscarLed(int pino, int vezes, int ms) {
  for (int i = 0; i < vezes; i++) {
    digitalWrite(pino, HIGH);
    delay(ms);
    digitalWrite(pino, LOW);
    if (i < vezes - 1) delay(ms);
  }
}
```

Recebe qual LED, quantas vezes piscar e o intervalo em milissegundos. O `if (i < vezes - 1)` evita uma pausa extra depois da última piscada, o que tornaria a resposta do sistema mais lenta do que precisa.
#### Nas funções existentes — onde cada LED entra

| Situação             | LED      | Comportamento                                                |
| -------------------- | -------- | ------------------------------------------------------------ |
| Voto registrado      | Verde    | Acende em `exibirConfirmacao()`, apaga quando a mensagem sai |
| Reset                | Vermelho | Pisca 3× antes da mensagem de reset                          |
| Apuração (sem votos) | Amarelo  | Pisca 2× rápido                                              |
| Apuração em curso    | Amarelo  | Fica aceso do início até o fim de todas as telas             |
| Vencedor encontrado  | Verde    | Pisca 3× ao final da sequência de apuração                   |
| Empate               | Vermelho | Pisca 3× ao final                                            |

#### Ligação física no Tinkercad

Cada LED precisa de um **resistor de 220Ω** em série para não queimar. A ligação é:

```C
Pino Arduino → Resistor 220Ω → Anodo do LED (+) → Catodo do LED (−) → GND
```

No Tinkercad basta arrastar um LED e um resistor para a protoboard, ligar o resistor ao pino do Arduino e o catodo do LED ao trilho GND.


---
# ❌Erros corrigidos
Problema encontrado:

O LCD I2C não estava iniciando corretamente no Tinkercad. A ligação dos fios estava certa, mas a biblioteca usada no código não era a mais adequada para o LCD I2C do simulador.

O código estava usando:

```C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);
```

E a inicialização estava assim:

```C
lcd.init();
lcd.backlight();
```

Para corrigir, troquei a biblioteca do LCD para a biblioteca usada pelo Tinkercad:

```C
#include <Adafruit_LiquidCrystal.h>
```

Depois, troquei a criação do LCD para:

```C
Adafruit_LiquidCrystal lcd(0);
```

Também mudei a inicialização dentro do setup. Em vez de usar:

```C
lcd.init();
lcd.backlight();
```
passei a usar:

```C
lcd.begin(16, 2);
```

Isso fez o LCD ser iniciado corretamente como um display de 16 colunas e 2 linhas.

As ligações continuaram as mesmas:

> SDA -> A4
> SCL -> A5
> VCC -> 5V
> GND -> GND

Conclusão:

O erro não estava na lógica da urna nem nos botões. O problema estava na forma como o LCD era inicializado no Tinkercad. A solução foi adaptar a biblioteca e o comando de inicialização do display.