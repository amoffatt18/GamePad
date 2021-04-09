// Vipor's Vengeance!
// Andrew Moffatt || 29 Mar 2021
// CRT 360 Advanced Prototyping || GamePad


int curMode = -1;


#include <Metro.h>
#include "frame.h"
#include "screen.h"
#include "tile.h"
#include "controls.h"
#include "interaction.h"
#include "hero.h"
#include "modes.h"


void setup() {
  Serial.begin(9600);
  initScreen();
  initControls();
  initHero();
  initNeighbors();
}

void loop() {
  getControls();
  runMode();
  checkFrame();
  tft.updateScreen();
  //Serial.println (curMode);

}
