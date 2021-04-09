#include <Metro.h>
#include "characters_MASK.h"
#include "characters_PIX.h"

int heroFrame;
int heroW;
int heroH;
int curTile;
int curTileX;
int curTileY;

float heroX;
float heroY;
float heroSpeed;

boolean isLevelDrawn;
boolean heroDir;

Metro heroFrameTimer = Metro(250);

void initHero () {
  heroX = (screenW / 2) - 12;
  heroY = (screenH / 2) - 12;
  heroSpeed = 0.5;

  isLevelDrawn = false;
  heroDir = true;

  heroFrame = 0;
  heroW = 32;
  heroH = 32;
}


void drawHero () {
  
  float nextX = heroX + (float (joystickBuffer[0]) * heroSpeed);
  float nextY = heroY + (float (joystickBuffer[1]) * heroSpeed);

//  curTileX = heroX / tileSize;
//  curTileY = heroY / tileSize;
//  curTile = curTileX + curTileY * tileW;

if (checkMove(curMode, nextX, nextY, heroW, heroH) == true) {
  heroX = nextX;
  heroY = nextY;
}

//if ((heroX + 32) > 315) {
//  heroX = 315 - 32;
//} else if (heroX < 20) {
//  heroX = 20;
//}
//if ((heroY + 32) > 210) {
//  heroY = 210 - 32;
//} else if (heroY < 20) {
//  heroY = 20;
//}


if (joystickBuffer [0] == 1) {
  heroDir = true;
} else if (joystickBuffer [0] == -1) {
  heroDir = false;
}

if (joystickBuffer [1] == 0 && heroDir == true) {
  heroFrame = 0;
}
if (joystickBuffer [1] == 0 && heroDir == false) {
  heroFrame = 4;
}
if (joystickBuffer[1] == 1 && heroDir == true) {
  if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 2;
      heroFrame = heroFrame + 1;
    }
  }
  if (joystickBuffer[1] == -1 && heroDir == false) {
  if (heroFrameTimer.check()) {
      heroFrame = (heroFrame + 1) % 6;
      if (heroFrame < 4) {
        heroFrame = 4;
      }
    }
  }

  tft.setClipRect(heroX - 5, heroY - 5, 38, 38);
  tft.drawRGBBitmap (heroX, heroY, characters_PIX[heroFrame], characters_MASK[heroFrame], heroW, heroH);
  tft.updateScreen();
}
