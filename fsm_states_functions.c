#include "fsm_states_functions.h"
#include "fsm_outputs.h"

void on_state_function(void) {
  digitalWrite(LED_PIN, HIGH);
}
void off_state_function(void) {
  digitalWrite(LED_PIN, LOW);
}

