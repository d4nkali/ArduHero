/*

  Programa Guitarra para o Clone Hero no PC usando Arduino Pro Mini
  Autor: d4nkali
  Data: 18/11/2023

*/

// Inclusão da biblioteca

  #include <Keyboard.h>

//Definição das variaveis

 // Pinos utilizados pelos botões

   const int botao_pin[] = {15, 14, 16, 10, 9, 8, 7, 6};

 // Teclas correspondentes aos botões

   const char teclas[] = {'A', 'S', 'J', 'K', 'L', KEY_RETURN, KEY_DOWN_ARROW, KEY_UP_ARROW};

 // Número de botões

   const int num_botao = sizeof(botao_pin) / sizeof(botao_pin[0]);

 // Estado dos botões

   bool buttonStates[num_botao] = {false};

void setup() { // Progrmação inicial

  Keyboard.begin();   // Inicializar a comunicação da placa com o computador

  for (int i = 0; i < num_botao; i++) { // Configura os botões como entradas

    pinMode(botao_pin[i], INPUT_PULLUP);

  }

}

void loop() { // Programação principal

  for (int i = 0; i < num_botao; i++) { // Ler o estado de cada botão

    bool buttonPressed = digitalRead(botao_pin[i]) == LOW;

    if (buttonPressed && !buttonStates[i]) { // Se o botão foi pressionado, então:

      Keyboard.press(teclas[i]); // Pressionar a tecla correspondente
      buttonStates[i] = true;

    }

    else if (!buttonPressed && buttonStates[i]) { // Se o botão foi solto, então:

      Keyboard.release(teclas[i]); // Liberar a tecla correspondente
      buttonStates[i] = false;

    }

  }

  delay(10); // Aguardar um curto período antes de ler novamente o estado dos botões

}

// FIM!