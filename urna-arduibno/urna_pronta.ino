// obs: se eu ficar calvo a culpa é sua!
// Projeto: urna eletrônica simples com Arduino

// A ideia aqui é contar votos de 4 candidatos usando botões
// e mostrar tudo em um LCD 16x2 com módulo I2C.

// Ligações que usei:
//
// LCD I2C:
// SDA -> A4
// SCL -> A5
// VCC -> 5V
// GND -> GND
//
// Botões:
// A        -> pino 2
// B        -> pino 3
// C        -> pino 4
// D        -> pino 5
// Reset    -> pino 6
// Apuração -> pino 7
//
// Cada botão fica ligado entre o pino do Arduino e o GND.
// Por isso no código eu uso INPUT_PULLUP, então não precisei
// colocar resistor externo nos botões.

#include <Adafruit_LiquidCrystal.h>

// LCD I2C do Tinkercad
Adafruit_LiquidCrystal lcd(0);

// pinos usados nos botões
const int PINO_A        = 2;
const int PINO_B        = 3;
const int PINO_C        = 4;
const int PINO_D        = 5;
const int PINO_RESET    = 6;
const int PINO_APURACAO = 7;

// tempo usado para evitar que um clique conte mais de uma vez
const unsigned long DEBOUNCE_MS = 50;

// aqui ficam guardados os votos de cada candidato
int votosA = 0;
int votosB = 0;
int votosC = 0;
int votosD = 0;

// variáveis usadas para controlar o debounce de cada botão
unsigned long ultimoTempoA        = 0;
unsigned long ultimoTempoB        = 0;
unsigned long ultimoTempoC        = 0;
unsigned long ultimoTempoD        = 0;
unsigned long ultimoTempoReset    = 0;
unsigned long ultimoTempoApuracao = 0;

// como estou usando INPUT_PULLUP, o botão solto fica HIGH
bool estadoAnteriorA        = HIGH;
bool estadoAnteriorB        = HIGH;
bool estadoAnteriorC        = HIGH;
bool estadoAnteriorD        = HIGH;
bool estadoAnteriorReset    = HIGH;
bool estadoAnteriorApuracao = HIGH;

// protótipos de funções
void atualizarDisplay();
void exibirConfirmacao(char candidato);
void exibirVencedor();
bool botaoPressionado(int pino, bool &estadoAnterior, unsigned long &ultimoTempo);
char encontrarVencedor(int &maiorVotos, bool &empate);
int calcularPorcentagem(int votos, int total);

