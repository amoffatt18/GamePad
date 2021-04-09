#include <Metro.h>
#include <Bounce2.h>

Metro controlRate = Metro(30);

int buttonBounce = 10;
int buttonPins[4] = {0, 1, 2, 3};
int buttonBuffer[4] = {0, 0, 0, 0};

int joystickPins[2] = {A0, A1};
int joystickBuffer[2] = {0, 0};

Bounce * buttons = new Bounce[4];

void initControls () {

  for (int i = 0; i < 4; i++) {
    buttons[i].attach(buttonPins[i], INPUT_PULLUP);
    buttons[i].interval(buttonBounce);
  }
}

void getControls () {

  if (controlRate.check()) {
    //Serial.println ("ln");
    for (int i = 0; i < 4; i++) {
      buttons[i].update();
      if (buttons[i].rose()) {
        Serial.println ("pressed");
        buttonBuffer[i] = 0;
      }
      if (buttons[i].fell()) {
        buttonBuffer[i] = 1;
        Serial.println ("not pressed");
      }
    }
    for (int i = 0; i < 2; i++) {
      joystickBuffer[i] = analogRead(joystickPins[i]);
      //Serial.println(joystickBuffer[i]);
    }
    if (joystickBuffer [0] > 700) {
      joystickBuffer[0] = -1;
    } else if (joystickBuffer[0] < 300) {
      joystickBuffer[0] = 1;
    } else {
      joystickBuffer[0] = 0;
    }
    if (joystickBuffer[1] > 700) {
      joystickBuffer[1] = 1;
    } else if (joystickBuffer[1] < 300) {
      joystickBuffer[1] = -1;
    } else {
      joystickBuffer[1] = 0;
    }
  }
}
