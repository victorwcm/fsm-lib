#ifndef FSM_INPUTS_H
#define FSM_INPUTS_H

#include "fsm_types.h"

// input pins definition 
#define BUTTON_PIN D5

// defines total number of inputs
#define NUM_INPUTS 1

// all possible input names
typedef enum {btn_pressed} input_name;

extern input inputs[];

// declares one update function for each fsm input
int btn_pressed_update();

extern void setup_inputs(void);
extern void update_inputs(void);

#endif

