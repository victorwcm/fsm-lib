#include "fsm_types.h"
#include "fsm_states.h"
#include "fsm_states_functions.h"
#include "fsm_transition_functions.h"
#include "fsm_inputs.h"
#include "fsm_outputs.h"

// current state variable
state *current_state = &fsm[ENTRY_STATE];

void setup() {
  setup_inputs();
  setup_outputs();
}

void loop() {
  // run current state funtion
  current_state->state_function();
  // update inputs
  update_inputs();
  // computes next state
  current_state = compute_next_state(current_state);
  // exit state if necessary
//  if (END_STATE == current_state)
//    return;
}

