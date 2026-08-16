# 🍄 Mario Bros Theme - Arduino Duet

Este projeto executa a clássica melodia do jogo **Super Mario Bros** utilizando dois buzzers no Arduino para criar um efeito de dueto (melodia principal + baixo/harmonia), acompanhado por efeitos visuais em um LED RGB.

---

## 🛠️ Componentes Necessários

* 1x Arduino (Uno, Nano ou equivalente)
* 2x Buzzers Passivos (Pinos 7 e 8)
* 1x LED RGB (Pinos 9, 10 e 12)
* Resistores adequados para o LED RGB
* Protoboard e Jumpers

---

## 📌 Esquemático de Conexões

| Componente | Pino do Arduino | Função |
| :--- | :--- | :--- |
| **Buzzer 1** | Pino 8 | Melodia Principal |
| **Buzzer 2** | Pino 7 | Acompanhamento / Baixo |
| **LED Vermelho** | Pino 12 | Visualizador |
| **LED Verde** | Pino 10 | Visualizador |
| **LED Azul** | Pino 9 | Visualizador |

---

## 💻 Estrutura do Código

O projeto foi desenvolvido no **VS Code** utilizando a extensão **PlatformIO**. 

* **`src/main.cpp`**: Contém a estrutura de matrizes das notas musicais, o controle dos tempos e a função de chaveamento manual (`delayMicroseconds`) para permitir o som paralelo no segundo buzzer sem travar a sincronia.

---

## 🚀 Como Executar

1. Abra a pasta do projeto no **VS Code** com a extensão **PlatformIO** instalada.
2. Conecte o seu Arduino na porta USB.
3. Clique em **Upload** ($\rightarrow$) na barra inferior do PlatformIO para compilar e gravar na placa.