void setup() {
  // configura todos os botões como entrada com pull-up interno
  pinMode(PINO_A,        INPUT_PULLUP);
  pinMode(PINO_B,        INPUT_PULLUP);
  pinMode(PINO_C,        INPUT_PULLUP);
  pinMode(PINO_D,        INPUT_PULLUP);
  pinMode(PINO_RESET,    INPUT_PULLUP);
  pinMode(PINO_APURACAO, INPUT_PULLUP);

  // inicia o LCD 16x2
  lcd.begin(16, 2);
  lcd.clear();

  // mensagem inicial
  lcd.setCursor(1, 0);
  lcd.print("URNA ELETRONICA");
  lcd.setCursor(2, 1);
  lcd.print("Bem-vindo! :)");
  delay(2500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pressione o voto");
  lcd.setCursor(1, 1);
  lcd.print("A | B | C | D");
  delay(2000);

  atualizarDisplay();
}

void loop() {
  // se apertar o botão A, soma um voto para A
  if (botaoPressionado(PINO_A, estadoAnteriorA, ultimoTempoA)) {
    votosA++;
    exibirConfirmacao('A');
    atualizarDisplay();
  }

  // voto no candidato B
  if (botaoPressionado(PINO_B, estadoAnteriorB, ultimoTempoB)) {
    votosB++;
    exibirConfirmacao('B');
    atualizarDisplay();
  }

  // voto no candidato C
  if (botaoPressionado(PINO_C, estadoAnteriorC, ultimoTempoC)) {
    votosC++;
    exibirConfirmacao('C');
    atualizarDisplay();
  }

  // voto no candidato D
  if (botaoPressionado(PINO_D, estadoAnteriorD, ultimoTempoD)) {
    votosD++;
    exibirConfirmacao('D');
    atualizarDisplay();
  }

  // mostra a apuração, com vencedor ou empate
  if (botaoPressionado(PINO_APURACAO, estadoAnteriorApuracao, ultimoTempoApuracao)) {
    exibirVencedor();
    atualizarDisplay();
  }

  // zera todos os votos
  if (botaoPressionado(PINO_RESET, estadoAnteriorReset, ultimoTempoReset)) {
    votosA = 0;
    votosB = 0;
    votosC = 0;
    votosD = 0;

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("** RESETADO **");
    lcd.setCursor(1, 1);
    lcd.print("Votos zerados!");
    delay(2000);

    atualizarDisplay();
  }
}

// função para ler o botão tentando evitar leitura falsa
// ela retorna true só quando identifica um clique válido
bool botaoPressionado(int pino, bool &estadoAnterior, unsigned long &ultimoTempo) {
  bool leitura = digitalRead(pino);

  // se mudou o estado do botão, reinicia a contagem do tempo
  if (leitura != estadoAnterior) {
    ultimoTempo = millis();
  }

  estadoAnterior = leitura;

  // depois de um pequeno tempo estável, considera o botão pressionado
  if ((millis() - ultimoTempo) >= DEBOUNCE_MS && leitura == LOW) {
    while (digitalRead(pino) == LOW) {
      // espera soltar o botão
    }

    delay(20);
    return true;
  }

  return false;
}

// calcula a porcentagem dos votos
// o if evita erro caso ainda não exista nenhum voto
int calcularPorcentagem(int votos, int total) {
  if (total == 0) {
    return 0;
  }

  return (votos * 100 + total / 2) / total;
}

// procura qual candidato teve mais votos
// se tiver empate, a variável empate fica como true
char encontrarVencedor(int &maiorVotos, bool &empate) {
  int contagens[4] = { votosA, votosB, votosC, votosD };
  char letras[4]   = { 'A', 'B', 'C', 'D' };

  maiorVotos = 0;
  empate = false;
  char vencedor = '?';

  // primeiro procura o maior número de votos
  for (int i = 0; i < 4; i++) {
    if (contagens[i] > maiorVotos) {
      maiorVotos = contagens[i];
      vencedor = letras[i];
    }
  }

  // se ninguém votou, não tem vencedor
  if (maiorVotos == 0) {
    return '?';
  }

  // agora verifica se mais de um candidato chegou nesse mesmo valor
  int qtdComMaximo = 0;

  for (int i = 0; i < 4; i++) {
    if (contagens[i] == maiorVotos) {
      qtdComMaximo++;
    }
  }

  if (qtdComMaximo > 1) {
    empate = true;
    vencedor = '?';
  }

  return vencedor;
}

// mostra o resultado da votação no LCD
void exibirVencedor() {
  int total = votosA + votosB + votosC + votosD;

  // caso aperte apuração sem ter nenhum voto
  if (total == 0) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Sem votos!");
    lcd.setCursor(1, 1);
    lcd.print("Registre votos");
    delay(3000);
    return;
  }

  int maiorVotos;
  bool empate;
  char vencedor = encontrarVencedor(maiorVotos, empate);

  // se tiver empate, mostra quais candidatos empataram
  if (empate) {
    int contagens[4] = { votosA, votosB, votosC, votosD };
    char letras[4]   = { 'A', 'B', 'C', 'D' };

    String empatados = "";

    for (int i = 0; i < 4; i++) {
      if (contagens[i] == maiorVotos) {
        if (empatados.length() > 0) {
          empatados += " ";
        }

        empatados += letras[i];
      }
    }

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("EMPATE!");
    lcd.setCursor(0, 1);
    lcd.print("Cands: ");
    lcd.print(empatados);
    delay(5000);
    return;
  }

  // se não teve empate, mostra o vencedor e a porcentagem dele
  int pctVencedor = calcularPorcentagem(maiorVotos, total);

  char linha1[17];
  snprintf(linha1, sizeof(linha1), "%d votos  %d%%", maiorVotos, pctVencedor);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("VENCEDOR: ");
  lcd.print(vencedor);
  lcd.setCursor(0, 1);
  lcd.print(linha1);
  delay(5000);

  // mostra os detalhes dos candidatos A e B
  int pctA = calcularPorcentagem(votosA, total);
  int pctB = calcularPorcentagem(votosB, total);

  char telaA[17];
  char telaB[17];

  snprintf(telaA, sizeof(telaA), "A: %2dvt  %3d%%", votosA, pctA);
  snprintf(telaB, sizeof(telaB), "B: %2dvt  %3d%%", votosB, pctB);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(telaA);
  lcd.setCursor(0, 1);
  lcd.print(telaB);
  delay(3000);

  // depois mostra C e D
  int pctC = calcularPorcentagem(votosC, total);
  int pctD = calcularPorcentagem(votosD, total);

  char telaC[17];
  char telaD[17];

  snprintf(telaC, sizeof(telaC), "C: %2dvt  %3d%%", votosC, pctC);
  snprintf(telaD, sizeof(telaD), "D: %2dvt  %3d%%", votosD, pctD);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(telaC);
  lcd.setCursor(0, 1);
  lcd.print(telaD);
  delay(3000);

  // por último mostra o total geral de votos
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Total de votos:");
  lcd.setCursor(5, 1);
  lcd.print(total);
  delay(3000);
}

// atualiza a tela principal com a quantidade de votos
void atualizarDisplay() {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("A:");
  lcd.print(votosA);

  int posB = (votosA < 10) ? 5 : 6;
  lcd.setCursor(posB, 0);
  lcd.print("B:");
  lcd.print(votosB);

  lcd.setCursor(0, 1);
  lcd.print("C:");
  lcd.print(votosC);

  int posD = (votosC < 10) ? 5 : 6;
  lcd.setCursor(posD, 1);
  lcd.print("D:");
  lcd.print(votosD);
}

// mensagem que aparece depois que alguém vota
void exibirConfirmacao(char candidato) {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Voto computado!");
  lcd.setCursor(5, 1);
  lcd.print("Cand. ");
  lcd.print(candidato);
  delay(1000);
}
