boolean initIntro = false;
boolean level1 = false;
boolean level2 = false;
boolean level3 = false;
boolean level4 = false;
boolean level5 = false;
boolean level6 = false;


void introScreen () {

  if (initIntro == false) {
    tft.setClipRect(0, 0, screenW, screenH);
    tft.fillScreen(ILI9341_BLACK);
    tft.updateScreen();
    initIntro = true;
    //Serial.println ("loading intro");
  }
  if (buttonBuffer[0] == 1) {
    //Serial.println(buttonBuffer[1]);
    curMode = 0;
  }
}

void firstLevel () {

  if (level1 == false) {
    tft.setClipRect (0, 0, screenW, screenH);
    drawLevel(0);
    tft.updateScreen();
    level1 = true;
    Serial.println ("loading level 1");
  }
  drawLevel(0);
  drawHero();

  if (buttonBuffer[1] == 1) {
    curMode = 1;
  }
}

void secondLevel () {

  if (level2 == false) {
    tft.setClipRect (0, 0, screenW, screenH);
    drawLevel(1);
    tft.updateScreen();
    level2 = true;
    Serial.println ("loading level 2");
  }
  drawLevel(1);
  drawHero();

  if (buttonBuffer[0] == 1) {
    curMode = 2;
  }
}

void thirdLevel () {

  if (level3 == false) {
    tft.setClipRect (0, 0, screenW, screenH);
    drawLevel(2);
    tft.updateScreen();
    level3 = true;
    Serial.println ("loading level 3");
  }
  drawLevel(2);
  drawHero();

  if (buttonBuffer[1] == 1) {
    curMode = 3;
  }
}

void fourthLevel () {
  if (level4 == false) {
    tft.setClipRect (0, 0, screenW, screenH);
    drawLevel(3);
    tft.updateScreen();
    level4 = true;
  }
  drawLevel(3);
  drawHero();

  if (buttonBuffer[0] == 1) {
    curMode = 4;
  }
}

void fifthLevel () {
  if (level5 == false) {
    tft.setClipRect (0, 0, screenW, screenH);
    drawLevel(4);
    tft.updateScreen();
    level5 = true;
  }
  drawLevel(4);
  drawHero();

  if (buttonBuffer[1] == 1) {
    curMode = 5;
  }
}

void bossLevel () {
  if (level6 == false) {
    tft.setClipRect (0, 0, screenW, screenH);
    drawLevel(5);
    tft.updateScreen();
    level6 = true;
  }
  drawLevel(5);
  drawHero();

  if (buttonBuffer[0] == 1) {
    curMode = 0;
  }
}

void runMode() {

  switch (curMode) {
    case -1: introScreen(); break;
    case 0: firstLevel(); break;
    case 1: secondLevel(); break;
    case 2: thirdLevel(); break;
    case 3: fourthLevel(); break;
    case 4: fifthLevel(); break;
    case 5: bossLevel(); break;

  }
}
