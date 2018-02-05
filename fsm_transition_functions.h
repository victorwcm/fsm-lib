#ifndef FSM_TRANSITION_FUNTIONS_H
#define FSM_TRANSITION_FUNTIONS_H

#include "fsm_types.h"

int on_to_off(void);
int on_to_on(void);
int off_to_on(void);
int off_to_off(void);

extern state* compute_next_state(state *current_state);

#endif

