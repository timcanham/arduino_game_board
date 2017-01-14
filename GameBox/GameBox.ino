// Map I/Os to enumerations

typedef enum IoList {
  RESET_BUTTON = 0,
  PLAYER_1_BUTTON = 1,
  PLAYER_2_BUTTON = 2,
  PLAYER_3_BUTTON = 3,
  PLAYER_4_BUTTON = 4,
  RESET_LED = 5,
  PLAYER_1_LED = 6,
  PLAYER_2_LED = 7,
  PLAYER_3_LED = 8,
  PLAYER_4_LED = 9,
  TOGGLE = 13 
};

// Define state machine for button/LED states

enum {
  WAITING, // Waiting for player to hit button
  SELECTED // Selected and waiting for clear button
} gameState;

int toggle = 0;

// clear all LEDs to waiting state
void clearLeds() {

  // Turn off LEDs
  for (int led = RESET_LED; led <= PLAYER_4_LED; led++) {
    digitalWrite(led, LOW);
  }

  // start with RESET LED on
  digitalWrite(RESET_LED, HIGH);

  // set game state as reset
  gameState = WAITING;
  
}

void setup() {

  // All buttons should be input pull-ups
  for (int button = RESET_BUTTON; button <= PLAYER_4_BUTTON; button++) {
    pinMode(button, INPUT_PULLUP);
  }

  for (int led = RESET_LED; led <= PLAYER_4_LED; led++) {
    pinMode(led, OUTPUT);
  }

  // set LEDs to waiting state
  clearLeds();

}

void loop() {

  // switch on game state
  switch (gameState) {
    case WAITING:
      // scan the player button presses for the first
      for (int button = PLAYER_1_BUTTON; button <= PLAYER_4_BUTTON; button++) {
        int buttonState = digitalRead(button);
        int led;
        // because switch closes to ground for pull-up input, button push is zero
        if (LOW == buttonState) {
          switch (button) {
            case PLAYER_1_BUTTON:
              led = PLAYER_1_LED;
              break;
            case PLAYER_2_BUTTON:
              led = PLAYER_2_LED;
              break;
            case PLAYER_3_BUTTON:
              led = PLAYER_3_LED;
              break;
            case PLAYER_4_BUTTON:
              led = PLAYER_4_LED;
              break;
          }
          // turn on player's LED
          digitalWrite(led,HIGH);
          // turn off reset LED
          digitalWrite(RESET_LED,LOW);
          // switch state
          gameState = SELECTED;
        }
      }
      break;
    case SELECTED: {
      // check reset input
      if (digitalRead(RESET_BUTTON) ==  LOW) {
        // clear other LEDs and set state back to WAITING
        clearLeds();
        gameState = WAITING;
      }
    }
  }

  // toggle output - see how fast it runs
  toggle = 1 - toggle;
  if (0 == toggle) {
    digitalWrite(TOGGLE,LOW);
  } else {
    digitalWrite(TOGGLE,HIGH);
  }
}
