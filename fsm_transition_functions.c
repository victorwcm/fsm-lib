#include "fsm_transition_functions.h"
#include "fsm_types.h"
#include "fsm_inputs.h"

int on_to_off() {
  return inputs[btn_pressed].input_value;
}

int on_to_on() {
  return !inputs[btn_pressed].input_value;
}

int off_to_on() {
  return inputs[btn_pressed].input_value;
}

int off_to_off() {
  return !inputs[btn_pressed].input_value;
}

// definition of the next state computation function
state* compute_next_state(state *current_state) {
  state *next_state;
  for(int i = 0; i < current_state->num_transitions; i++) {
    if(current_state->transitions[i].transition_function()) {
      next_state = current_state->transitions[i].next_state;
      break;
    }
  }
  return next_state;
}

