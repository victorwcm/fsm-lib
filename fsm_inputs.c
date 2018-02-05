#include "fsm_inputs.h"
#include <Arduino.h>

// inputs declaration -> name, update_function
input inputs[] = {
  {btn_pressed, btn_pressed_update}
};

// auxiliar variables
int button_state = LOW;                // armazena a leitura atual do botao
int last_button_state = LOW;            // armazena a leitura anterior do botao
unsigned long last_debounce_time = 0;   // armazena a ultima vez que a leitura da entrada variou
const unsigned long debounce_delay = 50;     // tempo utilizado para implementar o debounce

// update functions implementation
int btn_pressed_update() {  
  int reading = digitalRead(BUTTON_PIN);
  if (reading != last_button_state) {
    last_debounce_time = millis();
  }
  
  last_button_state = reading;
  
  if ((millis() - last_debounce_time) > debounce_delay) {
    if (reading != button_state) {
      button_state = reading;
      if (button_state == HIGH) {
        return true;
      }
    }
  }
  return false; 
}

void setup_inputs() {
  pinMode(BUTTON_PIN, INPUT);
}

void update_inputs() {
  for(int i = 0; i < NUM_INPUTS; i++) {
    inputs[i].input_value = inputs[i].update_input_function();
  }
}

