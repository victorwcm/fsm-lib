#ifndef FSM_TYPES_H
#define FSM_TYPES_H

typedef struct state_ state;
typedef struct transition_ transition;
typedef struct input_ input;

typedef enum {ON, OFF} state_name;

struct input_ {
  int input_value;
  int (*update_input_function)(void);
};

struct state_ {
  // state name
  state_name name;
  // state function
  void (*state_function)(void);
  // state transitions
  transition *transitions;
  // total number of transtions
  unsigned int num_transitions;
};

struct transition_ {
  // transition function
  int (*transition_function)(void);
  // next state reference
  state *next_state;
};

#endif

