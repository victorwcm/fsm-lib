#include "fsm_states.h"
#include "fsm_types.h"
#include "fsm_states_functions.h"
#include "fsm_transition_functions.h"

state fsm[2] = {
  {ON,  on_state_function,  {{on_to_off, OFF},{on_to_on, ON}}, 2},
  {OFF, off_state_function, {{off_to_on, ON}, {off_to_off, OFF}}, 2}
};

