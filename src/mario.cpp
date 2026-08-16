#include <Arduino.h>

// --- DECLARAÇÃO DE PROTÓTIPOS DE FUNÇÕES (Obrigatório em C++ no VS Code) ---
void tocarBuzzer2Manual(int pino, int frequencia, int duracaoMs);
void tocarMarioDuetoCompleto();

// Definição dos pinos
const int pinoBuzzer1  = 8; // Melodia Principal (usa tone() nativo)
const int pinoBuzzer2  = 7; // Acompanhamento/Baixo (usa função manual)

const int pinoVermelho = 12; 
const int pinoVerde    = 10; 
const int pinoAzul     = 9;  

const int brilhoMisto  = 35; 

// NOTAS DA MELODIA COMPLETA (Buzzer 1)
const int melodia[] = {
  // --- PARTE 1: INTRODUÇÃO ---
  659, 659, 0, 659, 0, 523, 659, 0, 784, 0, 0, 0, 392, 0, 0, 0,
  // --- PARTE 2: ESTROFE PRINCIPAL ---
  523, 0, 0, 392, 0, 0, 330, 0, 0, 440, 0, 494, 0, 466, 440, 0,
  392, 659, 784, 880, 0, 698, 784, 0, 659, 0, 523, 587, 494, 0, 0,
  523, 0, 0, 392, 0, 0, 330, 0, 0, 440, 0, 494, 0, 466, 440, 0,
  392, 659, 784, 880, 0, 698, 784, 0, 659, 0, 523, 587, 494, 0, 0,
  // --- PARTE 3: O SUBSOLO (CORRIDA) ---
  0, 784, 740, 698, 622, 0, 659, 0, 440, 494, 523, 0, 440, 494, 523, 0,
  0, 784, 740, 698, 622, 0, 659, 0, 988, 0, 988, 988, 0, 0, 0, 0,
  0, 784, 740, 698, 622, 0, 659, 0, 440, 494, 523, 0, 440, 494, 523, 0,
  0, 622, 0, 0, 587, 0, 0, 523, 0, 0, 0, 0, 0, 0, 0, 0
};

// NOTAS DA HARMONIA COMPLETA (Buzzer 2)
const int harmonia[] = {
  // --- PARTE 1: INTRODUÇÃO ---
  330, 330, 0, 330, 0, 262, 330, 0, 392, 0, 0, 0, 196, 0, 0, 0,
  // --- PARTE 2: ESTROFE PRINCIPAL ---
  262, 0, 0, 196, 0, 0, 165, 0, 0, 220, 0, 247, 0, 233, 220, 0,
  196, 330, 392, 440, 0, 349, 392, 0, 330, 0, 262, 294, 247, 0, 0,
  262, 0, 0, 196, 0, 0, 165, 0, 0, 220, 0, 247, 0, 233, 220, 0,
  196, 330, 392, 440, 0, 349, 392, 0, 330, 0, 262, 294, 247, 0, 0,
  // --- PARTE 3: O SUBSOLO (CORRIDA) ---
  0, 392, 370, 349, 311, 0, 330, 0, 220, 247, 262, 0, 220, 247, 262, 0,
  0, 392, 370, 349, 311, 0, 330, 0, 494, 0, 494, 494, 0, 0, 0, 0,
  0, 392, 370, 349, 311, 0, 330, 0, 220, 247, 262, 0, 220, 247, 262, 0,
  0, 311, 0, 0, 294, 0, 0, 262, 0, 0, 0, 0, 0, 0, 0, 0
};

const int tempos[] = {
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140,
  140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140, 140
};

void setup() {
  pinMode(pinoBuzzer1, OUTPUT);
  pinMode(pinoBuzzer2, OUTPUT);
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAzul, OUTPUT);

  tocarMarioDuetoCompleto();
}

void loop() {
  digitalWrite(pinoVermelho, LOW);
  analogWrite(pinoVerde, 0);
  analogWrite(pinoAzul, 0);
}

// --- FUNÇÃO MANUAL PARA O BUZZER 2 ---
void tocarBuzzer2Manual(int pino, int frequencia, int duracaoMs) {
  if (frequencia == 0) {
    delay(duracaoMs);
    return;
  }
  
  long periodoMicros = 1000000L / frequencia;
  long tempoFim = millis() + duracaoMs;
  
  while (millis() < tempoFim) {
    digitalWrite(pino, HIGH);
    delayMicroseconds(periodoMicros / 2);
    digitalWrite(pino, LOW);
    delayMicroseconds(periodoMicros / 2);
  }
}

void tocarMarioDuetoCompleto() {
  int totalNotas = sizeof(melodia) / sizeof(melodia[0]);

  for (int i = 0; i < totalNotas; i++) {
    int duracao = tempos[i];

    if (melodia[i] != 0 || harmonia[i] != 0) {
      // 1. Toca o Buzzer 1 (Melodia) se houver nota
      if (melodia[i] != 0) {
        tone(pinoBuzzer1, melodia[i], duracao);
      }
      
      // 2. Controla os LEDs
      if (i % 3 == 0) {
        digitalWrite(pinoVermelho, HIGH);
      } else if (i % 3 == 1) {
        analogWrite(pinoVerde, brilhoMisto);
      } else {
        analogWrite(pinoAzul, brilhoMisto);
      }
      
      // 3. Toca o Buzzer 2 (Baixo/Harmonia)
      tocarBuzzer2Manual(pinoBuzzer2, harmonia[i], duracao);
      
    } else {
      // Pausa total
      noTone(pinoBuzzer1);
      digitalWrite(pinoBuzzer2, LOW);
      
      digitalWrite(pinoVermelho, LOW);
      analogWrite(pinoVerde, 0);
      analogWrite(pinoAzul, 0);
      delay(duracao);
    }

    // Limpeza de sinal entre notas
    noTone(pinoBuzzer1);
    digitalWrite(pinoBuzzer2, LOW);
    digitalWrite(pinoVermelho, LOW);
    analogWrite(pinoVerde, 0);
    analogWrite(pinoAzul, 0);
    delay(18);
  }
}